/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:29:31 by btanja            #+#    #+#             */
/*   Updated: 2019/04/08 19:37:21 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "abc";

	printf("str: %s\n", str);
	printf("strlen: %s\n", strdup(str));
	printf("ft_strlen: %s\n", ft_strdup(str));
}
