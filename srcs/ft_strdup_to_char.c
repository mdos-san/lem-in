/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_to_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:51:01 by mdos-san          #+#    #+#             */
/*   Updated: 2017/01/21 16:05:53 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	*ft_strdup_to_char(char *str, char c)
{
	int		pos_c;
	int		i;
	char	*new;

	i = 0;
	pos_c = 0;
	while (str && str[pos_c] != c && str[pos_c] != 0)
		++pos_c;
	new = ft_strnew(pos_c);
	if (!new)
		return (NULL);
	while (new && i < pos_c)
	{
		new[i] = str[i];
		++i;
	}
	return (new);
}
