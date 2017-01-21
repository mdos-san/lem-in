/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:16:36 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/03 13:11:49 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*result;

	i = 0;
	result = 0;
	if (s == 0)
		return (NULL);
	result = ft_strdup(s);
	while (*(result + i) != 0)
	{
		*(result + i) = f(*(result + i));
		i++;
	}
	return (result);
}
