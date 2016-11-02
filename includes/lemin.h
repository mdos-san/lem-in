/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 09:05:32 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/22 11:47:39 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libftprintf.h"

/*
**|	Description of struct s_lm
**|
**|	debug:	Used to print debug info;
**|	nb_ant:	Number of ant given;
**|	rooms:	Linked list of all rooms, will containt *t_room as content;
*/

typedef struct	s_lm
{
	char		debug;
	int			nb_ant;
	t_list		*rooms;
}				t_lm;

/*
**| Description of struct s_room
**|
**|	input:	Basic input given on stdin (form: "name x y")
**|	name:	Name of the room;
**|	x:		X position of the room;
**|	y:		Y position of the room;
**|	type:	Type of the room, normal(0), start(1) or end(2);
*/

typedef struct	s_room
{
	char		*input;
	char		*name;
	int			x;
	int			y;
	char		type;
}				t_room;

t_lm			lm_get();
void			lm_start(t_lm *lm);

#endif
