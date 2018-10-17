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
		while (avail_rooms->next)
			avail_rooms = avail_rooms->next;
		avail_rooms->next = (t_room_lst *)malloc(sizeof(t_room_lst));
		avail_rooms = avail_rooms->next;
		avail_rooms->next = NULL;
	}
	avail_rooms->room = head;
	avail_rooms->room->level = level + 1;
	if (level && head_avail && head_avail->room && head_avail->room->name)
		avail_rooms = head_avail;
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

t_room_lst		*change_avail_rooms(t_room_lst *avail_rooms, t_room *head, t_room *search_room)
{
	t_room 		*head_save;

	head_save = head;
	while (head && head->name && ft_strcmp(head->name, search_room->head_link->name) != 0)
		head = head->next;
	if (head && head->name && head->level == -1)
	{
		if (!avail_rooms)
		{
			avail_rooms = (t_room_lst *)malloc(sizeof(t_room_lst));
			avail_rooms->room = NULL;
			avail_rooms->next = NULL;
		}
		add_to_room_lst(avail_rooms, head, search_room->level);
	}
	head = head_save;
	return (avail_rooms);
}

t_lemin			*make_search(t_lemin *lemin, t_room *search_room, t_room *head)
{
	t_links *head_l;
	t_room_lst	*avail_rooms;
	t_room_lst	*tmp_room;

	avail_rooms = NULL;
	while (search_room && lemin->error != 2)
		{
			if (search_room->head_link && search_room->head_link->name)
				head_l = search_room->head_link;
			else
				head_l = NULL;
			while (search_room->head_link && search_room->head_link->name)
			{
				if (ft_strcmp(search_room->head_link->name, lemin->start) == 0)
				{
					search_room->head_link = head_l;
					make_path(lemin, search_room, search_room->head_link->room);
					lemin->error = 2;
					free_lst(avail_rooms);
					break ;
				}
				else
					avail_rooms = change_avail_rooms(avail_rooms, head, search_room);
				search_room->head_link = search_room->head_link->next;
			}
			if (lemin->error != 2)
			{
				if (head_l)
					search_room->head_link = head_l;
				search_room = avail_rooms ? avail_rooms->room : NULL;
				tmp_room = avail_rooms;
				avail_rooms = avail_rooms ? avail_rooms->next : NULL;
				tmp_room ? free(tmp_room) : 0;
			}
		}
		avail_rooms ? free_lst(avail_rooms) : 0;
	return (lemin);
}

t_lemin			*check_path(t_lemin *lemin)
{
	t_room	*head;
	t_room	*search_room;

	if (lemin->start && lemin->end)
	{
		head = lemin->head_room;
		while (ft_strcmp(lemin->head_room->name, lemin->end) != 0)
			lemin->head_room = lemin->head_room->next;
		search_room = lemin->head_room;
		search_room->level = 0;
		lemin = make_search(lemin, search_room, head);
		lemin->head_room = head;
	}
	lemin->error = lemin->error != 2 ? -1 : 2;
	return (lemin);
}
