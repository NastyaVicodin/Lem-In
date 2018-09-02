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

	len = ft_strlen(arr[0]);
	printf("line_handler\n");
	if (lemin->rooms->name)
	{
		while (lemin->rooms->next != NULL)
			lemin->rooms = lemin->rooms->next;
		lemin->rooms->next = (t_room *)malloc(sizeof(t_room));
		lemin->rooms = lemin->rooms->next;
		lemin->rooms->next = NULL;
	}
	lemin->rooms->name = (char *)malloc(sizeof(char) * (len + 1));
	ft_strcpy(lemin->rooms->name, arr[0]);
	lemin->rooms->x = ft_atoi(arr[1]);
	lemin->rooms->y = ft_atoi(arr[2]);
	return (lemin);
}

t_lemin			*if_valid(t_lemin *lemin, char *line)
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
			line_handler(lemin, arr);
		else
			lemin->error = -1;
	}
	else
		lemin->error = -1;
	free_array(arr);
	return (lemin);
}
