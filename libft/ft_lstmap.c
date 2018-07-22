/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:48:48 by alukyane          #+#    #+#             */
/*   Updated: 2017/10/02 18:48:49 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*linknew;
	t_list	*curr;

	linknew = NULL;
	if (lst && f)
	{
		curr = f(ft_lstnew(lst->content, lst->content_size));
		linknew = curr;
		lst = lst->next;
		while (lst)
		{
			curr->next = f(ft_lstnew(lst->content, lst->content_size));
			lst = lst->next;
			curr = curr->next;
		}
	}
	return (linknew);
}
