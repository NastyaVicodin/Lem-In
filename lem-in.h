/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
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
	struct s_links	*cur_link;
	struct s_room	*next;
}					t_room;

typedef struct		s_lemin
{
	int				ant_count;
	int				error;
	char			*start;
	char			*end;
	struct s_room	*rooms;
	struct s_room	*cur_room;
}					t_lemin;
#endif
