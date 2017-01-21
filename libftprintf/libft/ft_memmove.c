/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:00:53 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/04 13:26:21 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (NULL);
	if (len == 0)
		return (dst);
	if (dst < src)
	{
		while (i < len)
		{
			*(unsigned char*)(dst + i) = *(unsigned char*)(src + i);
			i++;
		}
		return (dst);
	}
	else
	{
		i = len;
		while ((int)(--i) >= 0)
			*(unsigned char*)(dst + i) = *(unsigned char*)(src + i);
		return (dst);
	}
}
