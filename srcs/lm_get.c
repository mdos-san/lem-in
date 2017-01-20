/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 09:43:00 by mdos-san          #+#    #+#             */
/*   Updated: 2017/01/20 13:49:10 by mdos-san         ###   ########.fr       */
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
		ft_printf("|room: %s\n", (r->input));
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

static int		good_format(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			++count;
		++i;
	}
	if (count == 2)
		return (1);
	else
		return (0);
}

static t_room	*find_room(t_lm *lm, char *name)
{
	t_list	*cursor;
	t_room	*room;

	cursor = lm->rooms;
	while (cursor)
	{
		room = (t_room*)(cursor->content);
		if (ft_strcmp(room->name, name) == 0)
			return (room);
		cursor = cursor->next;
	}
	return (NULL);
}

static int		add_link(t_room *r1, t_room *r2)
{
	if (!r1 || !r2)
		return (0);
	(r1->link) ? ft_lstpushb(r1->link, &r2, sizeof(t_room*))
		: (r1->link = ft_lstnew(&r2, sizeof(t_room*)));
	(r2->link) ? ft_lstpushb(r2->link, &r1, sizeof(t_room*))
		: (r2->link = ft_lstnew(&r1, sizeof(t_room*)));
	return (1);
}

static void		get_link(t_lm *lm, char *str)
{
	char	*gnl_buf;
	char	*r1;
	char	*r2;

	gnl_buf = NULL;
	r1 = ft_strdup_to_char(str, '-');
	r2 = ft_strdup(((ft_strchr(str, '-')) ? ft_strchr(str, '-') + 1 : NULL));
	if (add_link(find_room(lm, r1), find_room(lm, r2)) == 1 || str[0] == '#')
	{
		ft_strdel(&r1);
		ft_strdel(&r2);
		while (get_next_line(0, &gnl_buf) > 0)
		{
			if (gnl_buf[0] != '#')
			{
				lm->input = ft_strjoin(lm->input, gnl_buf);
				lm->input = ft_strjoin(lm->input, "\n");
				r1 = ft_strdup_to_char(gnl_buf, '-');
				r2 = ft_strdup(ft_strchr(gnl_buf, '-') + 1);
				if (add_link(find_room(lm, r1), find_room(lm, r2)) == 0)
				{
					ft_printf("ERROR\n");
					exit(0);
				}
				ft_strdel(&gnl_buf);
				ft_strdel(&r1);
				ft_strdel(&r2);
			}
			else if (gnl_buf[0] == '#')
			{
				lm->input = ft_strjoin(lm->input, gnl_buf);
				lm->input = ft_strjoin(lm->input, "\n");
			}
		}
	}
	else
	{
		ft_printf("ERROR\n");
		exit(0);
	}
}

static void		get_room(t_lm *lm)
{
	char	*array;
	t_room	*r;
	char	next_type;

	array = NULL;
	lm->rooms = NULL;
	next_type = 0;
	r = (t_room *)malloc(sizeof(t_room));
	while (get_next_line(0, &array) > 0)
	{
		lm->input = ft_strjoin(lm->input, array);
		lm->input = ft_strjoin(lm->input, "\n");
		(ft_strcmp(array, "##start") == 0) ? (next_type = 1) : 0;
		(ft_strcmp(array, "##end") == 0) ? (next_type = 2) : 0;
		if ((lm->s_given > 1 || lm->e_given > 1))
		{
			ft_printf("ERROR");
			exit(0);
		}
		(ft_strcmp(array, "##start") == 0) ? (++lm->s_given) : 0;
		(ft_strcmp(array, "##end") == 0) ? (++lm->e_given) : 0;
		if (good_format(array))
		{
			r->input = ft_strdup(array);
			r->name = ft_strdup_to_char(array, ' ');
			r->type = next_type;
			r->w = -1;
			r->p = -1;
			r->link = NULL;
			(lm->rooms == NULL) ? (lm->rooms = ft_lstnew(r, sizeof(t_room)))
				: ft_lstpushb(lm->rooms, r, sizeof(t_room));
			ft_strdel(&array);
			next_type = 0;
		}
		else if (array[0] != '#')
			break ;
	}
	get_link(lm, array);
}

t_lm			lm_get(void)
{
	t_lm	new;
	char	*array;

	new.debug = 0;
	new.path = NULL;
	new.path_tmp = NULL;
	new.path_length = 0;
	new.tmp_length = 0;
	new.s_given = 0;
	new.e_given = 0;
	get_next_line(0, &array);
	new.input = ft_strjoin(array, "\n");
	new.nb_ant = ft_atoi(array);
	if (new.nb_ant <= 0)
	{
		ft_printf("ERROR");
		exit(0);
	}
	get_room(&new);
	if (new.debug)
		debug(&new);
	return (new);
}
