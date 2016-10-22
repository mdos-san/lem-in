/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 09:16:42 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/04 14:20:38 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

static void	get_nb_char(int n, int *size)
{
	while (n > 0)
	{
		n /= 10;
		*size = *size + 1;
	}
}

static char	*exception(int n, char *result)
{
	if (n == 0)
	{
		result = (char*)malloc(2);
		if (!result)
			return (NULL);
		result[0] = '0';
		result[1] = 0;
		return (result);
	}
	if (n == -2147483647 - 1)
	{
		result = (char*)malloc(12);
		if (!result)
			return (NULL);
		result = ft_strcpy(result, "-2147483648");
		return (result);
	}
	return (0);
}

static void	if_n_negative(int *n, int *is_negative, int *size)
{
	if (*n < 0)
	{
		*n = *n * -1;
		(*is_negative)++;
		(*size)++;
	}
}

char		*ft_itoa(int n)
{
	int		i;
	int		is_negative;
	int		size;
	char	*result;

	i = 1;
	is_negative = 0;
	size = 0;
	result = NULL;
	if (n == 0 || n == -2147483647 - 1)
		return (exception(n, result));
	if_n_negative(&n, &is_negative, &size);
	get_nb_char(n, &size);
	result = (char*)malloc(size + 1);
	if (!result)
		return (NULL);
	result[size] = 0;
	while (n > 0)
	{
		result[size - i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	result[0] = (is_negative == 1) ? '-' : result[0];
	return (result);
}
