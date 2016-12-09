/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdetach_last.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 12:38:03 by mdos-san          #+#    #+#             */
/*   Updated: 2016/12/09 12:38:27 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_lstdetach_last(t_list *l)
{
	t_list	*c;

	c = l;
	while (c)
	{
		if (c->next && !c->next->next)
			c->next = NULL;
		c = c->next;
	}
}
