/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:42:40 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/22 03:25:59 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_xpw(t_flag *flag, char *arr, int *p, int *w)
{
	*p = flag->precision - ft_strlen(arr);
	*p = (*p < 0) ? 0 : *p;
	*w = flag->width - ft_strlen(arr) - *p;
	*w = (flag->flag['#'] == 1) ? *w - 2 : *w;
	*w = (*w < 0) ? 0 : *w;
	*w = (flag->p_given && flag->precision == 0) ? flag->width : *w;
}

void	print_width(int nb, int *r)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		ft_putchar(' ');
		++*r;
		++i;
	}
}

void	print_width_z(int nb, int *r)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		ft_putchar('0');
		++*r;
		++i;
	}
}

void	precision(int p, int *r)
{
	int	i;

	i = 0;
	while (i < p)
	{
		ft_putchar('0');
		++*r;
		++i;
	}
}

void	width(t_flag *flag, int w, int *r)
{
	(flag->flag['-'] == 0 && flag->flag['0'])
		? print_width_z(w, r) : 0;
	(flag->flag['-'] == 0 && !flag->flag['0'])
		? print_width(w, r) : 0;
}
