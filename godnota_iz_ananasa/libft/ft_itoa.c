#include "libft.h"

static unsigned int	ft_unsign(int n)
{
	unsigned int	num;

	if (n < 0)
		num = n * (-1);
	else
		num = n;
	return (num);
}

static size_t	ft_reslen(int n)
{
	unsigned int	num;
	size_t		i;

	num = ft_unsign(n);
	i = 0;
	while (num > 0)
	{
		i++;
		num /= 10;
	}
	if (n <= 0)
		return (i + 1);
	else
		return (i);
}

char	*ft_itoa(int n)
{
	char		*res;
	size_t		reslen;
	unsigned int	num;

	reslen = ft_reslen(n);
	res = (char*)ft_memalloc(reslen);
	num = ft_unsign(n);
	while (reslen--)
	{
		res[reslen] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
