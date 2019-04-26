/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:28:53 by btanja            #+#    #+#             */
/*   Updated: 2019/04/22 20:41:36 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	size_t	len;

	len = 0;
	while (s1[len])
		len++;
	if (!(tmp = (char *)malloc(sizeof(char) * (++len))))
		return (NULL);
	tmp[len] = '\0';
	while (len--)
		tmp[len] = s1[len];
	return (tmp);
}
