/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 09:57:42 by mdos-san          #+#    #+#             */
/*   Updated: 2017/01/23 15:07:43 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_list	*get_end(t_list *rooms)
{
	t_list	*c;
	t_room	*r;

	c = rooms;
	while (c)
	{
		r = (t_room*)c->content;
		if (r->type == 2)
			return (c);
		c = c->next;
	}
	return (NULL);
}

static t_list	*get_start(t_list *rooms)
{
	t_list	*c;
	t_room	*r;

	c = rooms;
	while (c)
	{
		r = (t_room*)c->content;
		if (r->type == 1)
			return (c);
		c = c->next;
	}
	return (NULL);
}

void			lm_start(t_lm *lm)
{
	t_list	*l;

	l = get_end(lm->rooms);
	lm->r_end = (t_room*)l->content;
	lm->nb_path = path_init(lm);
	if (lm->nb_path == 0)
		error(lm);
	lm->r_end->p = 1;
	lm->r_end->w = -1;
	l = get_start(lm->rooms);
	lm->start = (t_room*)l->content;
	ft_putendl(lm->input);
	resolve(lm);
}
