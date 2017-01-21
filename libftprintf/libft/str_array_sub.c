/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_array_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 10:03:12 by mdos-san          #+#    #+#             */
/*   Updated: 2016/09/19 11:27:22 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	str_array_sub(char ***stra, char *pattern)
{
	int		i;
	int		j;
	int		line;
	char	**new;

	i = 0;
	j = 0;
	line = str_array_count(*stra);
	new = (char **)malloc(line * sizeof(char *));
	while ((*stra)[i])
	{
		if (ft_strstart((*stra)[i], pattern) == 0)
		{
			new[j] = ft_strdup((*stra)[i]);
			++j;
		}
		++i;
	}
	str_array_del(stra);
	*stra = new;
}
