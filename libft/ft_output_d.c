/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_printf		*ft_check_pos(t_printf *var, long long digit)
{
	if (var->flag[1] == '+' && digit >= 0)
		write(1, "+", 1);
	else if (var->flag[1] != '+' && var->flag[2] == ' ' && digit >= 0)
		write(1, " ", 1);
	else if (digit < 0)
		write(1, "-", 1);
	return (var);
}

static	int			ft_out_d(t_printf *var, long long digit, int len, int tmp)
{
	int		i;

	i = -1;
	if (var->flag[0] == '-')
	{
		ft_check_pos(var, digit);
		while (++i < var->prec - len)
			write(1, "0", 1);
		ft_putnbr(ABS(digit));
	}
	else
	{
		if (var->flag[4] == '0')
			ft_check_pos(var, digit);
		while (++i < len - tmp)
			if (var->flag[4] == '0' && (!(var->prec) || var->star))
				write(1, "0", 1);
			else
				write(1, " ", 1);
		if (var->flag[4] != '0')
			ft_check_pos(var, digit);
	}
	return (i);
}

static	t_printf	*ft_align(t_printf *var, long long digit, int len, int l_o)
{
	int		i;
	int		tmp;

	tmp = l_o < var->prec ? var->prec : l_o;
	if ((var->flag[1] == '+' && digit >= 0) || (var->flag[1] != '+'
		&& var->flag[2] == ' ' && digit >= 0) || digit < 0)
		tmp++;
	if (var->flag[0] == '-')
	{
		i = ft_out_d(var, digit, l_o, tmp);
		ft_print_end(i, len, tmp, ' ');
	}
	else
	{
		i = ft_out_d(var, digit, len, tmp);
		ft_print_end(i, var->prec, l_o, '0');
		ft_putnbr(ABS(digit));
	}
	var->res = len > tmp ? (var->res + len) : (var->res + tmp);
	return (var);
}

t_printf			*ft_output_d(t_printf *var, int len_orig, long long digit)
{
	int			len;

	len = var->width <= var->prec ? var->prec : var->width;
	if (len < len_orig)
	{
		if ((var->flag[1] == '+' && digit >= 0) || (var->flag[1] != '+'
			&& var->flag[2] == ' ' && digit >= 0) || digit < 0)
			var->res += 1;
		ft_check_pos(var, digit);
		ft_putnbr_u(ABS(digit));
		var->res += len_orig;
	}
	else
		ft_align(var, digit, len, len_orig);
	return (var);
}
