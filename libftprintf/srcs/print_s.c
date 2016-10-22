/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:42:05 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/22 05:47:23 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	check_null(t_flag *flag, char *st, int *r)
{
	if (st == NULL && flag->width == 0)
	{
		ft_putstr("(null)");
		*r += 6;
		return (1);
	}
	return (0);
}

static void	s_width(t_flag *flag, char *str, int *r)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	if (flag->width > 0)
	{
		nb = flag->width - ft_strlen(str);
		nb = (flag->p_given && !flag->precision) ? flag->width : nb;
		while (i < nb)
		{
			(flag->flag['0']) ? ft_putchar('0') : ft_putchar(' ');
			++*r;
			++i;
		}
	}
}

void		print_s(t_flag *flag, int *r)
{
	char	tmp;
	char	*str;
	int		nb;
	char	*ss;

	ss = va_arg(flag->arg, char *);
	if (!check_null(flag, ss, r))
	{
		str = ft_strdup(ss);
		nb = 0;
		if (flag->precision > 0)
		{
			tmp = str[flag->precision];
			str[flag->precision] = '\0';
		}
		(!flag->flag['-']) ? s_width(flag, str, r) : 0;
		if ((flag->p_given && flag->precision) || !flag->p_given)
		{
			(ss != NULL) ? ft_putstr(str) : ft_putstr("(null)");
			*r += ft_strlen(str);
		}
		(flag->flag['-']) ? s_width(flag, str, r) : 0;
		(flag->precision > 0) ? (str[flag->precision] = tmp) : 0;
		ft_strdel(&str);
	}
}
