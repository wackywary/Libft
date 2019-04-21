/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:38:36 by btanja            #+#    #+#             */
/*   Updated: 2019/04/12 15:15:04 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (src < dst)
	{
		while (++i <= len)
			d[len - i] = s[len - i];
	}
	else
		while (len-- > 0)
		{
			d[i] = s[i];
			i++;
		}
	return (dst);
}
