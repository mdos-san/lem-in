/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 09:43:00 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/22 11:41:55 by mdos-san         ###   ########.fr       */
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
		ft_printf("|room: %s\n", (*(t_room*)(l->content)).input);
		ft_printf("-----type: %d\n", (*(t_room*)(l->content)).type);
		l = l->next;
	}
}

static int	good_format(char *str)
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

static void	get_link(t_lm *lm, char *str)
{
	(void)lm;
	(void)str;
}

static void	get_room(t_lm *lm)
{
	char	*array;
	t_room	r;
	char	next_type;

	array = NULL;
	lm->rooms = NULL;
	next_type = 0;
	while (get_next_line(0, &array) > 0)
	{
		(ft_strcmp(array, "##start") == 0) ? (next_type = 1) : 0;
		(ft_strcmp(array, "##end") == 0) ? (next_type = 2) : 0;
		if (good_format(array))
		{
			r.input = ft_strdup(array);
			r.type = next_type;
			(lm->rooms == NULL)
				? (lm->rooms = ft_lstnew((void*)&r, sizeof(r)))
				: ft_lstpushb(lm->rooms, (void*)&r, sizeof(r));
			ft_strdel(&array);
			next_type = 0;
		}
		else if (array[0] != '#')
			break ;
	}
	get_link(lm, array);
}

t_lm		lm_get(void)
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
