/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:16:19 by btanja            #+#    #+#             */
/*   Updated: 2019/04/12 15:16:24 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		chr;
	const unsigned char	*str;
	size_t				i;

	chr = (unsigned char)c;
	str = s;
	i = 0;
	while (i < n)
	{
		if (str[i] == chr)
			return ((void*)s);
		i++;
	}
	return (NULL);
}
