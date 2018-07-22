/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 19:51:30 by alukyane          #+#    #+#             */
/*   Updated: 2017/10/24 19:51:32 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*memory;

	memory = 0;
	if (size == 0)
		return (memory);
	memory = (void *)malloc(size);
	if (memory == 0)
		return (NULL);
	ft_bzero(memory, size);
	return (memory);
}
