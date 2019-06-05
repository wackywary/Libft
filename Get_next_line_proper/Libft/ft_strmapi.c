/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:46:45 by btanja            #+#    #+#             */
/*   Updated: 2019/04/15 16:54:41 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*fresh;
	int		i;

	i = -1;
	if (!s)
		return (NULL);
	fresh = ft_strnew(ft_strlen(s));
	while (*(s + ++i))
		*(fresh + i) = f(i, *(s + i));
	return (fresh);
}
