/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 14:03:40 by mdos-san          #+#    #+#             */
/*   Updated: 2017/01/20 14:35:54 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	get_link_assign(t_lm *lm, char **gnl_buf, char **r1, char **r2)
{
	lm->input = ft_strjoin(lm->input, *gnl_buf);
	lm->input = ft_strjoin(lm->input, "\n");
	*r1 = ft_strdup_to_char(*gnl_buf, '-');
	*r2 = ft_strdup(ft_strchr(*gnl_buf, '-') + 1);
	if (add_link(find_room(lm, *r1), find_room(lm, *r2)) == 0)
		error(lm);
	ft_strdel(gnl_buf);
	ft_strdel(r1);
	ft_strdel(r2);
}

void		get_link(t_lm *lm, char *str)
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
				get_link_assign(lm, &gnl_buf, &r1, &r2);
			else if (gnl_buf[0] == '#')
			{
				lm->input = ft_strjoin(lm->input, gnl_buf);
				lm->input = ft_strjoin(lm->input, "\n");
			}
		}
	}
	else
		error(lm);
}

static int	get_room_assign(t_lm *lm, char **array, t_room *r, char *next_type)
{
	lm->input = ft_strjoin(lm->input, *array);
	lm->input = ft_strjoin(lm->input, "\n");
	(ft_strcmp(*array, "##start") == 0) ? (*next_type = 1) : 0;
	(ft_strcmp(*array, "##end") == 0) ? (*next_type = 2) : 0;
	if ((lm->s_given > 1 || lm->e_given > 1))
		error(lm);
	(ft_strcmp(*array, "##start") == 0) ? (++lm->s_given) : 0;
	(ft_strcmp(*array, "##end") == 0) ? (++lm->e_given) : 0;
	if (good_format(*array))
	{
		r->input = ft_strdup(*array);
		r->name = ft_strdup_to_char(*array, ' ');
		r->type = *next_type;
		r->w = -1;
		r->p = -1;
		r->link = NULL;
		(lm->rooms == NULL) ? (lm->rooms = ft_lstnew(r, sizeof(t_room)))
			: ft_lstpushb(lm->rooms, r, sizeof(t_room));
		ft_strdel(array);
		*next_type = 0;
	}
	else if ((*array)[0] != '#')
		return (1);
	return (0);
}

void		get_room(t_lm *lm)
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
		if (get_room_assign(lm, &array, r, &next_type))
			break ;
	}
	get_link(lm, array);
}
