#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <libft.h>
# define BUFF_SIZE 3

int count_lines(int fd, char *buf)
{
	int lines;
	long bytes;

	lines = 0;
	while ((bytes = read(fd, buf, BUFF_SIZE)) > 0)
		while (bytes > -1)
		{
			if (buf[bytes] == '\n')
				lines++;
			bytes--;
		}
	return (lines);
}

int	get_chunk(int fd, char *buf)
{
	int		bytes;
	int		length;
	char		*chunk;

	bytes = read(fd, buf, BUFF_SIZE);
	length = bytes;
	chunk = (char*)malloc(sizeof(char) * (bytes + 1));
	chunk[bytes + 1] = '\0';
	while (bytes)
	{
		chunk[bytes] = buf[bytes];
		bytes--;
	}
	chunk[0] = buf[0];
	
	return (length);
}

int	get_file_length(int fd, char *buf)
{
	long length;
	long i;

	length = 0;
	i = 1;
	while (i > 0)
	{	
		i = read(fd, buf, BUFF_SIZE);
		length = length + i;
	}
	close(fd);
	return (length);

}

char	*merge_chunks(int fd, char *buf)
{
	char 	*merge;
	int	chunk_size;
	int 	i;

	i = 0;
	chunk_size = get_chunk(fd, buf);
	merge = (char*)malloc(sizeof(char) * chunk_size);
	while (chunk)
	{
		*(merge + i) = *chunk;
		chunk++;
		i++;
	}

	return (merge);
}
/*
void	malloc_chunks(int fd, char *buf)
{
	int i;
	int lines;
	long bytes;
	char **chunk;

	i = 0;
	lines = count_lines(fd, buf);
	chunk = (char**)malloc(sizeof(char*) * lines);
	while ((bytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
		chunk[bytes + 1] = '\0';
		while (buf[i] != '\n')
		{
			while (i < bytes + 1)
			{
				chunk[i] = buf[i];
				i++;
			}
			if (buf[i] == '\0')
				
		}
		printf("chunk: %s\n", chunk);
	}
}*/

int	main()
{
	char *b;
	char buf[BUFF_SIZE + 1];
	int b_fd;

	b = "testfile2";
	b_fd = open(b, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	write(b_fd, "1st line\n2nd line\n3rd line\n", 28);
	close(b_fd);
	b_fd = open(b, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	//read_file_line(b_fd, buf);
	//printf("chunk_size: %d\n", get_chunk(b_fd, buf));
	//printf("chunk: %s\n", chunk);
	printf("file string: %s\n", merge_chunks(b_fd, buf));
	//printf("file length: %d\n", get_file_length(b_fd, buf));
	close(b_fd);
}
