/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_room_lst	*add_to_room_lst(t_room_lst *av, t_room *head, int level)
{
	t_room_lst *head_avail;

	head_avail = av;
	if (av && av->room)
	{
		while (av->next)
			av = av->next;
		av->next = (t_room_lst *)malloc(sizeof(t_room_lst));
		av = av->next;
		av->next = NULL;
	}
	av->room = head;
	av->room->level = level + 1;
	if (level && head_avail && head_avail->room && head_avail->room->name)
		av = head_avail;
	return (av);
}

t_room_lst			*next_avail_room(t_room_lst *avail_rooms)
{
	t_room_lst	*tmp_room;

	tmp_room = avail_rooms;
	avail_rooms = avail_rooms ? avail_rooms->next : NULL;
	tmp_room ? free(tmp_room) : 0;
	return (avail_rooms);
}

t_room				*next_srch(t_room *srch, t_links *head_l, t_room_lst *av)
{
	if (head_l)
		srch->head_link = head_l;
	srch = av ? av->room : NULL;
	return (srch);
}

t_room_lst			*change_avail(t_room_lst *av, t_room *head, t_room *srch)
{
	t_room		*head_save;

	head_save = head;
	while (head && head->name &&
			ft_strcmp(head->name, srch->head_link->name) != 0)
		head = head->next;
	if (head && head->name && head->level == -1)
	{
		if (!av)
		{
			av = (t_room_lst *)malloc(sizeof(t_room_lst));
			av->room = NULL;
			av->next = NULL;
		}
		add_to_room_lst(av, head, srch->level);
	}
	head = head_save;
	return (av);
}

t_links				*set_head_link(t_room *search_room)
{
	if (search_room->head_link && search_room->head_link->name)
		return (search_room->head_link);
	else
		return (NULL);
}
