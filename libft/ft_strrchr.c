/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 17:52:46 by alukyane          #+#    #+#             */
/*   Updated: 2017/10/24 17:52:47 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		pos;
	char	*str;

	str = (char *)s;
	pos = -1;
	i = 0;
	while ((char)str[i] != '\0')
	{
		if ((char)str[i] == c)
		{
			pos = i;
		}
		i++;
	}
	if (pos != -1)
		return (&str[pos]);
	if (c == '\0')
		return (str + i);
	return (NULL);
}
