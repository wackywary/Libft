/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 10:34:40 by jpasty            #+#    #+#             */
/*   Updated: 2019/05/22 18:00:47 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

//void static mt_assert(int n)
//{
//    printf("%d\n", n);
//}

int			main(void)
{
//    test->timeout = 1;
//
//    char *line;
//    int fd;
//    int fd2;
//    int fd3;
//    int	diff_file_size;
//
//    system("mkdir -p sandbox");
//    system("openssl rand -base64 $((30 * 1000 * 3/4)) | tr -d '\n' | tr -d '\r' > sandbox/one_big_fat_line.txt");
//    system("echo '\n' >> sandbox/one_big_fat_line.txt");
//
//    fd = open("sandbox/one_big_fat_line.txt", O_RDONLY);
//    fd2 = open("sandbox/one_big_fat_line.txt.mine", O_CREAT | O_RDWR | O_TRUNC, 0755);
//
//    while (get_next_line(fd, &line) == 1)
//    {
//        write(fd2, line, strlen(line));
//        write(fd2, "\n", 1);
//    }
//    if (line)
//        write(fd2, line, strlen(line));
//    close(fd);
//    close(fd2);
//
//    system("diff sandbox/one_big_fat_line.txt sandbox/one_big_fat_line.txt.mine > sandbox/one_big_fat_line.diff");
//    fd3 = open("sandbox/one_big_fat_line.diff", O_RDONLY);
//    diff_file_size = read(fd3, NULL, 10);
//    close(fd3);
//
//    mt_assert(diff_file_size == 0);
//    char 	*line;
//    int		out;
//    int		p[2];
//    int		fd;
//
//    fd = 1;
//    out = dup(fd);
//    pipe(p);
//
//    dup2(p[1], fd);
//    write(fd, "aaa\nbbb\nccc\nddd\n", 16);
//    dup2(out, fd);
//    close(p[1]);
//    get_next_line(p[0], &line);
//    mt_assert(strcmp(line, "aaa") == 0);
//    get_next_line(p[0], &line);
//    mt_assert(strcmp(line, "bbb") == 0);
//    get_next_line(p[0], &line);
//    mt_assert(strcmp(line, "ccc") == 0);
//    get_next_line(p[0], &line);
//    mt_assert(strcmp(line, "ddd") == 0);
//    free(line);
//
//    char 	*line;
//    int		out;
//    int		p[2];
//    int		fd;
//
//    out = dup(1);
//    pipe(p);
//
//    fd = 1;
//    dup2(p[1], fd);
//    write(fd, "efghijkl", 8);
//    close(p[1]);
//    dup2(out, fd);
//    get_next_line(p[0], &line);
//    mt_assert(strcmp(line, "efghijkl") == 0);
//
    int		fd1;
	int		fd2;
	int     fd3;
	int     b_fd;
	char    *b;
	char	*line;

  /*  fd1 = open("WarAndPeace.txt", O_RDONLY);
	printf("%d\n", get_next_line(fd1, &line));
	{
        ft_putstr(line);
        ft_putchar('\n');
		free(line);

    }*/
    b = "testfile2";
    b_fd = open(b, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    write(b_fd, "1st line\n2nd line\n3rd line\n", 28);
    close(b_fd);
    b_fd = open(b, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    printf("%d\n", get_next_line(b_fd, &line));
    {
        ft_putstr(line);
        ft_putchar('\n');
        free(line);
    }
/*	fd2 = open("//Users/jpasty/Desktop/mleticia/test/mince_meat.txt", O_RDONLY);
	get_next_line(fd2, &line);
	{
    ft_putstr(line);
	ft_putchar('\n');
	free(line);
	}
	fd3 = open("//Users/jpasty/Desktop/mleticia/test/ene", O_RDONLY);
    get_next_line(fd3, &line);
    {
        ft_putstr(line);
        ft_putchar('\n');
	    free(line);
    }
//	get_next_line(fd2, &line);
//	{
//    ft_putstr(line);
//	ft_putchar('\n');
//	free(line);
//	}

	close(fd1);
	close(fd2);
	close(fd3);
	close(fd1);*/
	return (0);
}
