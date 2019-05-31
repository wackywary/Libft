#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include "libft.h"
# define BUFF_SIZE 5

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
void	print_lst(t_list *lst)
{
	char *content;
	
	while (lst)
	{
		content = (char*)lst->content;
		printf("%s\n", content);
		lst = lst->next;
	}
}

t_list	*lst_goto_i(t_list *lst, int i)
{
	while (i--)
		lst = lst->next;
	return (lst);
}
void	lstdel_i(t_list *lst, int i)
{
	lst = lst_goto_i(lst, i);
	ft_memdel(&lst->content);
	lst->content_size = 0;
	free(lst);
	lst = NULL;
}

void	lstdel(t_list *lst)
{
	ft_memdel(&lst->content);
	lst->content_size = 0;
	free(lst);
	lst = NULL;
}

void	lstreplace_i(t_list *lst, int i, char *content, size_t size)
{
	int k;

	k = 0;
	lst = lst_goto_i(lst, i);
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

int	main()
{
	char	*b;
	t_list	*chunks;
	char	*line;
	char *content;
	int	b_fd;
	int	i;
	char	buf[BUFF_SIZE + 1];

	i = 1;
	b = "Plain";
	line = "abcdefghijklmnopqrstuvwxyz123456789";
	content = "KIKA PIKA";
	printf("strlen: %ld\n", ft_strlen(content));
	b_fd = open(b, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	write(b_fd, line, ft_strlen(line));
	close(b_fd);
	b_fd = open(b, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	chunks = chunk_list(b_fd, buf);
	print_lst(chunks);
//	printf("\n***lstdel***\n");
//	lstdel_i(chunks, i);
//	print_lst(chunks);
	printf("\n***lstreplace***\n");
	lstreplace_i(chunks, i, content, ft_strlen(content));
	print_lst(chunks);
}
