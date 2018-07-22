/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_positive_power.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 20:14:08 by alukyane          #+#    #+#             */
/*   Updated: 2017/09/23 20:15:04 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_positive_power(int nb, int power)
{
	int c;

	c = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 0)
	{
		c *= nb;
		power--;
	}
	return (c);
}
