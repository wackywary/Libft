#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include "get_next_line.h"

void	ft_lstaddtoend(t_list *alst, t_list *new)
{
	while (alst->next)
		alst = alst->next;
	alst->next = new;
}

t_list *chunk_list(int fd, char *buf)
{
	long	bytes;
	t_list	*chunk_new;
	t_list	*chunk_fst;
	
	if ((bytes = read(fd, buf, BUFF_SIZE)) < 0 || fd < 0)
		return (NULL);
	buf[bytes] = '\0';
	chunk_fst = ft_lstnew(buf, bytes);
	while ((bytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[bytes] = '\0';
		chunk_new = ft_lstnew(buf, bytes);
		ft_lstaddtoend(chunk_fst, chunk_new);		
	}
	return (chunk_fst);
}

void	lstreplace(t_list *lst, size_t line_size)
{
	size_t	k;
	char	*newchunk;
	size_t	newsize;

	k = 0;
	newchunk = ft_strsub((char*)lst->content, line_size + 1, lst->content_size - line_size);
	newsize = ft_strlen(newchunk);
	ft_memdel(&lst->content);
	lst->content = ft_memalloc(newsize + 1);
	while (k < newsize)
	{
		*((char*)lst->content + k) = *(newchunk + k);
		k++;
	}
	lst->content_size = newsize;
	ft_strdel(&newchunk);
}
/*
void	lstreplace(t_list *lst, size_t line_size)
{
	size_t	k;
	char	*newchunk;
	size_t	newsize;

	k = 0;
	newchunk = ft_strsub((char*)lst->content, line_size + 1, lst->content_size - line_size - 1);
	newchunk[lst->content_size - line_size - 1] = '\0';
	newsize = ft_strlen(newchunk);
	ft_memdel(&lst->content);
	lst->content = ft_memalloc(newsize);
	while (k < newsize)
	{
		*((char*)lst->content + k) = *(newchunk + k);
		k++;
	}
	*((char*)lst->content) = *(newchunk);
	*((char*)lst->content + k) = '\0';
	lst->content_size = newsize;
	ft_strdel(&newchunk);
}
*/
size_t	get_line_size(t_list *chunks)
{
	size_t	line_size;

	line_size = 0;
	while (*(char*)(chunks->content + line_size) != '\n' && *(char*)(chunks->content + line_size))
			line_size++;
	return (line_size);
}
/*
int	get_next_line(const int fd, char **line)
{
	static t_list	*chunks;
	t_list		*i;
	size_t		line_size;
	char		buf[BUFF_SIZE + 1];
	char		*substr;
	
	if ((i = chunk_list(fd, buf)))
		chunks = i;
	if (BUFF_SIZE <= 0 || fd < 0 || line == NULL) 
		return (-1);
	if (chunks == NULL)
		return (0);
	*line = "";
	while (chunks)
	{
		line_size = get_line_size(chunks);
		substr = ft_strsub((char*)chunks->content, 0 ,line_size);
		*line = ft_strjoin(*line, substr);
		ft_strdel(&substr);
		if (*(char*)(chunks->content + line_size) == '\n')
		{
			lstreplace(chunks, line_size);
			break;
		}
		free(chunks);
		chunks = chunks->next;
	}
	close(fd);
	return (1);
}
*/
int	get_next_line(const int fd, char **line)
{
	static t_list	*chunks;
	t_list		*i;
	size_t		line_size;
	char		buf[BUFF_SIZE + 1];
	char		*substr;
	
	if ((i = chunk_list(fd, buf)))
		chunks = i;
	if (BUFF_SIZE <= 0 || fd < 0 || line == NULL) 
		return (-1);
	if (chunks == NULL)
		return (0);
	*line = "";
	while (chunks)
	{
		line_size = get_line_size(chunks);
		substr = ft_strsub((char*)chunks->content, 0 ,line_size);
		if (ft_strlen(substr))
		*line = ft_strjoin(*line, substr);
		ft_strdel(&substr);
		if (*(char*)(chunks->content + line_size) == '\n')
		{
			lstreplace(chunks, line_size);
			break;
		}
		free(chunks);
		chunks = chunks->next;
	}
	close(fd);
	return (1);
}


int	main()
{
	char	*b;
//	char	*a;
	char	*line;
//	char	buf[BUFF_SIZE];
//	char	text_b[] = "1\n";
	char	text_b[] = "\n\n1\n12\n123\n1234\n12345\n123456\n1234567\n12345678\n123456789\n\0";
//	char	*text_a;
//	int	text_len_a;
	int	text_len_b;
	int	b_fd;
//	int	a_fd;
	int	i;

	i = 0;
	b = "Blain";
//	a = "Alain";
//	text_a = "\nab\nabc\nabcd\nabcde\nabcdef\nabcdefg\nabcdefgh\nabcdefghi";
//	text_b = "1\n12\n123\n1234\n12345\n123456\n1234567\n12345678\n123456789\n";
//	text_len_a = ft_strlen(text_a);
	text_len_b = ft_strlen(text_b);
	b_fd = open(b, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	write(b_fd, text_b, text_len_b);
	close(b_fd);
//	a_fd = open(a, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
//	write(b_fd, text_a, text_len_a);
//	close(a_fd);
	b_fd = open(b, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
//	a_fd = open(a, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
//	printf("read: %ld\n", read(b_fd, buf, BUFF_SIZE));
	while (i < 20)
	{
		printf("out:%d\n", get_next_line(b_fd, &line));
//		printf("out:%d\n", get_next_line(a_fd, &line));
		printf("line: %s\n", line);
		i++;
	}
}
