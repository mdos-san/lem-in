/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:09:33 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/18 06:54:06 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft.h"

static char	*ft_strdupadd(const char *s1, const char *s2, int len)
{
	char	*cpy;

	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (cpy == NULL)
		return (NULL);
	ft_bzero(cpy, len + 1);
	ft_strcpy(cpy, s1);
	ft_strcat(cpy, s2);
	return (cpy);
}

static int	realloc_str(char **st_str, char *buf, int len)
{
	char	*tmp;

	tmp = *st_str;
	*st_str = ft_strdupadd(*st_str, buf, len);
	ft_strdel(&tmp);
	return (1);
}

static void	truncate_str(char **line, char **st_str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (*(*st_str + i) != '\n')
		i++;
	i++;
	tmp = ft_strchr(*st_str, '\n');
	*tmp = 0;
	*line = ft_strdup(*st_str);
	*tmp = '\n';
	tmp = ft_strdup(*st_str + i);
	ft_strdel(st_str);
	*st_str = tmp;
}

static int	end_file(char **line, char **st_str)
{
	*line = ft_strdup(*st_str);
	if (ft_strlen(*line) > 0)
	{
		ft_strdel(st_str);
		return (1);
	}
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static char	*st_str = 0;
	char		buf[BUFF_SIZE + 1];
	int			len;
	int			ret;

	buf[BUFF_SIZE] = 0;
	len = ft_strlen(st_str);
	if (fd < 0 || line == 0)
		return (-1);
	while (!ft_strchr(st_str, '\n'))
	{
		ft_bzero(buf, BUFF_SIZE);
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		if (ret == 0)
			return (end_file(line, &st_str));
		len += ret;
		if (!realloc_str(&st_str, buf, len))
			return (-1);
	}
	truncate_str(line, &st_str);
	return (1);
}
