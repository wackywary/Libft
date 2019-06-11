#include "libft.h"

t_list *ft_lstnew(void const *content, size_t content_size)
{
	t_list *frsh;
	
	if(!(frsh = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		frsh->content = NULL;
		frsh->content_size = 0;
	}
	else
	{
		if(!(frsh->content = ft_memalloc(content_size)))
		{
			free(frsh);
			return (NULL);
		}
		ft_memcpy(frsh->content, content, content_size);	
		frsh->content_size = content_size;
	}
	frsh->next = NULL;
	return (frsh);
}
