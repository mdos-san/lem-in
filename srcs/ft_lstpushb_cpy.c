#include "lemin.h"

void	ft_lstpushb_cpy(t_list *lst, void *content, size_t content_size)
{
	if (lst->next != NULL)
		ft_lstpushb(lst->next, content, content_size);
	else
		lst->next = ft_lstnew_cpy(content, content_size);
}
