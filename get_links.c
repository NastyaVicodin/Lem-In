/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_lemin *new_link(t_room *room)
{
	if (room->links->name)
	{
		while (room->links->next != NULL)
			room->links = room->links->next;
		room->links->next = (t_room *)malloc(sizeof(t_links));
		room->links = room->links->next;
		room->links->next = NULL;
	}
	return (lemin);
}

t_lemin	*get_links(t_lemin *lemin, char **arr)
{
	char	*line;
	int		len;

	i = 0;
	while (lemin->rooms->name && i < 2)
	{
		if (ft_strcmp(lemin->rooms->name, arr[0]) == 0)
		{
			len = ft_strlen(arr[0]);
			new_link(lemin->rooms);
			lemin->rooms->links->name = (char *)malloc(sizeof(char) * (len + 1));
			ft_strcpy(lemin->rooms->links->name, arr[0]);
		}
		else if (ft_strcmp(lemin->rooms->name, arr[1]) == 0)
		{
			len = ft_strlen(arr[1]);
			new_link(lemin->rooms);
			lemin->rooms->links->name = (char *)malloc(sizeof(char) * (len + 1));
			ft_strcpy(lemin->rooms->links->name, arr[1]);
		}
	}
	return (lemin);
}
