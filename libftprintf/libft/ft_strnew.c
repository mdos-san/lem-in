/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:47:08 by mdos-san          #+#    #+#             */
/*   Updated: 2015/11/27 14:17:06 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*result;

	i = 0;
	result = (char*)malloc(size + 1);
	if (result == NULL)
		return (NULL);
	*(result + size) = 0;
	while (i < size)
	{
		*(result + i) = 0;
		i++;
	}
	return (result);
}
