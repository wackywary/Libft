/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:43:12 by btanja            #+#    #+#             */
/*   Updated: 2019/04/06 18:47:40 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int main()
{
	size_t n1, n2;
	unsigned char str1[] = "abcde\0";
	unsigned char *s1;
	unsigned char str2[] = "abcde\0";
	unsigned char *s2;
	s1 = str1;
	s2 = str2;
	n1 = 8;
	n2 = 8;
	s1 += n1;
	s2 += n2;
	bzero(str1, n1);
	ft_bzero(str2, n2);
	n2 = 8;
	printf("bzero: %s\n", str1);
	printf("str[%zu]: %c\n", n1 - 1, *(s1 - 1));
	printf("str[%zu]: %c\n", n1, *s1);
	printf("ft_bzero: %s\n", str2);
	printf("str[%zu]: %c\n", n2 - 4, *(s2 - 4));
	printf("str[%zu]: %c\n", n2, *s2);

}
