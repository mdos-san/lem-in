/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hhu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:32:54 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/22 05:06:48 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_ltoa(unsigned char l)
{
	char	buf[21];
	int		i;

	i = 0;
	ft_bzero(buf, 21);
	if (l == 0)
		return (ft_strdup("0"));
	while (l != 0)
	{
		buf[19 - i] = (l % 10) + 48;
		l /= 10;
		++i;
	}
	--i;
	return (ft_strdup(buf + 19 - i));
}

static void	get_width(t_flag *flag, char *arr, int *nb, unsigned char in)
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

void		print_hhu(t_flag *flag, int *r)
{
	char			*arr;
	int				i;
	int				nb;
	int				n;
	unsigned char	in;

	i = 0;
	in = (unsigned char)va_arg(flag->arg, int);
	arr = ft_ltoa(in);
	n = (arr[0] == '-') ? 1 : 0;
	get_width(flag, arr, &nb, in);
	(flag->flag['-'] == 0 && (!flag->flag['0'] || flag->precision)
	&& flag->width - n > flag->precision) ? print_width(nb, r) : 0;
	(n == 1 && ++*r) ? ft_putchar('-') : 0;
	(flag->flag['-'] == 0 && flag->flag['0'] && !flag->precision)
		? print_width_z(nb, r) : 0;
	precision(flag->precision - (int)ft_strlen(arr) + n, r);
	(flag->p_given && !flag->precision && !in) ? 0 : ft_putstr(arr + n);
	*r += (flag->p_given && !flag->precision && !in) ? 0 : ft_strlen(arr + n);
	(flag->flag['-'] == 1) ? print_width(nb, r) : 0;
}
