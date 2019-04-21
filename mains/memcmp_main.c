/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:55:09 by btanja            #+#    #+#             */
/*   Updated: 2019/04/08 19:18:44 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int main()
{
	char str1[] = "";
	char str2[] = "ab";
	int n;

	n = 1;
	printf("str1: %s | ", str1);
	printf("str2: %s | ", str2);
	printf("n = %d\n", n);
	printf("memcmp: %d\n", memcmp(str1, str2, n));
	printf("ft_memcmp: %d\n", ft_memcmp(str1, str2, n));
}
