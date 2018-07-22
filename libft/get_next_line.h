/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:56:52 by alukyane          #+#    #+#             */
/*   Updated: 2017/12/11 12:56:53 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4096
# include "libft.h"
# include <fcntl.h>

typedef struct		s_gnl
{
	void			*content;
	int				fd;
	size_t			size;
	int				flag;
	struct s_gnl	*next;
}					t_gnl;
int					get_next_line(const int fd, char **line);
#endif
