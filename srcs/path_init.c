#include "lemin.h"

static void	set_link_depth(t_list *link, int act_d, int depth)
{
	t_list	*l;
	t_room	*r;

	l = link;
	while (l)
	{
		r = *(t_room**)l->content;
		if (r->w == act_d && r->type != 2 && r->type != 1)
			r->w = depth;
		l = l->next;
	}
}

static int	bfs(t_room *r, int path, int depth, int debug)
{
	t_list	*l;
	t_room	*next;

	if (debug)
		ft_printf("BFS: Actualy on %s\n", r->name);
	if (r->type == 1)
	{
		ft_printf("PATH FINDED\n");
		return ((r->type == 1) ? 1 : 0);
	}
	l = r->link;
	r->w = depth;
	r->p = path;
	set_link_depth(r->link, -1, depth + 1);
	while (l)
	{
		next = *(t_room**)l->content;
		if ((next->w > depth && next->p == -1) || next->type == 1)
		{
			if (bfs(next, path, depth + 1, debug) == 1)
				return (1);
		}
		l = l->next;
	}
	if (debug)
		ft_printf("BFS: LEAVING %s\n", r->name);
	r->w = -1;
	r->p = -1;
	return (0);
}

int	path_init(t_lm *lm)
{
	int		path;
	t_list	*l;

	path = 0;
	l = lm->r_end->link;
	set_link_depth(l, -1, 1);
	while (l)
	{
		if (bfs(*(t_room**)(l->content), path + 1, 1, lm->debug))
			++path;
		l = l->next;
	}
	if (lm->debug)
		ft_printf("PATH_INIT: %d path(s) finded with bfs !\n", path);
	return (path);
}
