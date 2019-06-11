/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:25:40 by btanja            #+#    #+#             */
/*   Updated: 2019/04/12 19:53:49 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	needle_len;

	if (!*needle)
		return ((char*)haystack);
	needle_len = ft_strlen(needle);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			if (!ft_strncmp(haystack, needle, needle_len))
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
