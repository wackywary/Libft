/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:33:57 by btanja            #+#    #+#             */
/*   Updated: 2019/04/10 20:55:53 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main()
{
	const char s[] = "abcde";
	int c;

	c = 98;
	printf("strrchr out: %d\n", (int)strrchr(s, c));
	 printf("ft_strrchr out: %d\n", (int)ft_strrchr(s, c));	
}
