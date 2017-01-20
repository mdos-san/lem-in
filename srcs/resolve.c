/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 17:54:46 by mdos-san          #+#    #+#             */
/*   Updated: 2017/01/20 14:49:07 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static char	*get_room_of_path(t_room *ro, int p, int nb, int *end)
{
	t_list	*c;
	t_room	*r;
	int		i;

	i = 0;
	c = ro->link;
	if (ro->type == 2)
		++*end;
	if (nb == 0 || ro->type == 2)
	{
		return (ro->name);
	}
	while (c)
	{
		r = *(t_room**)c->content;
		if (((ro->w > r->w || ro->w == -1) && r->p == p) || r->type == 2)
			return (get_room_of_path(r, p, nb - 1, end));
		++i;
		c = c->next;
	}
	return (NULL);
}

static void	resolve_travel(t_lm *lm, int *i, int *j, char *str)
{
	*j = 1;
	++lm->turn;
	lm->lem = *i - *j + lm->nb_path;
	while (lm->lem > 0)
	{
		lm->lem = *i - *j + lm->nb_path;
		if (lm->end < lm->lem && lm->lem <= lm->nb_ant)
		{
			lm->resolve_path = (lm->lem % lm->nb_path) + 1;
			lm->depth = *j / (lm->nb_path) + 1;
			if (lm->lem % lm->nb_path == 1)
				--lm->depth;
			else if (lm->nb_path == 1)
				--lm->depth;
			str = get_room_of_path(lm->start, lm->resolve_path,
				lm->depth, &lm->nend);
			if (str)
				ft_printf("L%d-%s ", lm->lem, str);
		}
		++*j;
	}
	lm->end = lm->nend;
	ft_putchar('\n');
	*i += lm->nb_path;
}

void		resolve(t_lm *lm)
{
	int		i;
	int		j;
	char	*str;

	i = 1;
	lm->turn = 0;
	lm->end = 0;
	lm->nend = 0;
	str = NULL;
	while (lm->end < lm->nb_ant)
		resolve_travel(lm, &i, &j, str);
}
