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

static void		free_lst(t_room_lst *lst)
{
	t_room_lst	*tmp;
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

static t_lemin	*make_search(t_lemin *lemin, t_room *search, t_room *head)
{
	t_links 	*head_l;
	t_room_lst	*av;

	av = NULL;
	while (search && lemin->error != 2)
	{
		head_l = set_head_link(search);
		while (search->head_link && search->head_link->name)
		{
			if (ft_strcmp(search->head_link->name, lemin->start) == 0)
			{
				search->head_link = head_l;
				make_path(lemin, search, search->head_link->room);
				lemin->error = 2;
				break ;
			}
			else
				av = change_avail(av, head, search);
			search->head_link = search->head_link->next;
		}
		search = lemin->error != 2 ? next_srch(search, head_l, av) : search;
		av = lemin->error != 2 ? next_avail_room(av) : av;
	}
	av ? free_lst(av) : 0;
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
