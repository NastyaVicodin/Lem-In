/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				if_all_num(char *line)
{
	int		i;

	// printf("if_all_num....\n");
	if (ft_strlen(line) > 20)
		return (-1);
	i = -1;
	while (line[++i])
	{
		if (!('0' <= line[i] && line[i] <= '9'))
			return (-1);
	}
	return (1);
}

int				if_exist(t_lemin *lemin, char **arr)
{
	t_room	*head;

	// printf("if_exist...\n");
	head = lemin->head_room;
	while (head && head->name)
	{
		if (ft_strcmp(head->name, arr[0]) == 0 ||
			(head->x == ft_atoi(arr[1]) && head->y == ft_atoi(arr[2])))
			return (-1);
		head = head->next;
	}
	return (1);
}

t_lemin			*line_handler(t_lemin *lemin, char **arr)
{
	int		len;
	t_room	*head;

	head = lemin->head_room;
	len = ft_strlen(arr[0]);
	// printf("line_handler\n");
	if (lemin->head_room->name)
	{
		while (lemin->head_room->next != NULL)
			lemin->head_room = lemin->head_room->next;
		lemin->head_room->next = (t_room *)malloc(sizeof(t_room));
		lemin->head_room = lemin->head_room->next;
		lemin->head_room->next = NULL;
		lemin->head_room->level = -1;
	}
	lemin->head_room->name = (char *)malloc(sizeof(char) * (len + 1));
	lemin->head_room->head_link = (t_links *)malloc(sizeof(t_links));
	lemin->head_room->head_link->next = NULL;
	lemin->head_room->head_link->name = NULL;
	ft_strcpy(lemin->head_room->name, arr[0]);
	lemin->head_room->x = ft_atoi(arr[1]);
	lemin->head_room->y = ft_atoi(arr[2]);
	lemin->head_room = head;
	// printf("Line_handler:head: %s\n", lemin->head_room->name);
	return (lemin);
}

t_lemin			*write_start_end(t_lemin *lemin, char *line, int flag)
{
	int 	len;

	len = ft_strlen(line);
	if (flag == 1)
	{
		lemin->start = (char *)malloc(sizeof(char) * (len + 1));
		ft_strcpy(lemin->start, line);
	}
	else if (flag == 2)
	{
		lemin->end = (char *)malloc(sizeof(char) * (len + 1));
		ft_strcpy(lemin->end, line);
	}
	return (lemin);
}

t_lemin			*if_valid(t_lemin *lemin, char *line, int flag)
{
	char	**arr;
	int		i;

	i = 0;
	arr = ft_strsplit(line, ' ');
	while (arr[i])
		i++;
	if (i == 3 && arr[0][0] && arr[0][0] != '#' && arr[0][0] != 'L')
	{
		if (if_all_num(arr[1]) == 1 && if_all_num(arr[2]) == 1 &&
			if_exist(lemin, arr) == 1)
		{
			line_handler(lemin, arr);
			lemin->error != -1 ? write_start_end(lemin, arr[0], flag) : 0;
		}
		else
			lemin->error = -1;
	}
	else
		lemin->error = -1;
	free_array(arr);
	return (lemin);
}
