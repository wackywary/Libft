/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:47:07 by btanja            #+#    #+#             */
/*   Updated: 2019/04/12 15:50:51 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int main()
{
	unsigned char dest1[] = "abcdefg";
	unsigned char src1[] = "12345";
	unsigned char dest2[] = "abcdefg";
	unsigned char src2[] = "12345";
	size_t n;
	int c;

	n = 2;
	c = 98;
//	printf("dest before ft_memccpy: %s\n", dest2);
//	printf("src before ft_memccpy: %s\n", src2);
//	printf("\n");
	memccpy(dest1, src1, c, n);
	printf("dest after memccpy: %s\n", dest1);
	printf("src after memccpy: %s\n", src1);
	ft_memccpy(dest2, src2, c, n);
	printf("dest after ft_memccpy: %s\n", dest2);
	printf("src after ft_memccpy: %s\n", src2);
}
