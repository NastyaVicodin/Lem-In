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
	lemin->head_room = (t_room *)malloc(sizeof(t_room));
	lemin->head_room->ant_passed = 0;
	lemin->head_room->level = -1;
	lemin->head_room->next = NULL;
	lemin->head_room->name = NULL;
	return (lemin);
}

static t_lemin			*get_ant_count(t_lemin *lemin)
{
	char		*line;

	while (get_next_line(lemin->fd, &line))
	{
		if (line[0] == '#' && ft_strcmp(line, "##start") != 0 &&
			ft_strcmp(line, "##end") != 0)
		{
			free(line);
			continue ;
		}
		if (line[0] != '0' && line[0] != '-' && if_all_num(line) == 1)
			lemin->ant_count = ft_atoi(line);
		if (lemin->ant_count == 0)
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

	while (lemin->error == 0 && get_next_line(lemin->fd, &line))
	{
		if (line[0] == '#' && ft_strcmp(line, "##start") != 0 &&
			ft_strcmp(line, "##end") != 0)
		{
			free(line);
			continue ;
		}
		else if (line[0] == 'L' || line[0] == '-' || line[0] == ' ')
		{
			lemin->error = -1;
			free(line);
		}
		else if (line[0] == '#' && line[1] && line[1] == '#')
			command_handler(lemin, line);
		else
		{
			if_valid(lemin, line, 0);
			lemin->error == -1 ? if_link(lemin, line) : 0;
			free(line);
		}
	}
	return (lemin);
}

static void				free_all(t_lemin *lemin)
{
	t_room	*prev_room;
	t_links	*prev_link;

	if (lemin)
	{
		lemin->start ? free(lemin->start) : 0;
		lemin->end ? free(lemin->end) : 0;
		while (lemin->head_room)
		{
			lemin->head_room->name ? free(lemin->head_room->name) : 0;
			while (lemin->head_room->head_link)
			{
				prev_link = lemin->head_room->head_link;
				lemin->head_room->head_link = lemin->head_room->head_link->next;
				free(prev_link);
			}
			prev_room = lemin->head_room;
			lemin->head_room = lemin->head_room->next;
			free(prev_room);
		}
		free(lemin);
	}
}

int						main(int ac, char **av)
{
	t_lemin		*lemin;

	if (ac <= 2)
	{
		lemin = make_struct();
		lemin->fd = ac == 2 ? open(av[1], O_RDONLY) : 0;
		if (lemin->fd != -1)
		{
			get_ant_count(lemin);
			if (lemin->error != -1)
			{
				get_rooms(lemin);
				lemin->error != 2 ? check_path(lemin) : 0;
				lemin->error == -1 ? write(1, "ERROR: No path found\n", 21) : 0;
			}
			else
				write(1, "ERROR: Wrong ant's amount\n", 26);
		}
		else
			write(1, "ERROR: File is not valid\n", 25);
		free_all(lemin);
	}
	else
		write(1, "ERROR: Too many files\n", 22);
	return (0);
}
