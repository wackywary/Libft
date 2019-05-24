#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include "libft.h"
# define BUFF_SIZE 100
/*
typedef struct node
{
	int	size;
	char	*chunk;
	struct	node *next;
}	node_c;
*/

void	ft_lstaddtoend(t_list *alst, t_list *new)
{
	while (alst->next)
		alst = alst->next;
	alst->next = new;
}

t_list *chunk_list_reverse(int fd, char *buf)	//linked list with backwards output, because we add to start of list
{
	long	bytes;
	t_list	*chunk_new;
	t_list	*chunk_fst;
	
	bytes = read(fd, buf, BUFF_SIZE);
	chunk_fst = ft_lstnew(buf, bytes + 1);
	while ((bytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
		chunk_new = ft_lstnew(buf, bytes + 1);
		ft_lstadd(&chunk_fst, chunk_new);
	}
	return (chunk_fst);
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

	
char	*get_line_rev(int fd, char *buf)
{
	t_list	*chunks;
	char	*line;
	int	line_size;
	int	bo;

	chunks = chunk_list_reverse(fd, buf);
	line_size = 0;
	bo = 0;
	line = "";
	//printf("chunks cont 1st: %s", (char*)(chunks->content));
	while (chunks && bo != 1)
	{
		while (*(char*)(chunks->content) != '\n' && *(char*)(chunks->content))
		{
			//printf("%c\n", *(char*)(chunks->content));
			line_size++;
			chunks->content++;
		//	printf("%s\n", ((char*)(chunks->content) - line_size));
		}
		if (*((char*)(chunks->content)) == '\n')
			bo = 1;
		//printf("chunks content: %s", (char*)((chunks->content) - line_size));
		line = ft_strjoin(line, ((char*)chunks->content - line_size));	
		chunks = chunks->next;
		line_size = 0;
	}
	return (line);
}

/*void	ft_lstcpy(t_list *elem)
{
	elem->content
}
*/
char	*get_line(int fd, char *buf) //doesn't work if BUFF_SIZE > line\n
{
	static t_list	*chunks;
	char		*line;
	char 		**split_line;
	t_list		*i;
	int		line_size;
	int		bo;

	
	i = chunk_list(fd, buf);
	printf("i: %s\t", (char*)i->content);
	if ((char*)i->content_size != 0)
		chunks = i;
	line_size = 0;
	bo = 0;
	line = "";
	//printf("chunks cont 1st: %s", (char*)(chunks->content));
	while (chunks && bo != 1)
	{
		while (*(char*)(chunks->content) != '\n' && *(char*)(chunks->content))
		{
			//printf("%c\n", *(char*)(chunks->content));
			line_size++;
			chunks->content++;
		//	printf("%s\n", ((char*)(chunks->content) - line_size));
		}
		if (*((char*)(chunks->content)) == '\n')
		{
			bo = 1;
			split_line = ft_strsplit(((char*)chunks->content - line_size), '\n'); //ft_strtrim only first \n - easier
			line = ft_strjoin(line, *split_line);
			(char*)chunks->content = ft_strsub((char*)chunks->content, line_size, ft_strlen((char*)chunks->content) - line_size);
		}
		//printf("chunks content: %s", (char*)((chunks->content) - line_size));
		else if (*((char*)(chunks->content)))
		{
			line = ft_strjoin(line, ((char*)chunks->content - line_size));	
			chunks = chunks->next;
		}
		line_size = 0;
	}
	return (line);
}

int	main()
{
	char	*b;
	t_list	*chunks;
	char	buf[BUFF_SIZE + 1];
	int	b_fd;
	int	i;

	i = 0;
	b = "Plain";
	b_fd = open(b, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	write(b_fd, "1st line\n2nd line\n3rd line\n4th line ept ku ku", 46);
	close(b_fd);
	b_fd = open(b, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	//chunks = chunk_list_reverse(b_fd, buf);
//	ft_lstiter(chunks, printf("%p\n", chunks->content));	
	/*while (chunks)
	{
		printf("%s\t", (char*)(chunks->content));
		chunks = chunks->next;
	}*/
	while (i < 4)
	{
		printf("%s\n", get_line(b_fd, buf));
		close(b_fd);
		i++;
	}
}
