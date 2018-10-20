/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_room	*find_room(t_room *head_lem, char *link)
{
	t_room	*head;
	t_room	*res;

	head = head_lem;
	while (head_lem)
	{
		if (ft_strcmp(head_lem->name, link) == 0)
			break ;
		head_lem = head_lem->next;
	}
	res = head_lem;
	head_lem = head;
	return (res);
}

t_lemin			*new_link(t_room *r, t_room *h, char *link, t_lemin *l)
{
	t_links	*head;

	if (r->head_link && r->head_link->name)
	{
		head = r->head_link;
		while (r->head_link->next != NULL)
			r->head_link = r->head_link->next;
		r->head_link->next = (t_links *)malloc(sizeof(t_links));
		r->head_link = r->head_link->next;
		r->head_link->next = NULL;
	}
	else
	{
		if (!r->head_link)
		{
			r->head_link = (t_links *)malloc(sizeof(t_links));
			r->head_link->next = NULL;
		}
		head = r->head_link;
	}
	r->head_link->room = find_room(h, link);
	r->head_link->name = r->head_link->room->name;
	ft_strcpy(r->head_link->name, link);
	r->head_link = head;
	return (l);
}
