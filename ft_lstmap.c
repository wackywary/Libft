#include "libft.h"

static size_t ft_listsize(t_list *lst)
{
	size_t size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list frsh;

	frsh = ft_lstnew(lst->content, lst->content_size);
	ft_lstiter(frsh, f);
	return (frsh);
}
