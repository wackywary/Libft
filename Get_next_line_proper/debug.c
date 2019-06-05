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
		printf("content: %c\n", *((char*)lst->content + k));
		printf("newchunk: %c\n", *((char*)lst->content + k));
		*((char*)lst->content + k) = *(newchunk + k);
		k++;
	}
	//*((char*)lst->content) = *(newchunk);
	//*((char*)lst->content + k) = '\0';
	lst->content_size = newsize;
	ft_strdel(&newchunk);
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
