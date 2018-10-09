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

void	print_path(t_room *path_arr, int size, int max_ant)
{
	int		i;
	int		room_count;

	room_count = 0;
	while (path_arr[size]->ant_passed < max_ant)
	{
		i = -1;
		while ((++i < room_count && room_count <= size) || (++i < size))
		{
			if (path_arr[i]->ant_passed < max_ant && path_arr[i + 1]->ant_passed < max_ant)
			{
				if (i == 0)
					path_arr[i]->ant_passed++;
				path_arr[i + 1]->ant_passed++;
				ft_printf("L%s-%s", path_arr[i]->name, path_arr[i + 1]->name);
			}
			ft_printf("\n");
		}
		room_count++;
	}
}

void	make_path(t_lemin *lemin, t_room *curr_room)
{
	t_room	*path_arr;
	int		i;

	i = 0;
	path_arr = (t_room *)malloc(sizeof(t_room) * (curr_room->level + 1));
	path_arr[i] = curr_room;
	i++;
	while (ft_strcmp(curr_room->name, lemin->end) != 0)
	{
		while (curr_room->head_link)
		{
			if (curr_room->level - curr_room->head_link->room->level == 1)
			{
				path_arr[i++] = curr_room->head_link->room;
				curr_room = curr_room->head_link->room;
				break ;
			}
			curr_room->head_link = curr_room->head_link->next;
		}
	}
	path_arr[i] = curr_room;
	print_path(path_arr, level, lemin->ant_count);
}