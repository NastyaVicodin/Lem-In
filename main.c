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
	lemin->rooms->name = NULL;
	return (lemin);
}

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
// HERE WE GO!!!!!!!!!!!!!!!!!
int				if_valid(char *line)
{
	char	**arr;
	int		i;

	i = 0;
	arr = ft_strsplit(line, ' ');
	while (arr[i])
		i++;
	if (i == 3)
	{
		if (if_all_num(arr[1]) && if_all_num(arr[2]))
			return (0);
	}
	free_array(arr);
	return (-1);
}

t_lemin			*start_handler(t_lemin *lemin)
{
	if (lemin->start == NULL && get_next_line(0, &line))
	{
		if (if_valid(line) == 0)
			line_handler(lemin, line);
		else
			emin->error == -1;
		free(line);
	}
	else
		lemin->error == -1;
	return (lemin);
}

t_lemin			*command_handler(t_lemin *lemin, char *line)
{
	if (ft_strcmp(line, "##start") == 0)
		start_handler(lemin);
	else if (ft_strcmp(line, "##end") == 0)
		end_handler(lemin);
	free(line);
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
			if_room(line) == 0 ? record_room(lemin, line) : 0;
			if_link(line) == 1 ? record_links(lemin, line) : 0;
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
