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
	lemin->head_room = head;
	return (lemin);
}
