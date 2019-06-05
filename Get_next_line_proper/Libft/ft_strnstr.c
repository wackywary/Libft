/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:54:21 by btanja            #+#    #+#             */
/*   Updated: 2019/04/13 11:46:36 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	if (!*needle)
		return ((char*)haystack);
	needle_len = ft_strlen(needle);
	while (*haystack && len--)
	{
		if (*haystack == *needle)
		{
			if (!ft_strncmp(haystack, needle, needle_len) && needle_len <= len)
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
