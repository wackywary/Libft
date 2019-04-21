/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncat_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:41:31 by btanja            #+#    #+#             */
/*   Updated: 2019/04/10 15:55:02 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int		main(void)
{
	char one[1024] = "first ";
	char two[] = "second ";
	char three[] = "third ";
	size_t n;

	n = 8;
	strncat(one, two, n);
	printf("libc: %s\n", one);
	ft_strncat(one, three, n);
	printf("libft: %s\n", one);
	return (0);
}

