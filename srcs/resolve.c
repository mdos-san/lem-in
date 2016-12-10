#include "lemin.h"

char	*get_path_room(t_list *lst, int d, int p)
{
	t_list	*c;
	t_room	*r;

	c = lst;
	while (c)
	{
		r = (t_room*)c->content;
		//ft_printf("\nr %d %s", r->p, r->name);
		if (r->p == p)
		{
			if (d == 0)
				return (r->name);
			else
				return (get_path_room(c, d - 1, p));
		}
		c = c->next;
	}
	return (NULL);
}

void	resolve(t_lm *lm)
{
	int		i;
	int		j;
	char	*name;
	int		nb;

	i = 1;
	nb = lm->nb_path;
	while (i <= lm->nb_ant + 1)
	{
		j = 1;
		while (j <= lm->nb_path)
		{
//			ft_printf("i - j + 1 = %d ||| lm->nb_path %d\n", i - j + 1, lm->nb_path);
//			ft_printf("j = %d ||| (i + j) %% nb + 1 = %d\n", j, (i + j) % nb + 1);
			ft_printf("\nActual depth: %d\n", (i + j) % nb + 1);
			name = get_path_room(lm->start_link, j, (i + j) % nb + 1);
			if (name && i - j + nb <= lm->nb_ant)
				ft_printf("L%d-%s ", i - j + nb, name);
			++j;
		}
		ft_printf("\n", i - j + 1, name);
		++i;
	}
}
