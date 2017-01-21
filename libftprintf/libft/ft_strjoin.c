/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:55:55 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/03 15:01:42 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*result;

	result = 0;
	len = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	result = (char*)malloc(len + 1);
	if (result == NULL)
		return (NULL);
	result[len] = 0;
	ft_bzero(result, len);
	ft_strcat(result, s1);
	ft_strcat(result, s2);
	return (result);
}
