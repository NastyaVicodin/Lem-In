/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_end(int i, int len, int tmp, char c)
{
	i = -1;
	while (++i < len - tmp)
		write(1, &c, 1);
}

t_printf	*ft_pos_x(t_printf *var, char *str, int len, int len_orig)
{
	if (var->flag[3] == '#' && ((ft_strcmp(str, "0") != 0 && var->type != 'p')
		|| var->type == 'p'))
	{
		write(1, "0", 1);
		if (var->type == 'X')
			write(1, "X", 1);
		else if (var->type == 'x' || var->type == 'p')
			write(1, "x", 1);
		if (len < len_orig)
			var->res += 2;
	}
	return (var);
}

int			out_x(t_printf *var, char *str, int len, int len_origin)
{
	int i;

	i = -1;
	ft_pos_x(var, str, len, len_origin);
	while (++i < var->prec - len_origin)
		write(1, "0", 1);
	write(1, str, len_origin);
	return (i);
}

t_printf	*ft_print_nbr(t_printf *var, va_list ap)
{
	if (var->type == 'd' || var->type == 'D' || var->type == 'i')
		ft_print_d(var, ap);
	else if (var->type == 'u' || var->type == 'U')
		ft_print_u(var, ap);
	else if (var->type == 'o' || var->type == 'O')
		ft_print_o(var, ap);
	else if (var->type == 'b' || var->type == 'B')
		ft_print_b(var, ap);
	else if (var->type == 'x' || var->type == 'X')
		ft_print_x(var, ap);
	else if (var->type == 'p')
		ft_print_x(var, ap);
	return (var);
}
