/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:52:40 by btanja            #+#    #+#             */
/*   Updated: 2019/04/11 15:44:54 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <string.h>

int main()
{
	const char haystack[] = "abbbcde";
	const char needle[] = "bcdef";

	printf("strstr out: %s\n", strstr(haystack, needle));
	printf("ft_strstr out: %s\n", ft_strstr(haystack, needle));	
}
