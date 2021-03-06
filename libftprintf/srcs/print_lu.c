/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:39:42 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/22 06:13:28 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*convert_ui(unsigned long ui)
{
	char	buf[257];
	int		i;
	int		mod;

	i = 0;
	ft_bzero(buf, 257);
	if (ui == 0)
		return (ft_strdup("0"));
	while (ui != 0)
	{
		mod = ui % 10;
		buf[255 - i] = mod + 48;
		ui /= 10;
		i += (ui != 0) ? 1 : 0;
	}
	return (ft_strdup(buf + 255 - i));
}

void		print_lu(t_flag *flag, int *r)
{
	char			*arr;
	int				w;
	int				p;
	int				i;
	unsigned long	ul;

	i = -1;
	ul = va_arg(flag->arg, unsigned long);
	arr = convert_ui(ul);
	p = flag->precision - ft_strlen(arr);
	p = (p < 0) ? 0 : p;
	p = (p == 0 && flag->flag['#'] == 1) ? 1 : p;
	w = flag->width - ft_strlen(arr) - p;
	w = (w < 0) ? 0 : w;
	w = (flag->p_given && flag->precision == 0) ? flag->width : w;
	(!flag->flag['-'] && !flag->flag['0']) ? print_width(w, r) : 0;
	(!flag->flag['-'] && flag->flag['0']) ? print_width_z(w, r) : 0;
	precision(p, r);
	ft_putstr(arr);
	*r += ft_strlen(arr);
	(flag->flag['-'] == 1) ? print_width(w, r) : 0;
	ft_strdel(&arr);
}
