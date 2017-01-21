/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:26:58 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/03 16:18:33 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#define S1_CAST *(unsigned char*)(s1 + i)
#define S2_CAST *(unsigned char*)(s2 + i)

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (S1_CAST && S2_CAST)
	{
		if (S1_CAST != S2_CAST)
			return ((int)(S1_CAST - S2_CAST));
		i++;
	}
	return ((int)(S1_CAST - S2_CAST));
}
