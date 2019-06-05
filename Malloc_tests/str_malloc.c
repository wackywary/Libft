#include <stdio.h>
#include <stdlib.h>
#define getName(var) #var

int	ft_find_zero(char *string)
{
	int i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

int ft_real_str_size(char *string)
{
	int i;

	i = ft_find_zero(string);
	while (string[i] == '\0')
		i++;
	printf("Last zero: string[%d]\n", i);
	return (i);
}

int main()
{
	char	*line;
	int	l;

	l = 10;
	line = (char*)malloc(sizeof(char) * l);	
	while (--l > -1) 
		line[l] = 1;
	printf("first zero: str[%d]\n", ft_find_zero(line));
//	ft_real_str_size(line);
	free(line);
}
