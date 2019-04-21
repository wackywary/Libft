/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:22:11 by btanja            #+#    #+#             */
/*   Updated: 2019/04/08 19:28:11 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "";

	printf("str: %s\n", str);
	printf("strlen: %zu\n", strlen(str));
	printf("ft_strlen: %zu\n", ft_strlen(str));
}
