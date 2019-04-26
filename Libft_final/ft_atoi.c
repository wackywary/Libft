/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:25:06 by btanja            #+#    #+#             */
/*   Updated: 2019/04/26 22:10:47 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_longer(long res, long neg, const char *str)
{
	if (res > 92233720368547780)
	{
		if (*str >= '0' && *str <= '7')
			return (2);
		else if (neg == -1)
			return (0);
		return (-1);
	}
	else
		return (2);
}

int			ft_atoi(const char *str)
{
	long neg;
	long res;

	neg = 1;
	res = 0;
	while (*str == ' ' || ((*str > 8) && (*str < 14)))
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (ft_longer(res, neg, str) == 0)
			return (0);
		else if (ft_longer(res, neg, str) == -1)
			return (-1);
		res = res * 10 + (*str - '0');
		str++;
	}
	return ((int)(neg * res));
}
