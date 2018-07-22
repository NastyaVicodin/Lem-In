/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_derot42.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 22:17:01 by alukyane          #+#    #+#             */
/*   Updated: 2017/09/28 22:17:03 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_dencr(char *str)
{
	int i;
	int size;

	i = 0;
	while (str[i] != '\0')
	{
		if ('a' <= str[i] && str[i] <= 'z')
		{
			size = str[i] - 'a';
			if (size < 16)
				str[i] = str[i] + 10;
			else
				str[i] = str[i] - 16;
		}
		if ('A' <= str[i] && str[i] <= 'Z')
		{
			size = str[i] - 'A';
			if (size < 16)
				str[i] = str[i] + 10;
			else
				str[i] = str[i] - 16;
		}
		++i;
	}
	return (str);
}

char		*ft_derot42(char *str, int deep)
{
	if (deep < 0)
		return (NULL);
	if (!(deep && str))
		return (str);
	ft_dencr(str);
	deep--;
	return (ft_derot42(str, deep));
}
