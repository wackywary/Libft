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

char	*ft_mallocstrcpy(char *dst, const char *src)
{
	int i;

	i = -1;
	dst = ft_memalloc(ft_strlen(src));
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}
int	line_length(char *text)
{
	int len;

	len = 0;
	while (*(text + len) != '\n' && *(text + len))
		len++;
	return (len);
}
int	get_next_line(const int fd, char **line)
{
	static char	*text;
	char		*i;
	char		buf[BUFF_SIZE + 1];
	int		len;

	i = get_text(fd, buf);
	if (i != "")
		text = ft_mallocstrcpy(text, i);
	else
	{
		len = line_length(text);
		text = ft_strsub(text, len + 1, ft_strlen(text) - len);
	}
	len = line_length(text);
	*line = ft_strsub(text, 0, len);
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
	b = "WarAndPeace.txt";
	b_fd = open(b, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	write(b_fd, "1st line\n2nd line\n3rd line\n4th line ept ku ku", 46);
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
