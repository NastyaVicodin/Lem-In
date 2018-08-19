/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:59:45 by alukyane          #+#    #+#             */
/*   Updated: 2017/10/24 16:59:47 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft/libft.h"
# include <stdio.h>

typedef  struct		s_links
{
	char			*name;
	struct s_links	*next;
}					t_links;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	struct s_links	*links;
	struct s_room	*next;
}					t_room;

typedef struct		s_lemin
{
	int				ant_count;
	int				error;
	char			*start;
	char			*end;
	struct s_room	*head_room;
	struct s_room	*rooms;
}					t_lemin;
int					if_all_num(char *line);
int					if_exist(t_lemin *lemin, char **arr);
int					if_exist_rooms(t_lemin *lemin, char **arr);
t_lemin				*line_handler(t_lemin *lemin, char **arr);
t_lemin				*if_valid(t_lemin *lemin, char *line);
t_lemin				*command_handler(t_lemin *lemin, char *line);
t_lemin				*if_link(t_lemin *lemin, char *line);
#endif
