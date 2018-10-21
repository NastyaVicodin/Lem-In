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

static t_lemin	*make_search(t_lemin *lemin, t_room *srch, t_room *head)
{
	t_links		*head_l;
	t_room_lst	*av;

	av = NULL;
	while (srch && lemin->error != 2)
	{
		head_l = set_head_link(srch);
		while (srch->head_link && srch->head_link->name)
		{
			if (ft_strcmp(srch->head_link->name, lemin->start) == 0)
			{
				lemin = make_path(lemin, srch, srch->head_link->room, head_l);
				lemin->error = 2;
				break ;
			}
			else
				av = change_avail(av, head, srch);
			srch->head_link = srch->head_link->next;
		}
		srch = lemin->error != 2 ? next_srch(srch, head_l, av) : srch;
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
