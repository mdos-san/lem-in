/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:26:28 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/22 06:16:01 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ftpf_del(t_ftpf **addr)
{
	if (*addr)
	{
		ft_strdel(&(*addr)->input);
		ft_strdel(&(*addr)->flag.mod);
		str_array_del(&(*addr)->params);
		free(*addr);
		*addr = NULL;
	}
}
