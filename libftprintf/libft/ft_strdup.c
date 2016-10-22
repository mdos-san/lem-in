/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:29:01 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/03 15:44:08 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*cpy;

	len = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	cpy = (char *)malloc(sizeof(char) * len + 1);
	if (cpy == NULL)
		return (NULL);
	cpy = ft_strcpy(cpy, s1);
	return (cpy);
}
