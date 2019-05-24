#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include "libft.h"
# define BUFF_SIZE 2

char	*get_text(int fd, char *buf)
{
	long	bytes;
	char	*chunkus;
	char	*chunk;

	chunkus = "";
	while ((bytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
		chunk = (char*)malloc(sizeof(char) * (bytes + 1));
		chunk[bytes + 1] = '\0';
		while (bytes)
		{
			chunk[bytes] = buf[bytes];
			bytes--;
		}
		chunk[0] = buf[0];
		chunkus = ft_strjoin(chunkus, chunk);
	}
	return (chunkus);
}

int	get_next_line(const int fd, char **line)
{
	static char	*text;
	char		*i;
	char		buf[BUFF_SIZE + 1];
	int		len;

	len = 0;
	i = get_text(fd, buf);
	if (i != "")
	{
		text = ft_memalloc(ft_strlen(i));
		ft_strcpy(text, i);
		while (*(text + len) != '\n' && *(text + len))
			len++;
		*line = ft_strsub(text, 0, len);
		text = ft_strsub(text, len + 1, ft_strlen(text) - len);
		printf("new text1:\n%s\n", text);
	}
	else
	{
		while (*(text + len) != '\n' && *(text + len))
			len++;
		*line = ft_strsub(text, 0, len);
		printf("len_else: %d\n", len);
		text = ft_strsub(text, len + 1, ft_strlen(text) - len);
		printf("new text:\n%s\n", text);
	}
	return (1);
}

int	main()
{
	char	*b;
	char	*line;
	char	buf[BUFF_SIZE + 1];
	int	b_fd;
	int	i;

	i = 0;
	b = "testfile2";
	b_fd = open(b, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	write(b_fd, "1st line\n2nd line\n3rd line\n", 28);
	close(b_fd);
	b_fd = open(b, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	while (i < 4)
	{
		printf("%d\n", get_next_line(b_fd, &line));
		printf("line:\n%s\n", line);
		i++;
	}
	close(b_fd);
}
