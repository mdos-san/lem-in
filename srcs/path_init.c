/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 17:54:31 by mdos-san          #+#    #+#             */
/*   Updated: 2017/01/07 18:02:10 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	if (r->type == 1)
		return ((r->type == 1) ? 1 : 0);
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
	r->w = -1;
	r->p = -1;
	return (0);
}

int			path_init(t_lm *lm)
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
	return (path);
}
