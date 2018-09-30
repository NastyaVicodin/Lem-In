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

t_room_lst		*add_to_room_lst(t_room_lst *avail_rooms, t_room *head, char *room_name, int level)
{
	t_room_lst *head_avail;

	printf("ADD_MAIN_HEAD: %s\n", head->name);
	while (head && head->name && ft_strcmp(head->name, room_name) != 0)
		head = head->next;
	if (head && head->name && head->level == -1)
	{
		printf("add_head: %s; level: %d\n", head->name, head->level);
		if (level)
		{
			head_avail = avail_rooms;
			while (avail_rooms->next)
				avail_rooms = avail_rooms->next;
			avail_rooms->next = (t_room_lst *)malloc(sizeof(t_room_lst));
			avail_rooms = avail_rooms->next;
			avail_rooms->next = NULL;
		}
		avail_rooms->room = head;
		avail_rooms->room->level = level + 1;
		if (level)
			avail_rooms = head_avail;
	}
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
	// t_links *link;

	// head = lemin->head_room;
	// printf("---------------\n");
	// while (lemin->head_room)
	// {
	// 	ft_printf("ROOM:%s\n", lemin->head_room->name);
	// 	link = lemin->head_room->head_link;
	// 	while (lemin->head_room->head_link)
	// 	{
	// 		ft_printf("____LINKS:%s\n", lemin->head_room->head_link->name);
	// 		lemin->head_room->head_link = lemin->head_room->head_link->next;
	// 	}
	// 	lemin->head_room->head_link = link;
	// 	lemin->head_room = lemin->head_room->next;
	// }
	
	// printf("---------------\n");
	// lemin->head_room = head;
	t_room		*search_room;
	t_room_lst	*avail_rooms;

	head = lemin->head_room;
	printf("Head_room: %s\n", head->name);
	if (lemin->start && lemin->end)
	{
		avail_rooms = (t_room_lst *)malloc(sizeof(t_room_lst));
		avail_rooms->next = NULL;
		printf("END_room: %s\n", lemin->end);
		printf("START_room: %s\n", lemin->start);
		while (ft_strcmp(lemin->head_room->name, lemin->end) != 0)
			lemin->head_room = lemin->head_room->next;
		search_room = lemin->head_room;
		search_room->level = 0;
		while (search_room)
		{
			printf("SEARCH_ROOM: %s\n", search_room->name);
			printf("SEARCH_LEVEL: %d\n", search_room->level);
			while (search_room->head_link)
			{
				printf("SEARCH_LINK: %s\n", search_room->head_link->name);
				if (ft_strcmp(search_room->head_link->name, lemin->start) == 0)
				{
					printf("%s\n", "MAKING PATH!");
					//make_path(lemin);
					lemin->error = 1;
					lemin->head_room = head;
					free_lst(avail_rooms);
					return (lemin);
				}
				else
					add_to_room_lst(avail_rooms, head, search_room->head_link->name, search_room->level);
				printf("%s\n", "Quit add_lst");
				search_room->head_link = search_room->head_link->next;
			}
			if (avail_rooms && avail_rooms->room && avail_rooms->room->name)
				printf("Avail_room: %s\n", avail_rooms->room->name);
			else
				printf("%s\n", "No avail!!!");
			search_room = avail_rooms ? avail_rooms->room : NULL;
			// TO DO: FREE AVAIL_LST HEAD BEFORE NEXT
			avail_rooms = avail_rooms ? avail_rooms->next : NULL;
		}
		free_lst(avail_rooms);
	}
		printf("%s\n", "NO PATH!");
	
	return (lemin);
}
