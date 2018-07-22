/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:11:07 by alukyane          #+#    #+#             */
/*   Updated: 2017/10/30 15:11:08 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*linknew;

	linknew = (t_list *)malloc(sizeof(t_list));
	if (linknew == 0)
		return (NULL);
	if (content)
	{
		linknew->content = malloc(content_size);
		if (linknew->content == 0)
			return (NULL);
		ft_memcpy(linknew->content, content, content_size);
		linknew->content_size = content_size;
	}
	else
	{
		linknew->content_size = 0;
		linknew->content = NULL;
	}
	linknew->next = NULL;
	return (linknew);
}
