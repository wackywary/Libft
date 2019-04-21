/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcat_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:26:35 by btanja            #+#    #+#             */
/*   Updated: 2019/04/10 15:40:24 by btanja           ###   ########.fr       */
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

	strcat(one, two);
	printf("libc: %s\n", one);
	ft_strcat(one, three);
	printf("libft: %s\n", one);
	return (0);
}

