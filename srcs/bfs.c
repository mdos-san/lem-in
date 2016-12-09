/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 18:35:16 by mdos-san          #+#    #+#             */
/*   Updated: 2016/12/09 21:30:15 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	bfs(t_room *act, int depth)
{
	static	int reach_start = 0;
	int	init;
	t_list	*l;
	t_room	*r;

	init = 0;
	act->w = depth;
	l = act->link;
	ft_printf("now on room %s of the path %d with w %d \n", act->name, act->p, act->w);
	while (l)
	{
		r = *(t_room**)l->content;
		if (!reach_start)
		{
			if (r->type != 1 && r->p == -1)
			{
				r->p = (act->type == 2) ? ++init : act->p;
				ft_printf("\troom %s assigned to path %d\n", r->name, r->p);
			}
		}
		l = l->next;
	}
	l = act->link;
	while (l)
	{
		r = *(t_room**)l->content;
		if (reach_start)
		{
			if (r->w == -1 && r->p == act->p)
			{
				r->p = -1;
				ft_printf("Set room %s path to -1\n", r->name);
			}
			else
				ft_printf("Doing nothing on room %s w %d\n", r->name, r->w);
		}
		if (!reach_start)
		{
			if (r->type != 1 && r->w == -1)
				bfs(r, depth + 1);
			else if (r->type == 1)
				reach_start = 1;
			if (act->type == 2)
				reach_start = 0;
		}
		l = l->next;
	}
}
