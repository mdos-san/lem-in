/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:38:50 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/04 13:17:30 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	is_negative;

	i = 0;
	result = 0;
	is_negative = 0;
	if (!str)
		return (0);
	while (((9 <= *(str + i)) && (*(str + i) <= 13)) || (*(str + i) == 32))
		i++;
	if (((ft_isdigit(str[i])) == 0) && !((str[i] == '+') || (str[i] == '-')))
		return (0);
	if (*(str + i) == '-')
		is_negative = 1;
	if ((*(str + i) == '+') || (*(str + i) == '-'))
		i++;
	while (ft_isdigit(*(str + i)) != 0)
	{
		result *= 10;
		result = result + *(str + i) - 48;
		i++;
	}
	(is_negative == 1) ? (result *= -1) : 1;
	return (result);
}
