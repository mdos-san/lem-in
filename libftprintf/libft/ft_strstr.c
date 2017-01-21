/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:53:08 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/03 16:03:24 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int			i;
	size_t		i2;
	size_t		len_s2;

	i = 0;
	i2 = 0;
	len_s2 = 0;
	if (!s1 || !s2)
		return (NULL);
	len_s2 = ft_strlen(s2);
	if (*s2 == '\0')
		return ((char *)s1);
	while (s1[i])
	{
		while (s1[i + i2] == s2[i2] && s1[i + i2])
			i2++;
		if (i2 == len_s2)
			return ((char *)(s1 + i));
		else
			i2 = 0;
		i++;
	}
	return (NULL);
}
