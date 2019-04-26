/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:00:11 by btanja            #+#    #+#             */
/*   Updated: 2019/04/12 16:44:45 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;
	size_t src_len;

	i = -1;
	src_len = 0;
	while (src[src_len])
		src_len++;
	while (src[++i] && i < len)
		dst[i] = src[i];
	if (src_len < len)
		while (i < len)
			dst[i++] = '\0';
	return (dst);
}
