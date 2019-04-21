/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:00:13 by btanja            #+#    #+#             */
/*   Updated: 2019/04/12 18:21:29 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"
 
int main(void)
{
      char s1[] = "test";
      char s2[] = "tEst";

      printf("Orig result is %d\n", strcmp(s1, s2));
      printf("s1 after orig is %s\n", s1);
      printf("s2 after orig is %s\n", s2);
 
      printf("ft result is %d\n", ft_strcmp(s1, s2));
      printf("s1 after ft is %s\n", s1);
      printf("s2 after ft is %s\n", s2);
      return (0);
}
