/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:47:02 by btanja            #+#    #+#             */
/*   Updated: 2019/04/15 20:49:53 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	int		i;

	i = 0;
	fresh = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	while (*(s1 + i))
	{
		*(fresh + i) = *(s1 + i);
		i++;
	}
	return (ft_strcat(fresh, s2));
}
