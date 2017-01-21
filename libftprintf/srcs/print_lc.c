/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:38:10 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/21 22:57:45 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_lc(t_flag *flag, int *r)
{
	int	nb;
	int	ca;

	ca = va_arg(flag->arg, int);
	nb = flag->width;
	--nb;
	(ca > 127) ? --nb : 0;
	(ca > 2047) ? --nb : 0;
	(ca > 65535) ? --nb : 0;
	(flag->flag['-'] == 0) ? print_width(nb, r) : 0;
	*r += ft_putwchar(ca);
	(flag->flag['-'] == 1) ? print_width(nb, r) : 0;
}
