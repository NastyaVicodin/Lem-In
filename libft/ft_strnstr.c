/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 10:07:27 by alukyane          #+#    #+#             */
/*   Updated: 2017/09/26 10:09:06 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t len)
{
	int		l1;
	int		l2;
	char	*str;

	str = (char*)s;
	l1 = 0;
	if (find[0] == 0)
		return (str);
	while (str[l1] != '\0' && l1 < (int)len)
	{
		l2 = 0;
		while (str[l1] == find[l2] && l1 < (int)len)
		{
			if (find[l2 + 1] == '\0')
			{
				return (&(*(str + l1 - l2)));
			}
			l1++;
			l2++;
		}
		l1 = l1 - l2;
		l1++;
	}
	return (0);
}
