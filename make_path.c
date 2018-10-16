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
	int		i, k;
	int		room_count;

	room_count = 0;
	i = -1;
	printf("size: %d\n", size);
	while (++i < size)
		printf("path_arr[%d] = %s\n", i, path_arr[i]->name);
	path_arr[0]->ant_passed = max_ant;
	//printf("path_arr[size]->ant_passed: %d\n", path_arr[size]->ant_passed);
	while (path_arr[size]->ant_passed < max_ant)
	{
		i = 0;
		k = 0;
		while (i < room_count + 1 && ((i < room_count && room_count < size) || i < size - 1))
		{
			if (path_arr[i]->ant_passed && path_arr[i + 1]->ant_passed < max_ant)
			{
				
				if (k != 0)
					printf(" ");
				path_arr[i]->ant_passed--;
				path_arr[i + 1]->ant_passed++;
				printf("L%s-%s", path_arr[i]->name, path_arr[i + 1]->name);
				k++;
			}
			
			i++;
		}printf("\n");
		room_count++;
	}
}

void	make_path(t_lemin *lemin, t_room *curr_room, t_room *start_room)
{
	t_room	**path_arr;
	int		i;
	t_links	*head_l;
	t_room	*tmp;
	int		size;

	i = 0;
	size = curr_room->level + 2;
	path_arr = (t_room **)malloc(sizeof(t_room *) * (size));
	path_arr[i] = start_room;
	printf("current room: %s; level = %d\n", curr_room->name, curr_room->level);
	i++;
	path_arr[i] = curr_room;
	i++;
	while (ft_strcmp(curr_room->name, lemin->end) != 0)
	{
		head_l = curr_room->head_link;
		printf("head_link: %s\n", curr_room->head_link->name);
		while (curr_room->head_link)
		{
			printf("curr_room: %s lvl = %d; cmp_room: %s lvl = %d\n", curr_room->name, curr_room->level, curr_room->head_link->name, curr_room->head_link->room->level);
			if (curr_room->level - curr_room->head_link->room->level == 1)
			{
				path_arr[i] = curr_room->head_link->room;
				printf("path_arr[%d] = %s\n", i, path_arr[i]->name);
				i++;
				tmp = curr_room->head_link->room;
				
				curr_room->head_link = head_l;
				curr_room = tmp;
				break ;
			}
			curr_room->head_link = curr_room->head_link->next;
		}
	}
	if (curr_room->name != path_arr[1]->name)
		path_arr[i] = curr_room;
	print_path(path_arr, size, lemin->ant_count);
	free(path_arr);
}