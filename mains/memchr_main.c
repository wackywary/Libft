/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr_mains.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:16:39 by btanja            #+#    #+#             */
/*   Updated: 2019/04/10 17:15:31 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main()
{
	unsigned char s[] = "abcde";
	size_t n;
	int c;

	n = 4;
	c = 95;
	printf("memchr out: %d\n", (int)memchr(s, c, n));
	printf("ft_memchr out: %d\n", (int)ft_memchr(s, c, n));	
}
