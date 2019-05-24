#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
# define BUFF_SIZE 1

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

void	read_file(int fd, char *buf)
{
	int len;
	long bytes;
	char *chunk;

	len = 0;
	//printf("read b?: %ld\n", bytes = read(fd, buf, BUFF_SIZE));
	while ((bytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
		printf("bytes: %ld\n", bytes);
		chunk = (char*)malloc(sizeof(char) * (bytes + 1));
		chunk[bytes + 1] = '\0';
		while (bytes)
		{
			chunk[bytes] = buf[bytes];
			bytes--;
		}
		chunk[0] = buf[0];
		printf("chunk: %s\n", chunk);
		len++; 
	}
	printf("len: %d\n", len);
}

int	main()
{
	char *a;
	char *b;
	char buf[BUFF_SIZE + 1];
	int a_fd;
	int b_fd;

	a = "testfile";
	b = "testfile2";
	a_fd = open(a, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	b_fd = open(b, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	write(b_fd, "1st line\n2nd line\n3rd line\n", 28);
	close(b_fd);
	b_fd = open(b, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	printf("lines: %d\n", count_lines(b_fd, buf));
	read_file(b_fd, buf);
	printf("buf b: %s\n", buf);
	close(b_fd);
	printf("fd: %d\n", a_fd);
	printf("fd2: %d\n", b_fd);
	printf("write?: %ld\n", write(a_fd, "file_aaa\n", 10));
	close(a_fd);
	a_fd = open(a, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	printf("read? : %ld\n", read(a_fd, buf, BUFF_SIZE));
	printf("buf: %s\n", buf);
	close(a_fd);
}
