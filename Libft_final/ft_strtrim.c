/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 20:50:34 by btanja            #+#    #+#             */
/*   Updated: 2019/04/26 22:22:28 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	sta;
	size_t			end;
	size_t			len;
	char			*trim;

	sta = -1;
	if (!s)
		return (NULL);
	end = ft_strlen(s);
	while (*(s + ++sta) == ' ' || *(s + sta) == '\n' || *(s + sta) == '\t')
		;
	if (sta == end)
		return (ft_strdup(""));
	while (*(s + --end) == ' ' || *(s + end) == '\n' || *(s + end) == '\t')
		;
	if (end >= sta)
		len = end - sta + 1;
	else
		len = sta - end + 1;
	if (!(trim = ft_strsub(s, sta, len)))
		return (NULL);
	*(trim + len) = '\0';
	return (trim);
}
