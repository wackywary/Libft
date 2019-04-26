/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:56:55 by btanja            #+#    #+#             */
/*   Updated: 2019/04/13 12:38:01 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t src_len;
	size_t dst_len;
	size_t i;
	size_t j;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = ft_strlen(dst);
	j = 0;
	if (size < dst_len + 1)
		return (src_len + size);
	else if (size > dst_len + 1)
	{
		while (src[j] && i < size - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	return (dst_len + src_len);
}
