/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pnt_fct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 05:13:07 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/22 05:22:27 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_useless(t_ftpf *new)
{
	int i;

	i = 0;
	while (i < 256)
	{
		new->hh[i] = useless;
		new->h[i] = useless;
		new->fct[i] = useless;
		new->l[i] = useless;
		new->z[i] = useless;
		new->j[i] = useless;
		++i;
	}
}

void	init_pz(t_ftpf *new)
{
	new->z['d'] = print_zd;
	new->z['D'] = print_zd;
	new->z['i'] = print_zd;
	new->z['u'] = print_zu;
	new->z['U'] = print_zu;
	new->z['o'] = print_zo;
	new->z['O'] = print_zo;
	new->z['x'] = print_zx;
	new->z['X'] = print_zx;
	new->l['p'] = print_p;
	new->l['P'] = print_p;
	new->fct['%'] = print_percent;
}

void	init_fct(t_ftpf *new)
{
	new->fct['D'] = print_ld;
	new->fct['I'] = print_ld;
	new->fct['C'] = print_lc;
	new->fct['S'] = print_ls;
	new->fct['O'] = print_lo;
	new->fct['U'] = print_lu;
	new->fct['c'] = print_c;
	new->fct['s'] = print_s;
	new->fct['d'] = print_d;
	new->fct['i'] = print_d;
	new->fct['o'] = print_o;
	new->fct['p'] = print_p;
	new->fct['P'] = print_p;
	new->fct['x'] = print_x;
	new->fct['X'] = print_x;
	new->fct['u'] = print_u;
}

void	init_lj(t_ftpf *new)
{
	new->j['d'] = print_jd;
	new->j['D'] = print_jd;
	new->j['i'] = print_jd;
	new->j['x'] = print_jx;
	new->j['X'] = print_jx;
	new->j['u'] = print_ju;
	new->j['U'] = print_ju;
	new->j['o'] = print_jo;
	new->j['O'] = print_jo;
	new->l['d'] = print_ld;
	new->l['D'] = print_ld;
	new->l['i'] = print_ld;
	new->l['I'] = print_ld;
	new->l['c'] = print_lc;
	new->l['C'] = print_lc;
	new->l['s'] = print_ls;
	new->l['S'] = print_ls;
	new->l['o'] = print_lo;
	new->l['O'] = print_lo;
	new->l['x'] = print_lx;
	new->l['X'] = print_lx;
	new->l['u'] = print_lu;
	new->l['U'] = print_lu;
}

void	init_hhhl(t_ftpf *new)
{
	new->hh['s'] = print_ls;
	new->hh['S'] = print_ls;
	new->hh['c'] = print_lc;
	new->hh['C'] = print_lc;
	new->hh['d'] = print_hhd;
	new->hh['D'] = print_hu;
	new->hh['i'] = print_hhd;
	new->hh['o'] = print_hho;
	new->hh['O'] = print_ho;
	new->hh['x'] = print_hhx;
	new->hh['X'] = print_hhx;
	new->hh['u'] = print_hhu;
	new->hh['U'] = print_hu;
	new->h['d'] = print_hd;
	new->h['D'] = print_hud;
	new->h['i'] = print_hd;
	new->h['I'] = print_hd;
	new->h['o'] = print_ho;
	new->h['O'] = print_ho;
	new->h['x'] = print_hx;
	new->h['X'] = print_hx;
	new->h['u'] = print_hu;
	new->h['U'] = print_huu;
}
