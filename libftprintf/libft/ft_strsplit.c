/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:52:23 by mdos-san          #+#    #+#             */
/*   Updated: 2016/01/23 08:40:13 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	check_nb_word(char const *s, char c)
{
	int	i;
	int	nb_word;

	i = 0;
	nb_word = 0;
	while (*(s + i) != 0)
	{
		if (*(s + i) != c)
		{
			nb_word++;
			while (*(s + i) != c && *(s + i) != 0)
				i++;
			if (*(s + i) == 0)
				i--;
		}
		i++;
	}
	return (nb_word);
}

static int	alloc_str(char ***tab_str, char const *s, int *i, int *i2)
{
	if (*i2 > 0)
	{
		if (!(**tab_str = (char*)malloc(*i2 + 1)))
			return (0);
		ft_strncpy(**tab_str, (s + *i), *i2);
		*(**tab_str + *i2) = 0;
		*tab_str = *tab_str + 1;
		*i = *i + *i2 - 1;
		*i2 = 0;
	}
	return (1);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		i2;
	int		nb_word;
	char	**tab_str;

	i = 0;
	i2 = 0;
	if (!s || !c)
		return (NULL);
	nb_word = check_nb_word(s, c);
	if (!(tab_str = (char**)malloc(sizeof(char*) * (nb_word + 1))))
		return (NULL);
	tab_str[nb_word] = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i + i2] != c && s[i + i2])
				i2++;
			if (alloc_str(&tab_str, s, &i, &i2) == 0)
				return (NULL);
		}
		i++;
	}
	return (tab_str - nb_word);
}
