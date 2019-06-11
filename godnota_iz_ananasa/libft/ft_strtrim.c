/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 20:50:34 by btanja            #+#    #+#             */
/*   Updated: 2019/04/17 21:09:46 by btanja           ###   ########.fr       */
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
	end = ft_strlen(s);
	while (*(s + ++sta) == ' ' || *(s + sta) == '\n' || *(s + sta) == '\t')
		;
	if (sta == end)
		return ("");
	while (*(s + --end) == ' ' || *(s + end) == '\n' || *(s + end) == '\t')
		;
	if (end >= sta)
		len = end - sta + 1;
	else
		len = sta - end + 1;
	trim = ft_strsub(s, sta, len);
	*(trim + len) = '\0';
	return (trim);
}
