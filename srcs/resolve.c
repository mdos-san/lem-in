#include "lemin.h"

static char			*get_room_of_path(t_room *ro, int p, int nb, int *end)
{
	t_list	*c;
	t_room	*r;
	int		i;

	i = 0;
	c = ro->link;
	if (nb == 0 || ro->type == 2)
	{
		if (ro->type == 2)
			++*end;
		return (ro->name);
	}
	while (c)
	{
		r = *(t_room**)c->content;
		if (((ro->w > r->w || ro->w == -1) && r->p == p) || r->type == 2)
		{
			return (get_room_of_path(r, p, nb - 1, end));
		}
		++i;
		c = c->next;
	}
	return (NULL);
}


void			resolve(t_lm *lm)
{
	int		i;
	int		j;
	char	*str;
	int		lem;
	int		turn;
	int		depth;
	int		path;
	int		end;
	int		nend;

	i = 1;
	turn = 0;
	end = 0;
	nend = 0;
	while (end < lm->nb_ant)
	{
		j = 1;
		++turn;
		while (j <= lm->nb_ant + 1)
		{
			lem = i - j + lm->nb_path;
			if (end < lem && lem <= lm->nb_ant)
			{
				path = (lem % lm->nb_path) + 1;
				depth = j / (lm->nb_path) + 1;
				if (lem % lm->nb_path == 1)
					--depth;
				else if (lm->nb_path == 1)
					--depth;
				str = get_room_of_path(lm->start, path, depth, &nend);
				if (str)
					ft_printf("L%d-%s ", lem, str);
			}
			++j;
		}
		end = nend;
		ft_putchar('\n');
		i += lm->nb_path;
	}
}
