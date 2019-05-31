#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include "libft.h"
# define BUFF_SIZE 26

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
	
	bytes = read(fd, buf, BUFF_SIZE);
	chunk_fst = ft_lstnew(buf, bytes + 1);
	while ((bytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
		chunk_new = ft_lstnew(buf, bytes + 1);
		ft_lstaddtoend(chunk_fst, chunk_new);
	}
	return (chunk_fst);
}

void	lstreplace(t_list *lst, char *content, size_t size)
{
	int k;

	k = 0;
	ft_memdel(&lst->content);
	lst->content = ft_memalloc(size);
	while (k < size)
	{
		*((char*)lst->content + k) = *(content + k);
		k++;
	}
	*((char*)lst->content) = *(content);
	lst->content_size = size;
}

int	get_next_line(const int fd, char **line)
{
	static t_list	*chunks;
	t_list		*i;
	int		line_size;
	int		bo;
	char		buf[BUFF_SIZE + 1];

	char		*newchunk;
	int		newsize;
	
	i = chunk_list(fd, buf);
	if ((char*)i->content_size)
		chunks = i;
	line_size = 0;
	bo = 0;
	*line = "";
	while (chunks && bo != 1)
	{
		while (*(char*)(chunks->content + line_size) != '\n' && *(char*)(chunks->content + line_size))
			line_size++;
		if (*(char*)(chunks->content + line_size) == '\0')
		{
			*line = ft_strjoin(*line, (char*)chunks->content);	
			printf("0strjoin: %s\n", *line);
			if ((chunks = chunks->next) == NULL)
				return (1);
		}

		if (*(char*)(chunks->content + line_size) == '\n')
		{
			bo = 1;
			*line = ft_strjoin(*line, ft_strsub((char*)chunks->content, 0, line_size));
			printf("nstrjoin: %s\n", *line);
			newchunk = ft_strsub((char*)chunks->content, line_size + 1, chunks->content_size - line_size - 1);
			printf("newchunk: %s\n", newchunk);
			newchunk[chunks->content_size - line_size - 1] = '\0';
			newsize = ft_strlen(newchunk);
			lstreplace(chunks, newchunk, newsize);
		}
			line_size = 0;
	}
	return (1);
}

int	main()
{
	char	*b;
	t_list	*chunks;
	char	*line;
	int	b_fd;
	int	i;

	i = 0;
	b = "Plain";
	line = ft_memalloc(50);
	b_fd = open(b, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	write(b_fd, "1st line\n2nd line\n3rd line\n4th line ept ku ku", 46);
	close(b_fd);
	b_fd = open(b, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	while (i < 4)
	{
		printf("out:%d\n", get_next_line(b_fd, &line));
		printf("line: %s\n", line);
		close(b_fd);
		i++;
	}
}
