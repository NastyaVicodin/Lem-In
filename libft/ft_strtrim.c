/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 19:51:30 by alukyane          #+#    #+#             */
/*   Updated: 2017/10/24 19:51:32 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_record_str(char const *s, int i, int end)
{
	char	*str;
	int		j;

	j = 0;
	str = (char *)malloc(sizeof(char) * (end - i + 2));
	if (str == 0)
		return (NULL);
	while (i < end + 1)
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		end;
	char	*str;

	i = 0;
	if (s)
	{
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
			i++;
		end = ft_strlen(s) - 1;
		while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
			&& end >= 0)
			end--;
		if (i == (int)ft_strlen(s))
		{
			str = (char *)malloc(1);
			return (ft_strcpy(str, "\0"));
		}
		return (ft_record_str(s, i, end));
	}
	return (NULL);
}
