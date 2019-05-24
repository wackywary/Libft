#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
# define BUFF_SIZE 2
#include "libft.h"

int	static_read(int i)
{
	static int	bytes = 0;

	bytes = bytes + i;
	return (bytes);
}

char	*get_chunk(int fd, char *buf, long bytes, char *chunk)
{
	chunk = (char*)malloc(sizeof(char) * (bytes + 1));
	chunk[bytes + 1] = '\0';
	while (bytes)
	{
		chunk[bytes] = buf[bytes];
		bytes--;
	}
	chunk[0] = buf[0];
	
	return (chunk);
}

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

int	main()
{
	char	*b;
	char	buf[BUFF_SIZE + 1];
	int	b_fd;

	b = "testfile2";
	b_fd = open(b, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	write(b_fd, "1st line\n2nd line\n3rd line\n", 28);
	close(b_fd);
	b_fd = open(b, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	/*chunkus = "";
	while ((i = read(b_fd, buf, BUFF_SIZE)) > 0)
	{
		chunk = get_chunk(b_fd, buf, i, chunk);
		chunkus = ft_strjoin(chunkus, chunk);
	}*/
	printf("text:\n%s\n", get_text(b_fd, buf));
	close(b_fd);
}
