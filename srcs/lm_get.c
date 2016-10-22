/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 09:43:00 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/22 10:41:43 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	debug(t_lm *lm)
{
	t_list	*l;

	l = lm->rooms;
	ft_printf("Debug: true\n");
	ft_printf("nb_ant: %d\n", lm->nb_ant);
	while (l)
	{
		ft_printf("room: %s\n", (*(t_room*)(l->content)).input);
		l = l->next;
	}
}

static void	get_room(t_lm *lm)
{
	char	*array;
	t_room	r;

	array = NULL;
	lm->rooms = NULL;
	while (get_next_line(0, &array) > 0)
	{
		r.input = ft_strdup(array);
		(lm->rooms == NULL) ? (lm->rooms = ft_lstnew((void*)&r, sizeof(r)))
			: ft_lstpushb(lm->rooms, (void*)&r, sizeof(r));
		ft_strdel(&array);
	}
}

t_lm	lm_get(void)
{
	t_lm	new;
	char	*array;

	new.debug = 1;
	get_next_line(0, &array);
	new.nb_ant = ft_atoi(array);
	get_room(&new);
	if (new.debug)
		debug(&new);
	return (new);
}
