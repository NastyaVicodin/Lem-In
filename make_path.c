/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		print_path(t_room **p, int size, size_t max)
{
	int		i;
	int		k;

	p[0]->ant_passed = max;
	i = -1;
	while (p[size - 1]->ant_passed < max)
	{
		i = size - 2;
		k = 0;
		while (i >= 0)
		{
			if (p[i]->ant_passed)
			{
				k++ != 0 ? ft_printf(" ") : 0;
				p[i + 1]->ant_passed++;
				if (p[i + 1]->ant_passed <= max)
					ft_printf("L%d-%s", p[i + 1]->ant_passed, p[i + 1]->name);
			}
			i--;
		}
		ft_printf("\n");
	}
}

static t_room	**make_path_array(t_room *start, t_room *curr_room, int size)
{
	t_room	**path_arr;

	path_arr = (t_room **)malloc(sizeof(t_room *) * (size));
	path_arr[0] = start;
	path_arr[1] = curr_room;
	return (path_arr);
}

static t_room	**fill_path(t_room *start, t_room *curr, t_lemin *l, int size)
{
	t_room	**path_arr;
	int		i;
	t_links	*head_l;
	t_room	*tmp;

	i = 2;
	path_arr = make_path_array(start, curr, size);
	while (ft_strcmp(curr->name, l->end) != 0)
	{
		head_l = curr->head_link;
		while (curr->head_link)
		{
			if (curr->level - curr->head_link->room->level == 1)
			{
				path_arr[i++] = curr->head_link->room;
				tmp = curr->head_link->room;
				curr->head_link = head_l;
				curr = tmp;
				break ;
			}
			curr->head_link = curr->head_link->next;
		}
	}
	path_arr[i] = curr;
	return (path_arr);
}

t_lemin			*make_path(t_lemin *l, t_room *c, t_room *s, t_links *h)
{
	t_room	**path_arr;
	int		size;

	size = c->level + 2;
	c->head_link = h;
	path_arr = fill_path(s, c, l, size);
	print_path(path_arr, size, l->ant_count);
	free(path_arr);
	return (l);
}
