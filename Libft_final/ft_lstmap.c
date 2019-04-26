/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 19:56:51 by btanja            #+#    #+#             */
/*   Updated: 2019/04/26 19:57:06 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*frsh_one;
	t_list	*frsh;

	if (!(frsh = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	frsh = f(frsh);
	frsh_one = frsh;
	while (lst->next)
	{
		lst = lst->next;
		frsh->next = f(ft_lstnew(lst->content, lst->content_size));
		frsh = frsh->next;
	}
	return (frsh_one);
}
