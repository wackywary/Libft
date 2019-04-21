/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:29:37 by btanja            #+#    #+#             */
/*   Updated: 2019/04/11 18:31:03 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char str[] = "	 -1234b";
	printf("Atoi original result: %d ", atoi(str));
	printf("Atoi original result: %d ", atoi(str));
	printf("Ft_atoi result is %d", ft_atoi(str));
}
