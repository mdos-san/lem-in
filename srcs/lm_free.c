/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:28:45 by mdos-san          #+#    #+#             */
/*   Updated: 2017/01/23 15:49:59 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	del(void *elem, size_t size)
{
	t_room *r;
	t_list *l;
	t_list *tmp;

	r = (t_room*)elem;
	l = r->link;
	while (l)
	{
		tmp = l->next;
		free(l);
		l = tmp;
	}
	if (r)
		free(r);
	(void)size;
}

void	lm_free(t_lm *lm)
{
	if (lm->rooms)
		ft_lstdel(&lm->rooms, del);
}
