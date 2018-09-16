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

t_lemin			*check_path(t_lemin *lemin)
{
	t_room *head;
	t_links *link;
	int		level;

	level = 1;
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
	char	*search_room;

	search_room = lemin->end;
	while (lemin->start && search_room)
	{
		while (lemin->head_room)
		{
			if (ft_strcmp(lemin->head_room->name, search_room) == 0) 
			{
				if (lemin->head_room->visited == 0)
					lemin->head_room->visited = level;
				head_l = lemin->head_room->head_link;
				make_avail_rooms(lemin, head_l);
				while (lemin->head_room->head_link)
				{
					if (ft_strcmp(lemin->head_room->head_link->name, lemin->start) == 0)
					{
						make_path(lemin);
						break ;
					}
					lemin->head_room->head_link = lemin->head_room->head_link->next;
				}
				search_room = find_needed(lemin, level);
				if (!search_room)
					level++;
			}
			lemin->head_room = lemin->head_room->next;
		}
		lemin->head_room = head;
	}
	else
		lemin->error = -1;
	return (lemin);
}
