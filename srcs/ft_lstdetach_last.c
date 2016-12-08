#include "lemin.h"

void	ft_lstdetach_last(t_list *l)
{
	t_list	*c;

	c =  l;
	while (c)
	{
		if (c->next && !c->next->next)
			c->next = NULL;
		c = c->next;
	}
}
