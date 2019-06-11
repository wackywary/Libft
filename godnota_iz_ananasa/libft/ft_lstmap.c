#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *frsh_one;
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
