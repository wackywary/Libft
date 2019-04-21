/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:04:11 by btanja            #+#    #+#             */
/*   Updated: 2019/04/06 19:15:20 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int main()
{
	int len;
	int c1;
	int c2;
//	unsigned char str1[] = "qqqqq";
	unsigned char str2[] = "ppppp";

	c1 = 56;
	c2 = 57;
	len = 6;
//	printf("memset return: %d\n", (int)memset(str1 , c1, len));
	printf("ft_memset return: %d\n", (int)ft_memset(str2, c2, len));
	ft_memset(str2, c2, len);
//	printf("memset: %s\n", str1);
	printf("ft_memset: %s\n", str2);
}
