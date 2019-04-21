/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:01:03 by btanja            #+#    #+#             */
/*   Updated: 2019/04/08 21:25:58 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int main()
{
	char dest1[] = "abcde";
	char src[] = "123";
	char dest2[] = "abcde";
	size_t n;

	n = 0;
	printf("src: %s\n", src);
	printf("dest before strncpy: %s\n", dest1);
	printf("strncpy res: %s\n", strncpy(dest1, src, n));
	printf("dest before ft_strncpy: %s\n", dest2);
	printf("ft_strncpy res: %s\n", ft_strncpy(dest2, src, n));
}
