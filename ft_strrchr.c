/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:33:02 by jpasty            #+#    #+#             */
/*   Updated: 2019/04/11 20:22:38 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*last;

	if (c == '\0')
		return (ft_strchr(s, c));
	while ((last = ft_strchr((char *)s, c)) != '\0')
	{
		str = last;
		s = last + 1;
	}
	return (str);
}
