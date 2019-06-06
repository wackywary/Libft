#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include "get_next_line.h"

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

char	*ft_strsub_0(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	j;

	i = -1;
	j = 0;
	sub = ft_strnew(len + 1);
	while (++i != start)
		;
	while (j < len)
	{
		*(sub + j) = *(s + i);
		i++;
		j++;
	}
	return (ft_strcat(sub, "\0"));
}

	//	printf("input:\n***%s***\n", (char*)chunks->content);
	//	printf("line size: %zu\n", line_size);
	//	printf("substr:\n***%s***\n", substr);
	//	printf("prev line length: %zu\n", ft_strlen(*line));
	//	printf("line:\n***%s***\n", *line);

int	get_next_line(const int fd, char **line)
{
	static t_list	*chunks;
	t_list		*i;
	size_t		line_size;
	char		buf[BUFF_SIZE + 1];
	char		*substr;
	char		*tmp;
	
	if ((i = chunk_list(fd, buf)))
		chunks = i;
	if (BUFF_SIZE <= 0 || fd < 0 || line == NULL) 
		return (-1);
	if (chunks == NULL)
	{
		*line = NULL;
		return (0);
	}
	*line = ft_strnew(1);
	while (chunks)
	{
		if ((line_size = get_line_size(chunks)) != 0)
		{
			substr = ft_strsub_0((char*)chunks->content, 0 ,line_size);
			if (ft_strlen(substr))
			{
				tmp = *line;
				*line = ft_strjoin(*line, substr);
				ft_strdel(&tmp);
			}
			ft_strdel(&substr);
		}
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
//	char	text_b[] = "123\n12\n123\n1234\n12345\n123456\n1234567\n12345678\n123456789\n\0";
	char	text_b[] = "1\n\n\n1\n\n1\n123456789\n12345678\n1234567\n123456\n12345\n1234\n123\n12\n1\n\n\n1";
	char	*line;
	char	*x;
	int	text_len_b;
	int	b_fd;
	int i;

	i = 0;
	b = "Blain";
	x = (char*)malloc(sizeof(char) * 5);
	text_len_b = ft_strlen(text_b);
	b_fd = open(b, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	write(b_fd, text_b, text_len_b);
	close(b_fd);
	b_fd = open(b, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	while (i++ < 25)
	{
		get_next_line(b_fd, &line);
		printf("line:\n***%s***\n", line);
	}
	printf("%s", x);
	if (!x)
		printf("yo!");
	printf("%s", ft_strcat(x, "a"));
	printf("%zu", ft_strlen(ft_strcat(x, "a")));
	printf("check: \n***%s***\n", ft_strsub("abcdefg", 0, 0));
}
