/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_array_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 10:02:59 by mdos-san          #+#    #+#             */
/*   Updated: 2016/09/19 11:27:12 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_array_find(char **arr, char *pattern)
{
	int	index;

	index = 0;
	while (arr[index])
	{
		if (ft_strstart(arr[index], pattern))
			return (arr[index]);
		++index;
	}
	return (NULL);
}
