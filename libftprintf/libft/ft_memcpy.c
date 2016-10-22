/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:52:53 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/03 15:34:29 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (dst);
	while (i < n)
	{
		*(char*)(dst + i) = *(char*)(src + i);
		i++;
	}
	return (dst);
}
