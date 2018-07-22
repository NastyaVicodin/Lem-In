/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 22:17:01 by alukyane          #+#    #+#             */
/*   Updated: 2017/09/28 22:17:03 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_encr(char *str)
{
	int i;
	int size;

	i = 0;
	while (str[i] != '\0')
	{
		if ('a' <= str[i] && str[i] <= 'z')
		{
			size = 'z' - str[i];
			if (size >= 16)
				str[i] = str[i] + 16;
			else
				str[i] = 'a' + 15 - size;
		}
		if ('A' <= str[i] && str[i] <= 'Z')
		{
			size = 'Z' - str[i];
			if (size >= 16)
				str[i] = str[i] + 16;
			else
				str[i] = 'A' + 15 - size;
		}
		++i;
	}
	return (str);
}

char		*ft_rot42(char *str, int deep)
{
	if (deep < 0)
		return (NULL);
	if (!(deep && str))
		return (str);
	ft_encr(str);
	deep--;
	return (ft_rot42(str, deep));
}
