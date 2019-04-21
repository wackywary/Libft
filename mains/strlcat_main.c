/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:06:03 by btanja            #+#    #+#             */
/*   Updated: 2019/04/13 12:38:28 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int		main(void)
{	char *dest;

	if (!(dest = (char*)malloc(sizeof(*dest) * 15)))
		return (0);
	memset(dest, 0, 15);
	memset(dest, 'r', 6);
//	printf("strlcat out: %zu\n",strlcat(dest, "lorem ipsum dolor sit amet", 15));
//	printf("libc: %s\n", dest);
	printf("ft_strlcat out: %zu\n", ft_strlcat(dest, "lorem ipsum dolor sit amet", 15));
	printf("libft: %s\n", dest);
	return (0);
}

