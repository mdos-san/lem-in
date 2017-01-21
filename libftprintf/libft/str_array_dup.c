/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_array_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 10:02:54 by mdos-san          #+#    #+#             */
/*   Updated: 2016/09/19 11:26:54 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**str_array_dup(char **array, int extra_row)
{
	char	**new;
	int		index;
	int		max;

	index = 0;
	max = str_array_count(array);
	new = (char **)malloc((max + 1 + extra_row) * sizeof(char*));
	new[max + extra_row] = NULL;
	if (array == NULL)
		return (NULL);
	while (index < max)
	{
		new[index] = ft_strdup(array[index]);
		++index;
	}
	while (index <= max + extra_row)
	{
		new[index] = NULL;
		++index;
	}
	return (new);
}
