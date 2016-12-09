/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushb_cpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 12:38:12 by mdos-san          #+#    #+#             */
/*   Updated: 2016/12/09 19:29:07 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_lstpushb_cpy(t_list *lst, void *content, size_t content_size)
{
	if (lst->next != NULL)
		ft_lstpushb_cpy(lst->next, content, content_size);
	else
		lst->next = ft_lstnew_cpy(content, content_size);
}
