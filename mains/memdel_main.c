/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memdel_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 18:03:56 by btanja            #+#    #+#             */
/*   Updated: 2019/04/13 18:07:28 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

/*static	void	st_memdel(void **ap)
{
	free(ap);
	*ap = NULL;
}
*/
int main()
{
	size_t size;
	char	*ptr;

	size = 10;
	ptr = ft_memalloc(size);
	ft_memdel((void *)ptr);
	//free(ptr);
	//ptr = NULL;
}
