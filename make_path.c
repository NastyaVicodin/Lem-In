/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_path(t_room **path_arr, int size, int max_ant)
{
	int		i;
	int		k;
	int		room_count;

	room_count = 0;
	path_arr[0]->ant_passed = max_ant;
	while (path_arr[size - 1]->ant_passed < max_ant)
	{
		i = 0;
		k = 0;
		while (i < room_count + 1 && ((i < room_count && room_count < size)
				|| i < size - 1))
		{
			if (path_arr[i]->ant_passed && path_arr[i + 1]->ant_passed < max_ant)
			{
				k++ != 0 ? ft_printf(" ") : 0;
				path_arr[i]->ant_passed--;
				path_arr[i + 1]->ant_passed++;
				ft_printf("L%s-%s", path_arr[i]->name, path_arr[i + 1]->name);
			}
			i++;
		}
		ft_printf("\n");
		room_count++;
	}
}

t_room	**make_path_array(t_room *start_room, t_room *curr_room, int size)
{
	t_room	**path_arr;

	path_arr = (t_room **)malloc(sizeof(t_room *) * (size));
	path_arr[0] = start_room;
	path_arr[1] = curr_room;
	return (path_arr);
}

t_room	**fill_path_array(t_room *start_room, t_room *curr_room, t_lemin *lemin, int size)
{
	t_room	**path_arr;
	int		i;
	t_links	*head_l;
	t_room	*tmp;

	i = 2;
	path_arr = make_path_array(start_room, curr_room, size);
	while (ft_strcmp(curr_room->name, lemin->end) != 0)
	{
		head_l = curr_room->head_link;
		while (curr_room->head_link)
		{
			if (curr_room->level - curr_room->head_link->room->level == 1)
			{
				path_arr[i++] = curr_room->head_link->room;
				tmp = curr_room->head_link->room;
				curr_room->head_link = head_l;
				curr_room = tmp;
				break ;
			}
			curr_room->head_link = curr_room->head_link->next;
		}
	}
	path_arr[i] = curr_room;
	return (path_arr);
}

void	make_path(t_lemin *lemin, t_room *curr, t_room *start)
{
	t_room	**path_arr;
	int		size;

	size = curr->level + 2;
	path_arr = fill_path_array(start, curr, lemin, size);
	print_path(path_arr, size, lemin->ant_count);
	free(path_arr);
}