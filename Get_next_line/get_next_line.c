#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
# define BUFF_SIZE 2
#include "libft.h"

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
	char	*text;
	char	buf[BUFF_SIZE + 1];
	int	len;

	len = 0;
	text = get_text(fd, buf);
	while (*(text + len) != '\n')
		len++;
	*line = (char*)malloc(sizeof(char) * (len + 1));
	while (len > 0)
	{
		*((*line) + len) = *(text + len);
		len--;
	}
	(*line)[0] = text[0];
	return (1);
}

int	main()
{
	char	*b;
	char	*line;
	char	buf[BUFF_SIZE + 1];
	int	b_fd;

	b = "testfile2";
	b_fd = open(b, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	write(b_fd, "1st line\n2nd line\n3rd line\n", 28);
	close(b_fd);
	b_fd = open(b, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
//	printf("text:\n%s\n", get_text(b_fd, buf));
	printf("%d\n", get_next_line(b_fd, &line));
	printf("line: %s\n", line);
	close(b_fd);
}
