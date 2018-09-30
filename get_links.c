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

static t_lemin	*new_link(t_room *room, t_lemin *lemin, int len, char *link)
{
	t_links	*head;

	if (room->head_link && room->head_link->name)
	{
		head = room->head_link;
		while (room->head_link->next != NULL)
			room->head_link = room->head_link->next;
		room->head_link->next = (t_links *)malloc(sizeof(t_links));
		room->head_link = room->head_link->next;
		room->head_link->next = NULL;
	}
	else
	{
		!(room->links) ? room->links = (t_links *)malloc(sizeof(t_links)) : 0;
		room->head_link = room->links;
		room->links->next = NULL;
		head = room->head_link;
	}
	room->head_link->name = (char *)malloc(sizeof(char) * (len + 1));
	ft_strcpy(room->head_link->name, link);
	room->head_link = head;
	return (lemin);
}

static t_lemin	*get_links(t_lemin *lemin, char **arr)
{
	int		len;
	int		i;
	t_room	*head;

	head = lemin->head_room;
	i = 0;
	printf("get_links==========: %s, %s\n", arr[0], arr[1]);
	while (lemin->head_room && lemin->head_room->name && i < 2)
	{
		if (ft_strcmp(lemin->head_room->name, arr[0]) == 0)
		{
			len = ft_strlen(arr[1]);
			new_link(lemin->head_room, lemin, len, arr[1]);
			i++;
		}
		else if (ft_strcmp(lemin->head_room->name, arr[1]) == 0)
		{
			len = ft_strlen(arr[0]);
			new_link(lemin->head_room, lemin, len, arr[0]);
			i++;
		}
		lemin->head_room = lemin->head_room->next;
	}
	lemin->head_room = head;
	return (lemin);
}

static int		link_notstored(t_room *room, char *link)
{ //no leaks
	if (ft_strcmp(room->name, link) == 0)
		return (-1);
	while (room->links && room->links->name)
	{
		if (ft_strcmp(room->links->name, link) == 0)
			return (-1);
		room->links = room->links->next;
	}
	return (1);
}

static int		if_exist_rooms(t_lemin *lemin, char **arr)
{ //no leaks
	t_room	*head;
	int		i;

	i = 0;
	head = lemin->head_room;
	printf("if_exist_rooms\n");
	printf("Link:head_room: %s\n", head->name);
	while (lemin->head_room && i < 2)
	{
		if ((ft_strcmp(lemin->head_room->name, arr[0]) == 0 &&
			link_notstored(lemin->head_room, arr[1]) == 1) ||
			(ft_strcmp(lemin->head_room->name, arr[1]) == 0 &&
			link_notstored(lemin->head_room, arr[0]) == 1))
		{
			i++;
			printf("First: %s; second: %s\n", arr[0], arr[1]);
		}
			
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
	printf("if_link\n");
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
