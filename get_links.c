/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_lemin	*get_links(t_lemin *lemin, char **arr)
{
	int		i;
	t_room	*head;

	head = lemin->head_room;
	i = 0;
	while (lemin->head_room && lemin->head_room->name && i < 2)
	{
		if (ft_strcmp(lemin->head_room->name, arr[0]) == 0)
		{
			new_link(lemin->head_room, head, arr[1], lemin);
			i++;
		}
		else if (ft_strcmp(lemin->head_room->name, arr[1]) == 0)
		{
			new_link(lemin->head_room, head, arr[0], lemin);
			i++;
		}
		lemin->head_room = lemin->head_room->next;
	}
	lemin->head_room = head;
	return (lemin);
}

static int		link_notstored(t_room *room, char *link)
{
	t_links	*head;

	if (ft_strcmp(room->name, link) == 0)
		return (-1);
	if (room->head_link && room->head_link->name)
		head = room->head_link;
	else
		head = NULL;
	while (room->head_link && room->head_link->name)
	{
		if (ft_strcmp(room->head_link->name, link) == 0)
		{
			if (head)
				room->head_link = head;
			return (-1);
		}
		room->head_link = room->head_link->next;
	}
	if (head)
		room->head_link = head;
	return (1);
}

static int		if_exist_rooms(t_lemin *lemin, char **arr)
{
	t_room	*head;
	int		i;

	i = 0;
	head = lemin->head_room;
	while (lemin->head_room && i < 2)
	{
		if ((ft_strcmp(lemin->head_room->name, arr[0]) == 0 &&
			link_notstored(lemin->head_room, arr[1]) == 1) ||
			(ft_strcmp(lemin->head_room->name, arr[1]) == 0 &&
			link_notstored(lemin->head_room, arr[0]) == 1))
			i++;
		lemin->head_room = lemin->head_room->next;
	}
	lemin->head_room = head;
	if (i != 2)
		return (-1);
	return (1);
}

t_lemin			*if_link(t_lemin *lemin, char *line)
{
	char	**arr;
	int		i;

	i = 0;
	arr = ft_strsplit(line, '-');
	while (arr[i])
		i++;
	if (i == 2 && arr[0][0] && arr[0][0] != '#' && arr[0][0] != 'L' &&
		arr[1][0] && arr[1][0] != '#' && arr[1][0] != 'L')
	{
		if (ft_strcmp(arr[0], arr[1]) != 0 &&
			if_exist_rooms(lemin, arr) == 1)
		{
			lemin->error = 0;
			get_links(lemin, arr);
		}
	}
	free_array(arr);
	if (lemin->error == -1)
		check_path(lemin);
	return (lemin);
}
