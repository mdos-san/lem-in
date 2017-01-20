/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 09:57:42 by mdos-san          #+#    #+#             */
/*   Updated: 2017/01/20 14:37:19 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		debug(t_lm *lm)
{
	t_list	*l;
	t_room	*r;
	t_list	*l2;

	l = lm->rooms;
	ft_printf("Debug: true\n");
	ft_printf("nb_ant: %d\n", lm->nb_ant);
	while (l)
	{
		r = (t_room*)(l->content);
		ft_printf("\n###|room: %s\n", (r->input));
		ft_printf("-----name: %s\n", (r->name));
		ft_printf("-----type: %d\n", (r->type));
		ft_printf("-----weig: %d\n", (r->w));
		ft_printf("-----path: %d\n", (r->p));
		l2 = r->link;
		while (l2)
		{
			r = *(t_room**)(l2->content);
			ft_printf("Linked_to: %s\n", (r->name));
			l2 = l2->next;
		}
		l = l->next;
	}
	ft_printf("%d path(s) finded !\n", lm->nb_path);
}

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

t_list			*ft_lstdup(t_list *l)
{
	t_list	*ret;

	ret = NULL;
	while (l)
	{
		(ret) ? ft_lstpushb(ret, l->content, l->content_size)
			: (ret = ft_lstnew(l->content, l->content_size));
		l = l->next;
	}
	return (ret);
}

void			lm_start(t_lm *lm)
{
	t_list	*l;

	l = get_end(lm->rooms);
	lm->r_end = (t_room*)l->content;
	lm->nb_path = path_init(lm);
	if (lm->nb_path == 0)
		error(lm);
	(lm->debug) ? debug(lm) : 0;
	lm->r_end->p = 1;
	lm->r_end->w = -1;
	l = get_start(lm->rooms);
	lm->start = (t_room*)l->content;
	ft_putendl(lm->input);
	resolve(lm);
	exit(0);
}
