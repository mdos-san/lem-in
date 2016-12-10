/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 09:57:42 by mdos-san          #+#    #+#             */
/*   Updated: 2016/12/09 20:29:08 by mdos-san         ###   ########.fr       */
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

static int		elem_exist(t_list *l, char *str)
{
	t_list	*c;
	t_room	*r;
	int		i;

	c = l;
	i = 0;
	while (c)
	{
		r = (t_room*)c->content;
		if (ft_strcmp(r->name, str) == 0)
			++i;
		if (i == 2)
			return (1);
		c = c->next;
	}
	return (0);
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

int				find_path(t_lm *lm, t_list *act)
{
	t_room	*r_a;
	t_list	*l;
	int		ret;

	r_a = (t_room*)act->content;
	l = r_a->link;
	(lm->path) ? ft_lstpushb(lm->path, r_a, sizeof(t_room))
		: (lm->path = ft_lstnew(r_a, sizeof(t_room)));
	++lm->path_length;
	if (r_a->type == 2)
		return (1);
	if (elem_exist(lm->path, r_a->name))
		return (0);
	while (l)
	{
		ret = find_path(lm, l);
		if (ret == 0)
		{
			ft_lstdetach_last(lm->path);
			--lm->path_length;
		}
		else if (ret == 1 &&
			(lm->path_length < lm->tmp_length || lm->tmp_length == 0))
		{
			lm->path_tmp = ft_lstdup(lm->path);
			lm->tmp_length = lm->path_length;
			return (0);
		}
		l = l->next;
	}
	return (0);
}

char			*get_room_of_path(t_list *l, int nb)
{
	t_list	*c;
	t_room	*r;
	int		i;

	i = 0;
	c = l;
	while (c)
	{
		if (i == nb)
		{
			r = (t_room*)c->content;
			return (r->name);
		}
		++i;
		c = c->next;
	}
	return (NULL);
}

int				ft_abs(int n)
{
	return ((n > 0) ? n : -1);
}

void			print_solution(t_lm *lm)
{
	int		i;
	int		j;
	int		c;
	char	*str;

	i = 1;
	while (i <= lm->nb_ant + lm->tmp_length)
	{
		j = 1;
		c = 0;
		while (j < lm->tmp_length)
		{
			if (0 < i - j + 1 && i - j + 1 <= lm->nb_ant)
			{
				if (c > 0)
					ft_printf(" ");
				str = get_room_of_path(lm->path_tmp, j);
				if (str)
					ft_printf("L%d-%s", i - j + 1, str);
				++c;
			}
			++j;
		}
		if (c > 0)
			ft_putchar('\n');
		++i;
	}
}

void			lm_start(t_lm *lm)
{
	t_list	*l;

	l = get_end(lm->rooms);
	bfs((t_room *)l->content, 0);
	debug(lm);
	l = get_start(lm->rooms);
	lm->start_link = l;
	lm->nb_path = count_path(((t_room*)l->content)->link);
	ft_printf("%d path(s) finded !\n", lm->nb_path);
	resolve(lm);
	exit(0);

	l = get_start(lm->rooms);
	find_path(lm, l);
	if (lm->path_length == 0)
		ft_printf("ERROR");
	else
	{
		ft_putendl(lm->input);
		print_solution(lm);
	}
	(lm->debug) ? debug(lm) : 0;
}
