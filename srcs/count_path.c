#include "lemin.h"

int	count_path(t_list *st_l)
{
	int		i;
	t_list	*l;
	t_room	*r;

	i = 0;
	l = st_l;
	while (l)
	{
		r = *(t_room**)l->content;
		if (r->p != -1)
			++i;
		l = l->next;
	}
	return (i);
}
