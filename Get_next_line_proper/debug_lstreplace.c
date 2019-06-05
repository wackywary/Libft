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

int	ft_find_zero(char *string)
{
	int i;

	i = 0;
	while (string[i])
		i++;
	return (i);
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

size_t	get_line_size(t_list *chunks)
{
	size_t	line_size;

	line_size = 0;
	while (*(char*)(chunks->content + line_size) != '\n' && *(char*)(chunks->content + line_size))
			line_size++;
	return (line_size);
}

void	lstreplace(t_list *lst, size_t line_size)
{
	size_t	k;
	char	*newchunk;
	size_t	newsize;

	k = 0;
	printf("input:\n**%s**\n", (char*)lst->content);
	newchunk = ft_strsub((char*)lst->content, line_size + 1, lst->content_size - line_size);
	printf("strsub res:\n**%s**\n", newchunk);
	printf("strsub length: %zu\n", ft_strlen(newchunk));
	newsize = ft_strlen(newchunk);
	ft_memdel(&lst->content);
	lst->content = ft_memalloc(newsize + 1);
	while (k < newsize)
	{
		*((char*)lst->content + k) = *(newchunk + k);
		printf("content: %c\n", *((char*)lst->content + k));
		printf("newchunk: %c\n", *((char*)lst->content + k));
		k++;
	}
	lst->content_size = newsize;
	ft_strdel(&newchunk);
}

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
		substr = ft_strsub((char*)chunks->content, 0 ,line_size + 1);
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
	char	text_b[] = "123\n12\n123\n1234\n12345\n123456\n1234567\n12345678\n123456789\n\0";
	char	buf[BUFF_SIZE + 1];
	t_list	*chunks;
	int	text_len_b;
	int	b_fd;

	b = "Blain";
	text_len_b = ft_strlen(text_b);
	b_fd = open(b, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	write(b_fd, text_b, text_len_b);
	close(b_fd);
	b_fd = open(b, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	chunks = chunk_list(b_fd, buf);
	lstreplace(chunks, 2);
	chunks = chunks->next;
}
