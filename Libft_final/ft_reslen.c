/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 18:00:35 by btanja            #+#    #+#             */
/*   Updated: 2019/04/22 19:39:50 by btanja           ###   ########.fr       */
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

size_t				ft_reslen(int n)
{
	unsigned int	num;
	size_t			i;

	num = ft_unsign(n);
	i = 0;
	while (num > 0)
	{
		i++;
		num /= 10;
	}
	if (n <= 0)
		return (i + 1);
	else
		return (i);
}
