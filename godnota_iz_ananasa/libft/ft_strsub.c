/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:20:56 by btanja            #+#    #+#             */
/*   Updated: 2019/06/05 15:49:19 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	j;

	i = -1;
	j = 0;
	sub = ft_strnew(len);
	while (++i != start)
		;
	while (j < len)
	{
		*(sub + j) = *(s + i);
		i++;
		j++;
	}
	return (sub);
}
