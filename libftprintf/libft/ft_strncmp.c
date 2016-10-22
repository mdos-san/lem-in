/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:42:58 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/03 16:20:31 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#define S1_CAST *(unsigned char*)(s1 + i)
#define S2_CAST *(unsigned char*)(s2 + i)

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (i < n && S1_CAST && S2_CAST)
	{
		if (S1_CAST != S2_CAST)
			return ((int)(S1_CAST - S2_CAST));
		i++;
	}
	if (i < n)
		return ((int)(S1_CAST - S2_CAST));
	return (0);
}
