/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:49:12 by mdos-san          #+#    #+#             */
/*   Updated: 2015/11/27 16:05:04 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*mem;

	i = 0;
	mem = 0;
	if ((int)size <= 0)
		return (NULL);
	mem = (char *)malloc(size + 1);
	if (mem == NULL)
		return (NULL);
	*(char*)(mem + size) = '\0';
	while (i < size)
	{
		*(char*)(mem + i) = '\0';
		i++;
	}
	return (mem);
}
