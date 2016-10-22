/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_zx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:49:10 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/22 03:08:29 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*convert_hexa(unsigned long long n, char up)
{
	int		i;
	int		mod;
	char	buf[65];

	i = 0;
	ft_bzero(buf, 65);
	if (n == 0)
	{
		buf[0] = '0';
		return (ft_strdup(buf));
	}
	while (n != 0)
	{
		mod = n % 16;
		if (mod <= 9)
			buf[63 - i] = mod + 48;
		else
		{
			mod -= 10;
			buf[63 - i] = mod + 97 - (32 * up);
		}
		n /= 16;
		++i;
	}
	return (ft_strdup(buf + 63 - i + 1));
}

void		print_zx(t_flag *flag, int *r)
{
	char				*arr;
	int					w;
	int					p;
	int					i;
	unsigned long long	ull;

	i = -1;
	ull = va_arg(flag->arg, unsigned long long);
	arr = convert_hexa(ull, flag->uppercase);
	init_xpw(flag, arr, &p, &w);
	(flag->flag['-'] == 0 && flag->flag['0'] == 0) ? print_width(w, r) : 0;
	(flag->flag['#'] && !flag->uppercase && ull > 0 && (*r += 2))
		? ft_putstr("0x") : 0;
	(flag->flag['#'] && flag->uppercase && ull > 0 && (*r += 2))
		? ft_putstr("0X") : 0;
	(flag->flag['-'] == 0 && flag->flag['0'] == 1) ? print_width_z(w, r) : 0;
	precision(p, r);
	(flag->p_given && flag->precision == 0) ? 0 : ft_putstr(arr);
	*r += (flag->p_given && flag->precision == 0) ? 0 : ft_strlen(arr);
	(flag->flag['-'] == 1) ? print_width(w, r) : 0;
	ft_strdel(&arr);
}
