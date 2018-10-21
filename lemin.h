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

typedef	struct		s_links
{
	char			*name;
	struct s_room	*room;
	struct s_links	*next;
}					t_links;

typedef	struct		s_room
{
	int				x;
	int				y;
	int				level;
	int				ant_passed;
	char			*name;
	struct s_links	*head_link;
	struct s_room	*next;
}					t_room;

typedef struct		s_room_lst
{
	struct s_room		*room;
	struct s_room_lst	*next;
}					t_room_lst;

typedef struct		s_lemin
{
	int				fd;
	int				ant_count;
	int				error;
	char			*start;
	char			*end;
	struct s_room	*head_room;
}					t_lemin;
int					if_all_num(char *line);
t_lemin				*if_valid(t_lemin *lemin, char *line, int flag);
t_lemin				*command_handler(t_lemin *lemin, char *line);
t_lemin				*new_link(t_room *r, t_room *h, char *link, t_lemin *l);
t_lemin				*if_link(t_lemin *lemin, char *line);
t_links				*set_head_link(t_room *search_room);
t_room_lst			*next_avail_room(t_room_lst *avail_rooms);
t_room				*next_srch(t_room *srch, t_links *head_l, t_room_lst *av);
t_room_lst			*change_avail(t_room_lst *av, t_room *head, t_room *srch);
t_lemin				*check_path(t_lemin *lemin);
t_lemin				*make_path(t_lemin *l, t_room *c, t_room *s, t_links *h);
#endif
