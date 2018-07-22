/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 19:51:30 by alukyane          #+#    #+#             */
/*   Updated: 2017/10/24 19:51:32 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*s;
	int				i;

	i = 0;
	s = (unsigned char*)str;
	while (i < (int)n)
	{
		if (s[i] == (unsigned char)c)
		{
			return (&s[i]);
		}
		i++;
	}
	return (NULL);
}
