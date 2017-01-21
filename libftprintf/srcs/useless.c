/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useless.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:50:28 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/21 23:04:01 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	find_alpha(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isalpha(s[i]))
			break ;
		++i;
	}
	return (i);
}

void		useless(t_flag *flag, int *r)
{
	int	start;
	int	nb;

	start = find_alpha(flag->param);
	nb = flag->width - ft_strlen(flag->param + start + 1);
	(flag->flag['-'] == 0 && !flag->flag['0']) ? print_width(nb, r) : 0;
	(flag->flag['0']) ? print_width_z(nb, r) : 0;
	ft_putstr(flag->param + start);
	*r += ft_strlen(flag->param + start);
	(flag->flag['-'] == 1 && !flag->flag['0']) ? print_width(nb, r) : 0;
}
