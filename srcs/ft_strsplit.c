#include "libft.h"

static char	*ft_strtrim_c(char const *s, char c)
{
	unsigned int	sta;
	size_t			end;
	size_t			len;
	char			*trim;

	sta = -1;
	end = ft_strlen(s);
	while (*(s + ++sta) == c)
		;
	if (sta == end)
		return ("");
	while (*(s + --end) == c)
		;
	if (end >= sta)
		len = end - sta + 1;
	else
		len = sta - end + 1;
	trim = ft_strsub(s, sta, len);
	*(trim + len) = '\0';
	return (trim);
}

static size_t	ft_strlen_c(const char *s, char c)
{
	size_t len;

	len = 0;
	while (*s && *s++ != c)
		len++;
	return (len);
}

char	**ft_strsplit(char const *s, char c)
{
	char	*big_str;
	char	*lil_str;
	char	**output;
	size_t	lil_len;
	
	output = (char**)ft_memalloc(ft_strlen(s));
	big_str = (char)s;
	lil_str = NULL;
	lil_len = 0;
	while (big_str)
	{	
		big_str = ft_strtrim_c(big_str, c);
		lil_len = ft_strlen_c(big_str, c);
		lil_str = (char*)ft_memalloc(lil_len);
		while (lil_len--)
		{
			lil_str[lil_len] = *big_str;
			big_str++;
		}
		*output++ = *lil_str;
		ft_memdel(big_str);
		ft_memdel(lil_str);
	}
}
