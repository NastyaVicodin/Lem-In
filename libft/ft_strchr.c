/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 17:38:35 by alukyane          #+#    #+#             */
/*   Updated: 2017/10/24 17:38:35 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	while ((char)str[i] != '\0')
	{
		if ((char)str[i] == c)
			return (&str[i]);
		i++;
	}
	if (c == '\0')
		return (str + i);
	return (NULL);
}
