/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 20:27:18 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/22 05:22:44 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include "libft.h"

typedef struct		s_flag
{
	int				precision;
	int				width;
	char			flag[256];
	char			*mod;
	char			uppercase;
	char			p_given;
	va_list			arg;
	char			*param;
}					t_flag;

typedef struct		s_ftpf
{
	char			*input;
	int				nbr_param;
	char			**params;
	void			(*fct[256])(t_flag *flag, int *ret);
	void			(*l[256])(t_flag *flag, int *ret);
	void			(*h[256])(t_flag *flag, int *ret);
	void			(*hh[256])(t_flag *flag, int *ret);
	void			(*j[256])(t_flag *flag, int *ret);
	void			(*z[256])(t_flag *flag, int *ret);
	unsigned char	c;
	char			*tmp;
	t_flag			flag;
	int				r;
}					t_ftpf;

int					ft_printf(char *str, ...);
t_ftpf				*ftpf_init(char *input);
void				ftpf_del(t_ftpf **addr);
int					ft_putwchar(int c);
int					ft_putwstr(int *wstr);
void				ft_putptn(unsigned long int pnt);
char				ft_str_last_char(char *s);

void				useless(t_flag *flag, int *ret);

void				print_zo(t_flag *flag, int *ret);
void				print_zx(t_flag *flag, int *ret);
void				print_zu(t_flag *flag, int *ret);
void				print_zd(t_flag *flag, int *ret);

void				print_jd(t_flag *flag, int *ret);
void				print_jo(t_flag *flag, int *ret);
void				print_ju(t_flag *flag, int *r);
void				print_jx(t_flag *flag, int *ret);

void				print_hd(t_flag *flag, int *ret);
void				print_hud(t_flag *flag, int *ret);
void				print_ho(t_flag *flag, int *ret);
void				print_hx(t_flag *flag, int *ret);
void				print_hu(t_flag *flag, int *r);
void				print_huu(t_flag *flag, int *r);

void				print_hhx(t_flag *flag, int *ret);
void				print_hhu(t_flag *flag, int *r);
void				print_hhd(t_flag *flag, int *ret);
void				print_hho(t_flag *flag, int *ret);

void				print_lc(t_flag *flag, int *ret);
void				print_ls(t_flag *flag, int *ret);
void				print_ld(t_flag *flag, int *ret);
void				print_lo(t_flag *flag, int *ret);
void				print_lx(t_flag *flag, int *ret);
void				print_lu(t_flag *flag, int *r);

void				print_c(t_flag *flag, int *ret);
void				print_s(t_flag *flag, int *ret);
void				print_d(t_flag *flag, int *ret);
void				print_p(t_flag *flag, int *ret);
void				print_o(t_flag *flag, int *ret);
void				print_x(t_flag *flag, int *ret);
void				print_u(t_flag *flag, int *r);

void				print_percent(t_flag *flag, int *ret);

void				print_width(int nbr, int *ret);
void				print_width_z(int nb, int *r);

void				init_xpw(t_flag *flag, char *arr, int *p, int *w);
void				precision(int p, int *r);
void				width(t_flag *flag, int w, int *r);
void				init_useless(t_ftpf *new);
void				init_hhhl(t_ftpf *new);
void				init_lj(t_ftpf *new);
void				init_fct(t_ftpf *new);
void				init_pz(t_ftpf *new);

#endif
