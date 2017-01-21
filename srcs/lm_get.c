/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 09:43:00 by mdos-san          #+#    #+#             */
/*   Updated: 2017/01/21 16:58:03 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		good_format(char *str)
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

t_room	*find_room(t_lm *lm, char *name)
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

int		add_link(t_room *r1, t_room *r2)
{
	if (!r1 || !r2)
		return (0);
	(r1->link) ? ft_lstpushb(r1->link, &r2, sizeof(t_room *))
		: (r1->link = ft_lstnew(&r2, sizeof(t_room *)));
	(r2->link) ? ft_lstpushb(r2->link, &r1, sizeof(t_room *))
		: (r2->link = ft_lstnew(&r1, sizeof(t_room *)));
	return (1);
}

t_lm	lm_get(void)
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
	ft_strdel(&array);
	if (new.nb_ant <= 0)
		error(&new);
	get_room(&new);
	return (new);
}
