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

#include "lemin.h"

static t_lemin			*make_struct(void)
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

static t_lemin			*get_ant_count(t_lemin *lemin)
{
	char		*line;

	while (get_next_line(0, &line))
	{
		if (line[0] == '#' && ft_strcmp(line, "##start") != 0 &&
			ft_strcmp(line, "##end") != 0)
		{
			free(line);
			continue ;
		}
		if (ft_strlen(line) <= 20 && if_all_num(line) == 1)
			lemin->ant_count = ft_atoi(line);
		if (!lemin->ant_count)
		{
			lemin->error = -1;
			free(line);
			break ;
		}
		free(line);
		if (lemin->ant_count)
			break ;
	}
	return (lemin);
}

static t_lemin			*get_rooms(t_lemin *lemin)
{
	char		*line;

	while (lemin->error == 0 && get_next_line(0, &line))
	{
		if (line[0] == '#' && ft_strcmp(line, "##start") != 0 &&
			ft_strcmp(line, "##end") != 0)
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
			lemin->error == -1 ? if_link(lemin, line) : 0;
			free(line);
		}
	}
	return (lemin);
}

int						main(void)
{
	t_lemin		*lemin;

	lemin = make_struct();
	get_ant_count(lemin);
	if (lemin->error != -1)
	{
		get_rooms(lemin);
		if (lemin->error != -1)
			write(1, "IM HAPPY!\n", 10);
		else
			write(1, "ERROR\n", 7);
		//lemin->error == -1 ? write(1, "ERROR\n", 7) : algo(lemin);
	}
	else
		write(1, "ERROR\n", 7);
	return (0);
}
