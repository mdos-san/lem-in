/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 09:05:32 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/22 09:55:50 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libftprintf.h"

/*
**|	Description struct s_lm
**|
**|	debug: Used to print debug info;
**|	nb_ant: Number of ant given;
*/

typedef struct	s_lm
{
	char		debug;
	int			nb_ant;
}				t_lm;

t_lm			lm_get();

#endif
