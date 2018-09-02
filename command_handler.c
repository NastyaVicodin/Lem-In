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

static t_lemin	*start_handler(t_lemin *lemin)
{
	char *line;

	if (lemin->start == NULL && get_next_line(0, &line))
	{
		if_valid(lemin, line);
		free(line);
	}
	else
		lemin->error = -1;
	return (lemin);
}

static t_lemin	*end_handler(t_lemin *lemin)
{
	char *line;

	if (lemin->end == NULL && get_next_line(0, &line))
	{
		if_valid(lemin, line);
		free(line);
	}
	else
		lemin->error = -1;
	return (lemin);
}

t_lemin			*command_handler(t_lemin *lemin, char *line)
{
	int len;

	if (ft_strcmp(line, "##start") == 0)
	{
		start_handler(lemin);
		if (lemin->error == 0)
		{
			len = ft_strlen(lemin->rooms->name);
			lemin->start = (char *)malloc(sizeof(char) * (len + 1));
			ft_strcpy(lemin->start, lemin->rooms->name);
		}
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		end_handler(lemin);
		if (lemin->error == 0)
		{
			len = ft_strlen(lemin->rooms->name);
			lemin->end = (char *)malloc(sizeof(char) * (len + 1));
			ft_strcpy(lemin->end, lemin->rooms->name);
		}
	}
	free(line);
	system("leaks lem-in");
	return (lemin);
}
