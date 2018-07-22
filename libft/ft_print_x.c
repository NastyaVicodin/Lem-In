/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_printf	*ft_align_x(t_printf *var, char *str, int len, int len_origin)
{
	int		i;
	int		tmp;

	i = -1;
	tmp = len_origin < var->prec ? var->prec : len_origin;
	if (var->flag[3] == '#' && (ft_atoi(str) != 0 || var->type == 'p'))
		tmp += 2;
	if (var->flag[0] == '-')
	{
		i = out_x(var, str, len, len_origin);
		ft_print_end(i, len, tmp, ' ');
	}
	else
	{
		if (var->flag[4] == '0')
			ft_pos_x(var, str, len, len_origin);
		while (++i < len - tmp)
			var->flag[4] == '0' ? write(1, "0", 1) : write(1, " ", 1);
		if (var->flag[4] != '0')
			ft_pos_x(var, str, len, len_origin);
		ft_print_end(i, var->prec, len_origin, '0');
		write(1, str, len_origin);
	}
	var->res = len > tmp ? (var->res + len) : (var->res + tmp);
	return (var);
}

static t_printf	*ft_output_x(t_printf *var, char *str)
{
	int			len;
	int			len_origin;

	len_origin = ft_strlen(str);
	if (var->type == 'X')
		ft_allupper(str, len_origin);
	len = var->width <= var->prec ? var->prec : var->width;
	if (len < len_origin)
	{
		ft_pos_x(var, str, len, len_origin);
		write(1, str, len_origin);
		var->res += len_origin;
	}
	else
		ft_align_x(var, str, len, len_origin);
	return (var);
}

static t_printf	*ft_print_x_l(t_printf *var, va_list ap)
{
	long long	digit;
	char		*str;

	digit = va_arg(ap, long long);
	digit = digit ? digit : (unsigned int)digit;
	digit = var->spec[0] == '0' ? (unsigned int)digit : digit;
	digit = ft_strcmp(var->spec, "h") == 0 ? (unsigned short)digit : digit;
	digit = ft_strcmp(var->spec, "hh") == 0 ? (unsigned char)digit : digit;
	digit = ft_strcmp(var->spec, "l") == 0 ? (unsigned long)digit : digit;
	if (digit == 0 && var->dot == 1 && !(var->prec) && !(var->width))
		return (var);
	if (digit == 0 && var->dot == 1 && !(var->prec) && var->width)
		str = ft_strdup(" ");
	else
		str = ft_itoa_base(digit, 16);
	ft_output_x(var, str);
	free(str);
	return (var);
}

static t_printf	*ft_print_x_u(t_printf *var, va_list ap)
{
	unsigned long long	digit;
	char				*str;

	digit = va_arg(ap, unsigned long long);
	digit = var->spec[0] == '0' ? (unsigned int)digit : digit;
	digit = ft_strcmp(var->spec, "h") == 0 ? (unsigned short)digit : digit;
	digit = ft_strcmp(var->spec, "hh") == 0 ? (unsigned char)digit : digit;
	digit = ft_strcmp(var->spec, "l") == 0 ? (unsigned long)digit : digit;
	if (digit == 0 && var->dot == 1 && !(var->prec) && !(var->width))
	{
		var->type == 'p' ? ft_pos_x(var, "", 0, 1) : 0;
		return (var);
	}
	if (digit == 0 && var->dot == 1 && !(var->prec) && var->width)
		str = var->type == 'p' ? ft_strdup("") : ft_strdup(" ");
	else
		str = ft_itoa_base(digit, 16);
	ft_output_x(var, str);
	free(str);
	return (var);
}

t_printf		*ft_print_x(t_printf *var, va_list ap)
{
	if (var->type == 'p')
	{
		var->flag[3] = '#';
		free(var->spec);
		var->spec = ft_strdup("z");
	}
	if (var->spec[0] == '0' || ft_strcmp(var->spec, "h") == 0 ||
		ft_strcmp(var->spec, "hh") == 0 || ft_strcmp(var->spec, "l") == 0 ||
		ft_strcmp(var->spec, "ll") == 0)
		ft_print_x_l(var, ap);
	else if (ft_strcmp(var->spec, "j") == 0 || ft_strcmp(var->spec, "z") == 0)
		ft_print_x_u(var, ap);
	return (var);
}
