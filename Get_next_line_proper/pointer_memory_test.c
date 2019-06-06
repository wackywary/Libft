#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include "get_next_line.h"

int main()
{
	char	*tmp;
	char	*point;
	size_t	length;

	point = (char*)malloc(sizeof(char) * 5);
	length = 5;
	while (length--)
		point[length] = 'a';
	*point = 1;
	tmp = point;
	printf("tmp string: %s\n", tmp);
	printf("tmp adress: %p\n", &tmp);
	printf("point adress: %p\n", &point);
	printf("point string: %s\n", point);
	point = (char*)malloc(sizeof(char) * 5);
	free(tmp);
	free(point);
	printf("%s", ft_strnew(1));
}
