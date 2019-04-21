/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:03:34 by btanja            #+#    #+#             */
/*   Updated: 2019/04/15 16:46:20 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	int		i;

	i = -1;
	if (!s)
		return (NULL);
	fresh = ft_strnew(ft_strlen(s));
	while (*(s + ++i))
		*(fresh + i) = f(*(s + i));
	return (fresh);
}
