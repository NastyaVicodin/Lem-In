/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 18:30:21 by alukyane          #+#    #+#             */
/*   Updated: 2017/09/25 18:30:23 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_how_long(long long int k, char c, size_t len)
{
	if (k <= 9223372036854775807 && k >= 0 && len <= 19)
	{
		if (c == '-')
			k *= -1;
		return (k);
	}
	else if (c == '-')
		k = 0;
	else
		k = -1;
	return (k);
}

int				ft_atoi(const char *str)
{
	int				i;
	int				min;
	long long int	k;
	size_t			len;

	i = 0;
	k = 0;
	len = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		++i;
	min = i;
	if (str[min] == '+' || str[min] == '-')
		++i;
	while (str[i] != '\0' && '0' <= str[i] && str[i] <= '9')
	{
		k = 10 * k + str[i] - '0';
		++len;
		++i;
	}
	k = ft_check_how_long(k, str[min], len);
	return (k);
}
