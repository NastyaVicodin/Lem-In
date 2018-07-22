/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 20:30:29 by alukyane          #+#    #+#             */
/*   Updated: 2017/09/28 15:37:05 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*res;

	i = ft_strlen(src);
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (res == 0)
		return (NULL);
	i = 0;
	res = ft_strcpy(res, src);
	return (res);
}
