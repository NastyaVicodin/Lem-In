/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:24:53 by alukyane          #+#    #+#             */
/*   Updated: 2017/11/27 15:24:54 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_length_n(unsigned long long n, int base)
{
	int		length;

	length = 0;
	while (n != 0)
	{
		n /= base;
		length++;
	}
	return (length);
}

static void		ft_calc(unsigned long long int val, int base, char *ans, int *p)
{
	char	*arr;
	int		i;
	char	c;

	c = 'a';
	i = -1;
	if (val >= (unsigned long long)base)
		ft_calc(val / base, base, ans, p);
	arr = (char *)malloc(sizeof(char) * 17);
	while (++i < 10)
		arr[i] = i + '0';
	i--;
	while (++i < 16)
		arr[i] = c++;
	arr[i] = '\0';
	ans[(*p)++] = arr[val % base];
	free(arr);
}

char			*ft_itoa_base(unsigned long long int value, int base)
{
	char	*ans;
	int		p;

	p = 0;
	if (base < 2 || base > 16 ||
		!(ans = (char *)malloc(sizeof(char) * ft_length_n(value, base) + 1)))
		return (NULL);
	ft_calc(value, base, ans, &p);
	ans[p] = '\0';
	return (ans);
}
