#include <stdio.h>
#include <stdlib.h>
#include <libft.h>
void	mallocate(char **line)
{
	int	i;

	i = 0;
	*line = (char*)malloc(sizeof(char) * 10);
	(*line)[10] = '\0';
	while (i < 10)
	{
		(*line)[i] = 1;
		i++;
	}
}

int	main()
{
	char	*line;
	int	i;

	i = 0;
	mallocate(&line);
	/*while (i < 10)
	{
		*(line + i) = 1;
		i++;
	}*/	
	printf("%ld\n", ft_strlen(line));
}
