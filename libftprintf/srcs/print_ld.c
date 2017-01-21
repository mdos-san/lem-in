/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:38:23 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/22 06:12:06 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_ltoa(long l)
{
	char	buf[257];
	int		i;
	char	n;

	i = 0;
	n = (l < 0) ? -1 : 1;
	ft_bzero(buf, 257);
	if (l == 0)
		return (ft_strdup("0"));
	while (l != 0)
	{
		buf[255 - i] = (l % 10) * n + 48;
		l /= 10;
		++i;
	}
	(n == -1) ? (buf[255 - i] = '-') : --i;
	return (ft_strdup(buf + 255 - i));
}

static void	get_width(t_flag *flag, char *arr, int *nb, long in)
{
	*nb = 0;
	if (flag->width > flag->precision)
	{
		*nb = (flag->precision > (int)ft_strlen(arr))
		? (int)(flag->width - ft_strlen(arr) - flag->precision + ft_strlen(arr))
		: (int)(flag->width - ft_strlen(arr));
		*nb += (flag->p_given && !flag->precision && !in) ? ft_strlen(arr) : 0;
	}
}

static void	flag_space(t_flag *flag, long in, int *nb, int *r)
{
	(flag->flag[' '] && !flag->flag['+'] && !flag->flag['-'] && in > 0
	&& !flag->width && !flag->precision && ++*r) ? ft_putchar(' ') : 0;
	if (flag->flag[' '] && in == 0)
	{
		ft_putchar(' ');
		++*r;
		--*nb;
	}
}

void		print_ld(t_flag *flag, int *r)
{
	char		*arr;
	int			i;
	int			nb;
	int			n;
	long		in;

	i = 0;
	in = va_arg(flag->arg, long);
	arr = ft_ltoa(in);
	n = (arr[0] == '-') ? 1 : 0;
	get_width(flag, arr, &nb, in);
	flag_space(flag, in, &nb, r);
	(flag->flag['+'] == 1 && in >= 0) ? --nb : 0;
	(flag->flag['-'] == 0 && (!flag->flag['0'] || flag->precision)
	&& flag->width - n > flag->precision) ? print_width(nb, r) : 0;
	(flag->flag['+'] == 1 && in >= 0 && ++*r) ? ft_putchar('+') : 0;
	(n == 1 && ++*r) ? ft_putchar('-') : 0;
	(flag->flag['-'] == 0 && flag->flag['0'] && !flag->precision)
		? print_width_z(nb, r) : 0;
	precision(flag->precision - (int)ft_strlen(arr) + n, r);
	(flag->p_given && !flag->precision && !in) ? 0 : ft_putstr(arr + n);
	*r += (flag->p_given && !flag->precision && !in) ? 0 : ft_strlen(arr + n);
	(flag->flag['-'] == 1) ? print_width(nb, r) : 0;
	ft_strdel(&arr);
}
