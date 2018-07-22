/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 19:51:30 by alukyane          #+#    #+#             */
/*   Updated: 2017/10/24 19:51:32 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*memory;

	memory = 0;
	memory = (char *)malloc(sizeof(char) * ((int)size + 1));
	if (memory == 0)
		return (NULL);
	ft_memset(memory, '\0', size + 1);
	return (memory);
}
