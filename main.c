/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_lemin			*make_struct(void)
{
	t_lemin		*lemin;

	lemin = (t_lemin *)malloc(sizeof(t_lemin));
	lemin->error = 0;
	lemin->ant_count = 0;
	lemin->start = NULL;
	lemin->end = NULL;
	lemin->rooms = (t_room *)malloc(sizeof(t_room));
	lemin->rooms->next = NULL;
	lemin->rooms->name = NULL;
	lemin->head_room = lemin->rooms;
	lemin->rooms->links = (t_links *)malloc(sizeof(t_links));
	lemin->rooms->links->next = NULL;
	lemin->rooms->links->name = NULL;
	return (lemin);
}

t_lemin			*get_ant_count(t_lemin *lemin)
{
	char		*line;

	while (get_next_line(0, &line))
	{
		if (line[0] == '#' && line[1] && line[1] != '#')
		{
			free(line);
			continue ;
		}
		if (ft_strlen(line) <= 20 && if_all_num(line))
			lemin->ant_count = ft_atoi(line);
		if (!lemin->ant_count)
		{
			lemin->error = -1;
			free(line);
			break ;
		}
		free(line);
	}
	return (lemin);
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
		if (ft_strcmp(arr[0], arr[1]) != 0 && if_exist_rooms(lemin, arr))
			get_links(lemin, arr);
		else
			lemin->error = -1;
	}
	else
		lemin->error = -1;
	free_array(arr);
	return (lemin);
}

t_lemin			*get_rooms(t_lemin *lemin)
{
	char		*line;

	while (get_next_line(0, &line) && lemin->error == 0)
	{
		if (line[0] == '#' && line[1] && line[1] != '#')
		{
			free(line);
			continue ;
		}
		else if (line[0] == 'L')
		{
			lemin->error = -1;
			free(line);
		}
		else if (line[0] == '#' && line[1] && line[1] == '#')
			command_handler(lemin, line);
		else
		{
			if_valid(lemin, line);
			if (lemin->error == -1)
				if_link(lemin, line);
			free(line);
		}
	}
	return (lemin);
}

int				main(void)
{
	t_lemin		*lemin;
	char		*line;

	lemin = make_struct();
	get_ant_count(lemin);
	if (lemin->error != -1)
	{
		get_rooms(lemin);
		lemin->error == -1 ? write(1, "ERROR\n", 7) : algo(lemin);
	}
	else
		write(1, "ERROR\n", 7);
	return (0);
}
