/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:32:55 by btanja            #+#    #+#             */
/*   Updated: 2019/04/22 18:38:11 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_unsign(int n)
{
	unsigned int	num;

	if (n < 0)
		num = n * (-1);
	else
		num = n;
	return (num);
}

char				*ft_itoa(int n)
{
	char			*res;
	size_t			reslen;
	unsigned int	num;

	reslen = ft_reslen(n);
	if (!(res = (char*)ft_memalloc(reslen + 1)))
		return (NULL);
	num = ft_unsign(n);
	while (reslen--)
	{
		res[reslen] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
