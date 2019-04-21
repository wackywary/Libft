/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:24:43 by btanja            #+#    #+#             */
/*   Updated: 2019/04/08 17:46:48 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int main()
{
	unsigned char dest1[] = "abcde";
	unsigned char src1[] = "fghij";
	unsigned char dest2[] = "abcde";
	unsigned char src2[] = "fghij";
	size_t n;

	n = 3;
	memcpy(dest1 + 2, dest1 + 1, n);
	printf("dest after memcpy: %s\n", dest1);
	printf("src after memcpy: %s\n", src1);
	ft_memcpy(dest2, src2, n);
	printf("dest after ft_memcpy: %s\n", dest2);
	printf("src after ft_memcpy: %s\n", src2);
}
