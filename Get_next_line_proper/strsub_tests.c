#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include "get_next_line.h"

char	*ft_strsub_0(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	j;

	i = -1;
	j = 0;
	sub = ft_strnew(len + 1);
	while (++i != start)
		;
	while (j < len)
	{
		*(sub + j) = *(s + i);
		i++;
		j++;
	}
	return (ft_strcat(sub, "\0"));
}
