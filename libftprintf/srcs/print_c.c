/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:27:55 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/21 22:51:16 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_c(t_flag *flag, int *r)
{
	(flag->flag['-'] == 0 && !flag->flag['0'])
		? print_width(flag->width - 1, r) : 0;
	(flag->flag['-'] == 0 && flag->flag['0'])
		? print_width_z(flag->width - 1, r) : 0;
	ft_putchar((char)va_arg(flag->arg, int));
	++*r;
	(flag->flag['-'] == 1) ? print_width(flag->width - 1, r) : 0;
}
