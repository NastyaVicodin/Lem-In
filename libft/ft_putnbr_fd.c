/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 14:52:37 by alukyane          #+#    #+#             */
/*   Updated: 2017/09/25 14:52:39 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int j;
	int arr[10];
	int	f;

	f = 1;
	j = 0;
	if (nb == 0)
		ft_putchar_fd('0', fd);
	if (nb < 0)
	{
		f = -1;
		ft_putchar_fd('-', fd);
	}
	while (nb != 0)
	{
		arr[j] = (nb % 10) * f;
		nb = nb / 10;
		++j;
	}
	while (j-- > 0)
		ft_putchar_fd(arr[j] + '0', fd);
}
