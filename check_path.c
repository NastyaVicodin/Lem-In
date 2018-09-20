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

	while (head && head->name && ft_strcmp(head->name, room_name) == 0)
		head = head->next;
	if (head && head->name && head->level == -1)
	{
		if (level)
		{
			head_avail = avail_rooms->room;
			while (avail_rooms->room)
				avail_rooms->room = avail_rooms->room->next;
		}
		avail_rooms->room = head;
		avail_rooms->room->level = level + 1;
		if (level)
			avail_rooms->room = head_avail;
	}
	return (avail_rooms);
}

t_lemin			*check_path(t_lemin *lemin)
{
	t_room *head;
	t_links *link;

	head = lemin->head_room;
	printf("---------------\n");
	while (lemin->head_room)
	{
		ft_printf("ROOM:%s\n", lemin->head_room->name);
		link = lemin->head_room->head_link;
		while (lemin->head_room->head_link)
		{
			ft_printf("____LINKS:%s\n", lemin->head_room->head_link->name);
			lemin->head_room->head_link = lemin->head_room->head_link->next;
		}
		lemin->head_room->head_link = link;
		lemin->head_room = lemin->head_room->next;
	}
	
	printf("---------------\n");
	lemin->head_room = head;
	t_room		*search_room;
	t_room_lst	*avail_rooms;

	head = lemin->head_room;
	if (lemin->start && lemin->end)
	{
		avail_rooms = (t_room_lst *)malloc(sizeof(t_room_lst));
		avail_rooms->next = NULL;
		while (ft_strcmp(lemin->head_room->name, lemin->end) == 0)
			lemin->head_room = lemin->head_room->next;
		search_room = lemin->head_room;
		search_room->level = 0;
		while (search_room)
		{
			while (lemin->search_room->head_link)
			{
				if (ft_strcmp(lemin->search_room->head_link->name, lemin->start) == 0)
				{
					make_path(lemin);
					break ;
				}
				else
					add_to_room_lst(avail_rooms, head, lemin->search_room->head_link->name, lemin->search_room->level);
				lemin->head_room->head_link = lemin->head_room->head_link->next;
			}
			search_room = avail_rooms->room;
			avail_rooms->room = avail_rooms->room->next;
		}	
	}
	else
		lemin->error = -1;
	return (lemin);
}
