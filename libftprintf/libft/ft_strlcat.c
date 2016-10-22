/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:16:41 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/03 15:56:55 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	i2;
	size_t	end_str;
	size_t	len_dst;

	i = 0;
	i2 = 0;
	end_str = 0;
	len_dst = 0;
	if (!dst || !src)
		return (0);
	end_str = size - ft_strlen(dst) - 1;
	len_dst = ft_strlen(dst);
	if ((int)end_str < 0)
		return (size + ft_strlen(src));
	while (*(dst + i) != '\0')
		i++;
	while ((int)i2 < (int)end_str)
	{
		dst[i] = src[i2];
		i++;
		i2++;
	}
	dst[i] = 0;
	return (len_dst + ft_strlen(src));
}
