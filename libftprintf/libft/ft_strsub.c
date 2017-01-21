/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:48:20 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/03 13:15:58 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	i = 0;
	result = (char *)malloc(len + 1);
	if (result == NULL)
		return (NULL);
	if (!s)
		return (NULL);
	while (i < len)
	{
		*(result + i) = *(s + start + i);
		i++;
	}
	*(result + i) = 0;
	return (result);
}
