/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_printf	*ft_check_pos_o(t_printf *var)
{
	if (var->flag[3] == '#')
		write(1, "0", 1);
	return (var);
}

static int	calc_tmp(int len_or, t_printf *var, int digit)
{
	int tmp;

	tmp = len_or < var->prec ? var->prec : len_or;
	if (var->flag[3] == '#' && digit != 0 && len_or >= var->prec)
		tmp++;
	return (tmp);
}

t_printf	*ft_align_o(t_printf *var, char *str, int len, int len_or)
{
	int		i;
	int		tmp;

	i = -1;
	tmp = calc_tmp(len_or, var, ft_atoi(str));
	var->prec = var->flag[3] == '#' ? var->prec - 1 : var->prec;
	if (var->flag[0] == '-')
	{
		ft_atoi(str) ? ft_check_pos_o(var) : 0;
		while (++i < var->prec - len_or)
			write(1, "0", 1);
		write(1, str, len_or);
		ft_print_end(i, len, tmp, ' ');
	}
	else
	{
		while (++i < len - tmp)
			var->flag[4] == '0' ? write(1, "0", 1) : write(1, " ", 1);
		ft_atoi(str) ? ft_check_pos_o(var) : 0;
		ft_print_end(i, var->prec, len_or, '0');
		write(1, str, len_or);
	}
	var->res = len > tmp ? (var->res + len) : (var->res + tmp);
	return (var);
}
