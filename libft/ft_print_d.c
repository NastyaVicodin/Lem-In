/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_printf		*ft_align_sp(t_printf *var, char chr, int len_origin)
{
	int		i;

	i = -1;
	if (var->flag[0] == '-')
	{
		write(1, &chr, len_origin);
		while (++i < var->width - len_origin)
			write(1, " ", 1);
	}
	else
	{
		while (++i < var->width - len_origin)
			write(1, " ", 1);
		write(1, &chr, len_origin);
	}
	var->res += var->width;
	return (var);
}

static	t_printf	*ft_print_d_0(t_printf *var, va_list ap)
{
	long long	digit;
	int			len_origin;
	char		*str;

	digit = va_arg(ap, long long);
	digit = var->spec[0] == '0' ? (int)digit : digit;
	digit = ft_strcmp(var->spec, "h") == 0 ? (short)digit : digit;
	digit = ft_strcmp(var->spec, "hh") == 0 ? (char)digit : digit;
	digit = ft_strcmp(var->spec, "l") == 0 ? (long)digit : digit;
	if (digit == 0 && var->dot == 1 && !(var->prec) && !(var->width))
		return (var);
	if (digit == 0 && var->dot == 1 && !(var->prec) && var->width)
		return (ft_align_sp(var, ' ', 1));
	else
		str = ft_itoa(digit);
	len_origin = ft_strlen(str);
	free(str);
	len_origin = digit < 0 ? len_origin - 1 : len_origin;
	ft_output_d(var, len_origin, digit);
	return (var);
}

t_printf			*ft_print_d(t_printf *var, va_list ap)
{
	if (var->type == 'D')
	{
		if (ft_strcmp(var->spec, "l") == 0)
			var->spec = ft_strdup("ll");
		else
			var->spec = ft_strdup("l");
	}
	if (var->spec[0] == '0' || ft_strcmp(var->spec, "h") == 0 ||
		ft_strcmp(var->spec, "hh") == 0 || ft_strcmp(var->spec, "l") == 0 ||
		ft_strcmp(var->spec, "ll") == 0 || ft_strcmp(var->spec, "j") == 0 ||
		ft_strcmp(var->spec, "z") == 0)
		ft_print_d_0(var, ap);
	return (var);
}
