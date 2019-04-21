/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:31:23 by btanja            #+#    #+#             */
/*   Updated: 2019/04/08 18:09:32 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int main()
{
	unsigned char src1[] = "abcde";
//	unsigned char src1[] = "fghij";
	unsigned char src2[] = "abcde";
//	unsigned char src2[] = "fghij";
	size_t n;

	n = 5;
//	printf("dest before memmove: %s\n", dest1);
	printf("string before memmove: %s\n", src1);
	memmove(&src1[0], &src1[3], n);
//	printf("dest after memmove: %s\n", dest1);
	printf("string after memmove: %s\n", src1);
	printf("string before ft_memmove: %s\n", src2);
	ft_memmove(&src2[0], &src2[3], n);
//	printf("dest after ft_memmove: %s\n", dest2);
	printf("src after ft_memmove: %s\n", src2);
}
