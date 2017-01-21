/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:39:09 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/22 03:36:01 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	count(int *arr, int *tab, int pre)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (count < pre)
	{
		++count;
		count += (arr[i] > 127) ? 1 : 0;
		count += (arr[i] > 2047) ? 1 : 0;
		count += (arr[i] > 65535) ? 1 : 0;
		if (count > pre)
		{
			tab[i] = 0;
			break ;
		}
		tab[i] = arr[i];
		++i;
	}
}

static int	*int_arr_dup(int *arr, int pre)
{
	int	nbr;
	int	to_go;
	int	*tab;

	nbr = 0;
	to_go = 0;
	while (arr[nbr])
	{
		++to_go;
		to_go += (arr[nbr] > 127) ? 1 : 0;
		to_go += (arr[nbr] > 2047) ? 1 : 0;
		to_go += (arr[nbr] > 65535) ? 1 : 0;
		++nbr;
	}
	tab = (int*)malloc(sizeof(int) * (nbr + 1));
	ft_bzero(tab, sizeof(int) * (nbr + 1));
	pre = (pre <= 0) ? to_go : pre;
	count(arr, tab, pre);
	return (tab);
}

static int	int_arr_len(int *arr)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (arr[i])
	{
		ret++;
		ret += (arr[i] > 127) ? 1 : 0;
		ret += (arr[i] > 2047) ? 1 : 0;
		ret += (arr[i] > 65535) ? 1 : 0;
		++i;
	}
	return (ret);
}

static int	check_null(t_flag *flag, int *st, int *r)
{
	if (st == NULL && flag->width == 0)
	{
		ft_putstr("(null)");
		*r += 6;
		return (1);
	}
	return (0);
}

void		print_ls(t_flag *flag, int *r)
{
	int		*arr;
	int		nb;
	int		*st;

	nb = 0;
	st = va_arg(flag->arg, int *);
	if (!check_null(flag, st, r))
	{
		arr = int_arr_dup(st, flag->precision);
		nb = (flag->width > flag->precision)
			? flag->width - int_arr_len(arr) : 0;
		width(flag, nb, r);
		if (!(flag->p_given && !flag->precision))
		{
			*r += ft_putwstr(arr);
			(flag->flag['-'] == 1) ? print_width(nb, r) : 0;
		}
		else
			width(flag, flag->width, r);
		(flag->flag['-'] && flag->flag['0']) ? print_width_z(nb, r) : 0;
		(arr) ? free(arr) : 0;
	}
}
