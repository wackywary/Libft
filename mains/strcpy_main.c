/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:43:24 by btanja            #+#    #+#             */
/*   Updated: 2019/04/08 19:59:20 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int main()
{
	char dest1[] = "abcde";
	char src[] = "fghij";
	char dest2[] = "abcde";

	printf("src: %s\n", src);
	printf("dest before strcpy: %s\n", dest2);
	printf("strcpy res: %s\n", strcpy(dest1, src));
	printf("dest before ft_strcpy: %s\n", dest2);
	printf("ft_strcpy res: %s\n", ft_strcpy(dest2, src));
}
