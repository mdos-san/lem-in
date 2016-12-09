#include "lemin.h"

int	ft_lstcount(t_list *l)
{
	t_list	*c;
	int		i;

	c = l;
	i = 0;
	while (c)
	{
		++i;
		c = c->next;
	}
	return (i);
}
