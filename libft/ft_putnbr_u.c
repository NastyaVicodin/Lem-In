/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 14:52:37 by alukyane          #+#    #+#             */
/*   Updated: 2017/09/25 14:52:39 by alukyane         ###   ########.fr       */
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

void			ft_putnbr_u(unsigned long long int nb)
{
	int		j;
	int		*arr;
	int		f;
	char	*str;

	arr = (int *)malloc(sizeof(int) * ft_length(nb));
	j = 0;
	if (nb == 0)
		write(1, "0", 1);
	while (nb != 0)
	{
		arr[j] = (nb % 10);
		nb = nb / 10;
		++j;
	}
	f = 0;
	str = (char *)malloc(sizeof(char) * (j + 1));
	while (j-- > 0)
		str[f++] = arr[j] + '0';
	str[f] = '\0';
	write(1, str, ft_strlen(str));
	free(str);
	free(arr);
}
