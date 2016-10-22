/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:04:37 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/03 15:27:03 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (NULL);
	while (i < n)
	{
		*(unsigned char*)(dst + i) = *(unsigned char*)(src + i);
		if (*(unsigned char*)(dst + i) == (unsigned char)c)
			return ((void *)(dst + i + 1));
		i++;
	}
	return (NULL);
}
