/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_array_cpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 15:34:57 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/16 15:38:09 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	str_array_cpy(char **dest, char **src)
{
	int		index;
	int		max;

	index = 0;
	max = str_array_count(dest);
	while (index < max)
	{
		ft_strcpy(dest[index], src[index]);
		++index;
	}
}
