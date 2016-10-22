/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:23:55 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/03 13:11:19 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	i = 0;
	result = 0;
	if (!s)
		return (NULL);
	result = ft_strdup(s);
	while (*(result + i) != 0)
	{
		*(result + i) = f(i, *(result + i));
		i++;
	}
	return (result);
}
