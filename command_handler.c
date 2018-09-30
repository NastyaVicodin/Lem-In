/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_lemin			*command_handler(t_lemin *lemin, char *line)
{
	char *line_room;

	if (ft_strcmp(line, "##start") == 0)
	{
		if (lemin->start == NULL && get_next_line(0, &line_room))
		{
			if_valid(lemin, line_room, 1);
			free(line_room);
		}
		else
			lemin->error = -1;
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		if (lemin->end == NULL && get_next_line(0, &line_room))
		{
			if_valid(lemin, line_room, 2);
			free(line_room);
		}
		else
			lemin->error = -1;
	}
	free(line);
	return (lemin);
}
