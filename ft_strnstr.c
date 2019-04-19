/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:24:17 by jpasty            #+#    #+#             */
/*   Updated: 2019/04/14 18:23:11 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(char *s, size_t l)
{
	size_t		i;

	i = 0;
	while (i < l)
	{
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (i);
}

char			*ft_strnstr(const char *dst, const char *src, size_t len)
{
	char		*s1;
	char		*s2;
	size_t		i;
	size_t		nl;

	i = 0;
	s1 = (char *)dst;
	s2 = (char *)src;
	nl = ft_strnlen(s2, len);
	if (*s2 == '\0')
		return (s1);
	while (i <= (len - nl))
	{
		if (*s1 == *s2 && (ft_memcmp(s1, s2, nl) == 0))
			return (s1);
		s1++;
		i++;
	}
	return (NULL);
}
