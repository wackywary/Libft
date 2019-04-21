/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:10:36 by btanja            #+#    #+#             */
/*   Updated: 2019/04/10 17:33:25 by btanja           ###   ########.fr       */
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
	printf("strchr out: %d\n", (int)strchr(s, c));
	printf("ft_strchr out: %d\n", (int)ft_strchr(s, c));	
}
