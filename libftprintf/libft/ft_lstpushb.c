/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 15:08:11 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/17 15:12:07 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushb(t_list *lst, void *content, size_t content_size)
{
	if (lst->next != NULL)
		ft_lstpushb(lst->next, content, content_size);
	else
		lst->next = ft_lstnew(content, content_size);
}
