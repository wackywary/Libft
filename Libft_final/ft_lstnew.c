/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 19:53:54 by btanja            #+#    #+#             */
/*   Updated: 2019/04/26 19:54:49 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *frsh;

	if (!(frsh = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		frsh->content = NULL;
		frsh->content_size = 0;
	}
	else
	{
		if (!(frsh->content = ft_memalloc(content_size)))
		{
			ft_memdel((void*)frsh);
			return (NULL);
		}
		ft_memcpy(frsh->content, content, content_size);
		frsh->content_size = content_size;
	}
	frsh->next = NULL;
	return (frsh);
}
