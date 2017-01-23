/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:42:36 by mdos-san          #+#    #+#             */
/*   Updated: 2017/01/23 15:16:01 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		room_check_name(t_lm *lm, char *str)
{
	t_list	*l;
	t_room	*r;

	l = lm->rooms;
	while (l)
	{
		r = (t_room*)l->content;
		if (ft_strcmp(r->name, str) == 0)
			return (1);
		l = l->next;
	}
	return (0);
}

int		room_check_coord(t_lm *lm, int x, int y)
{
	t_list	*l;
	t_room	*r;

	l = lm->rooms;
	while (l)
	{
		r = (t_room*)l->content;
		if (r->x == x && r->y == y)
			return (1);
		l = l->next;
	}
	return (0);
}

void	new_room(t_lm *lm, char *array, char type)
{
	t_room	r;

	r.input = ft_strdup(array);
	r.name = ft_strdup_to_char(array, ' ');
	r.x = ft_atoi(ft_strchr(array, ' '));
	r.y = ft_atoi(ft_strchr(ft_strchr(array, ' ') + 1, ' '));
	if (room_check_name(lm, r.name) || room_check_coord(lm, r.x, r.y))
		error(lm);
	r.type = type;
	r.w = -1;
	r.p = -1;
	r.link = NULL;
	(lm->rooms == NULL) ? (lm->rooms = ft_lstnew(&r, sizeof(t_room)))
		: ft_lstpushb(lm->rooms, &r, sizeof(t_room));
}
