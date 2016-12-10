/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 09:05:32 by mdos-san          #+#    #+#             */
/*   Updated: 2016/12/09 20:12:16 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libftprintf.h"

/*
**| Description of struct s_room
**|
**|	input:	Basic input given on stdin (ex: "name x y")
**|	name:	Name of the room;
**|	x:		X position of the room;
**|	y:		Y position of the room;
**|	id:		Unique id to identify room without difficulties;
**|	type:	Type of the room, normal(0), start(1) or end(2);
**|	link: 	Linked list of all connected room;
*/

typedef struct	s_room
{
	char		*input;
	char		*name;
	int			x;
	int			y;
	int			id;
	char		type;
	t_list		*link;
	int			w;
	int			p;
}				t_room;

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
	t_list		*path;
	int			path_length;
	t_list		*path_tmp;
	int			tmp_length;
	char		*input;
	int			nb_path;
	t_room		*start;
}				t_lm;

t_lm			lm_get();
void			lm_start(t_lm *lm);
char			*ft_strdup_to_char(char *str, char c);
void			ft_lstpushb_cpy(t_list *lst, void *content,
					size_t content_size);
void			ft_lstdetach_last(t_list *l);
int				ft_lstcount(t_list *l);
void			bfs(t_room *act, int depth);
int				count_path(t_list *st_l);
void			resolve(t_lm *lm);

#endif
