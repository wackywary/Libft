/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:46:45 by btanja            #+#    #+#             */
/*   Updated: 2019/04/22 20:35:12 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const char	*s;
	char		*d;
	size_t		i;

	s = (const char*)src;
	d = (char*)dst;
	i = -1;
	while (++i < n)
	{
		*(d + i) = *(s + i);
		if (*(s + i) == (char)c)
			return (dst + i + 1);
	}
	return (NULL);
}
