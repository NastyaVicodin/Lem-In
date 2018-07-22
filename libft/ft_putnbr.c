/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 14:52:37 by alukyane          #+#    #+#             */
/*   Updated: 2017/09/25 14:52:39 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_length(long long int n)
{
	int		length;

	length = 0;
	if (n < 0)
	{
		n *= -1;
		length++;
	}
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

static void		ft_printnbr(int *arr, int j)
{
	char	*str;
	int		f;

	f = 0;
	str = (char *)malloc(sizeof(char) * (j + 1));
	while (j-- > 0)
	{
		str[f++] = arr[j] + '0';
	}
	str[f] = '\0';
	write(1, str, ft_strlen(str));
	free(str);
}

void			ft_putnbr(long long int nb)
{
	int j;
	int *arr;
	int	f;

	arr = (int *)malloc(sizeof(int) * ft_length(nb));
	f = 1;
	j = 0;
	if (nb == 0)
		write(1, "0", 1);
	if (nb < 0)
	{
		f = -1;
		write(1, "-", 1);
	}
	while (nb != 0)
	{
		arr[j] = (nb % 10) * f;
		nb = nb / 10;
		++j;
	}
	ft_printnbr(arr, j);
	free(arr);
}
