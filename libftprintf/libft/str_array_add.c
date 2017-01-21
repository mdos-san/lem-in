/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_array_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 10:02:42 by mdos-san          #+#    #+#             */
/*   Updated: 2016/09/19 11:26:09 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	str_array_add(char ***array, char *str)
{
	char	**new;

	new = str_array_dup(*array, 1);
	str_array_del(array);
	new[str_array_count(new)] = ft_strdup(str);
	*array = new;
}
