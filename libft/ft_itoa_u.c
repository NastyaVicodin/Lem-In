/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 22:22:42 by alukyane          #+#    #+#             */
/*   Updated: 2017/10/28 22:22:44 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_length(unsigned long long int n)
{
	int		length;

	length = 0;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

static char		*ft_convert(unsigned long long int n, char *s, int length)
{
	int		len;
	char	*str;

	len = length;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (NULL);
	length--;
	while (n != 0)
	{
		if (str[0] == '-')
			str[length] = (n % 10) * (-1) + '0';
		else
			str[length] = n % 10 + '0';
		n /= 10;
		length--;
	}
	str[len] = '\0';
	s = ft_strcpy(s, str);
	free(str);
	return (s);
}

char			*ft_itoa_u(unsigned long long int n)
{
	int		length;
	char	*str;

	if (n == 0)
	{
		str = (char *)malloc(sizeof(char) * (2));
		if (str == 0)
			return (NULL);
		str = ft_strcpy(str, "0\0");
	}
	else
	{
		length = ft_length(n);
		str = (char *)malloc(sizeof(char) * (length + 1));
		if (str == 0)
			return (NULL);
		str = ft_convert(n, str, length);
	}
	return (str);
}
