/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:28:53 by btanja            #+#    #+#             */
/*   Updated: 2019/04/12 15:17:06 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	int		len;

	len = 0;
	while (s1[len])
		len++;
	tmp = (char *)malloc(sizeof(char) * (len));
	tmp[len] = '\0';
	while (len--)
		tmp[len] = s1[len];
	return (tmp);
}
