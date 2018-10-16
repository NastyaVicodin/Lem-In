/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room_lst		*add_to_room_lst(t_room_lst *avail_rooms, t_room *head, int level)
{
	t_room_lst *head_avail;

		head_avail = avail_rooms;
		if (avail_rooms && avail_rooms->room)
		{
			//head_avail = avail_rooms;
			if (head_avail->room && head_avail->room->name)
				printf("HEAD_avail: %s\n", head_avail->room->name);
			while (avail_rooms->next)
				avail_rooms = avail_rooms->next;
			avail_rooms->next = (t_room_lst *)malloc(sizeof(t_room_lst));
			avail_rooms = avail_rooms->next;
			avail_rooms->next = NULL;
		}
		
		avail_rooms->room = head;
		// printf("____HEAD_avail: %s\n", avail_rooms->room->name);
		avail_rooms->room->level = level + 1;
		if (level && head_avail && head_avail->room && head_avail->room->name)
			avail_rooms = head_avail;
		printf("______________HEAD_avail: %s\n", avail_rooms->room->name);
	return (avail_rooms);
}

void			free_lst(t_room_lst *lst)
{
	t_room_lst	*tmp;
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

t_lemin			*check_path(t_lemin *lemin)
{
	t_room *head;
	t_links *head_l;
	t_room		*search_room;
	t_room_lst	*avail_rooms;
	t_room_lst	*tmp_room;
	t_room 		*head_save;

	head = lemin->head_room;
	printf("check_path..\n");
	if (lemin->start && lemin->end)
	{
		// avail_rooms = (t_room_lst *)malloc(sizeof(t_room_lst));
		// avail_rooms->next = NULL;
		//printf("END_room: %s\n", lemin->end);
		while (ft_strcmp(lemin->head_room->name, lemin->end) != 0)
			lemin->head_room = lemin->head_room->next;
		search_room = lemin->head_room;
		search_room->level = 0;
		while (search_room)
		{
			// printf("SEARCH_LEVEL: %d\n", search_room->level);
			if (search_room->head_link && search_room->head_link->name)
				head_l = search_room->head_link;
			else
				head_l = NULL;
			while (search_room->head_link && search_room->head_link->name)
			{
				printf("SEARCH_ROOM: %s\n", search_room->name);
				printf("head_link: %s\n", search_room->head_link->name);
				if (ft_strcmp(search_room->head_link->name, lemin->start) == 0)
				{
					ft_printf("%s\n", "MAKING PATH!");
					lemin->head_room = head;
					search_room->head_link = head_l;
					make_path(lemin, search_room, search_room->head_link->room);
					lemin->error = 2;
					free_lst(avail_rooms);
					return (lemin);
				}
				else
				{
					head_save = head;
					while (head && head->name && ft_strcmp(head->name, search_room->head_link->name) != 0)
						head = head->next;

					if (head && head->name && head->level == -1)
					{
						if (!avail_rooms)
						{
							avail_rooms = (t_room_lst *)malloc(sizeof(t_room_lst));
							avail_rooms->next = NULL;
						}
						add_to_room_lst(avail_rooms, head, search_room->level);
						printf("avail_head: %s\n", avail_rooms->room->name);
					}
					head = head_save;
				}
				// if (avail_rooms && avail_rooms->room->name)
				// 	printf("%s%s\n", "Quit add_lst....avail_lst head = ", avail_rooms->room->name);
				// else
				// 	printf("just quit....\n");
				search_room->head_link = search_room->head_link->next;
			}
			if (head_l)
				search_room->head_link = head_l;
			// if (avail_rooms && avail_rooms->room && avail_rooms->room->name)
			// 	printf("Avail_room: %s\n", avail_rooms->room->name);
			// else
			// 	printf("%s\n", "No avail!!!");
			search_room = avail_rooms ? avail_rooms->room : NULL;
			tmp_room = avail_rooms;
			// TO DO: FREE AVAIL_LST HEAD BEFORE NEXT
			// if (search_room)
			// 	printf("Avail_before: %s\n", avail_rooms->room->name);
			// else
			// 	printf("no before!!!\n");
			avail_rooms = avail_rooms ? avail_rooms->next : NULL;
			// if (avail_rooms && avail_rooms->room->name)
			// 	printf("Avail_after: %s\n", avail_rooms->room->name);
			// else
			// 	printf("Avail is NULL!\n");
			tmp_room ? free(tmp_room) : 0;
		}
		avail_rooms ? free_lst(avail_rooms) : 0;
		lemin->head_room = head;
	}
	printf("%s\n", "NO PATH!");
	return (lemin);
}
