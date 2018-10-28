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

#include "visual.h"

static void	print_error(void)
{
	write(1, RED, 6);
	write(1, "*-* *-* *-* *-* *-* *-* *-* *-* *-* *-* *-*\n", 44);
	write(1, "   Are you smart enough to put valid map?  \n", 44);
	write(1, "*-* *-* *-* *-* *-* *-* *-* *-* *-* *-* *-*\n", 44);
	write(1, RES, 5);
}

static void	print_welcome(void)
{
	write(1, GRN, 6);
	write(1, "+-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+\n", 44);
	write(1, "         W   E   L   C   O   M   E         \n", 44);
	write(1, "  TO   THE   BEST   ANT'S   FARM   EVER !  \n", 44);
	write(1, "+-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+\n", 44);
	write(1, RES, 5);
	write(1, "\n\n", 2);
}

static void	choose_color(int i)
{
	if (i % 5 == 0)
		write(1, YEL, 6);
	else if (i % 5 == 1)
		write(1, RED, 6);
	else if (i % 5 == 2)
		write(1, MAG, 6);
	else if (i % 5 == 3)
		write(1, CYN, 6);
	else
		write(1, GRN, 6);
}

static void	print_link(char *line, int num)
{
	char	**arr;
	char	**arr_line;
	char	*room_name;
	int		i;

	choose_color(num);
	arr = ft_strsplit(line, 'L');
	i = -1;
	while (arr[++i])
	{
		arr_line = ft_strsplit(arr[i], '-');
		room_name = ft_strsub(arr_line[1], 0, ft_strlen(arr_line[1]));
		write(1, "*::*::*::*::*::*::*\n", 20);
		write(1, "  I am Mister Ant #", 19);
		ft_putstr(arr_line[0]);
		ft_putstr(" and I'm going to room ");
		ft_putstr(room_name);
		write(1, "\n*::*::*::*::*::*::*\n", 21);
		free(room_name);
		free_array(arr_line);
	}
	write(1, RES, 5);
	free_array(arr);
}

int			main(void)
{
	char	*line;
	int		i;

	i = 0;
	print_welcome();
	while (get_next_line(0, &line))
	{
		if (line[0] == 'E')
		{
			print_error();
			free(line);
			break ;
		}
		else if (line[0] == 'L')
		{
			print_link(line, i);
			i++;
		}
		free(line);
	}
	return (0);
}
