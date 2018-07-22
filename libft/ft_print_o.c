/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_printf			*ft_output_o(t_printf *var, char *str)
{
	int			len;
	int			len_origin;

	len_origin = ft_strlen(str);
	len = var->width <= var->prec ? var->prec : var->width;
	if (len < len_origin)
	{
		if (ft_atoi(str) != 0)
		{
			ft_check_pos_o(var);
			if (var->flag[3] == '#')
				var->res += 1;
		}
		write(1, str, len_origin);
		var->res += len_origin;
	}
	else
		ft_align_o(var, str, len, len_origin);
	return (var);
}

static	t_printf	*ft_print_o_l(t_printf *var, va_list ap)
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
	{
		var->res = var->flag[3] == '#' ? var->res + 1 : var->res;
		return (ft_check_pos_o(var));
	}
	if (digit == 0 && var->dot == 1 && !(var->prec) && var->width)
		str = ft_strdup(" ");
	else
		str = ft_itoa_base(digit, 8);
	ft_output_o(var, str);
	free(str);
	return (var);
}

static	t_printf	*ft_print_o_u(t_printf *var, va_list ap)
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
		var->res = var->flag[3] == '#' ? var->res + 1 : var->res;
		return (ft_check_pos_o(var));
	}
	if (digit == 0 && var->dot == 1 && !(var->prec) && var->width)
		str = ft_strdup(" ");
	else
		str = ft_itoa_base(digit, 8);
	ft_output_o(var, str);
	free(str);
	return (var);
}

t_printf			*ft_print_o(t_printf *var, va_list ap)
{
	if (var->type == 'O')
	{
		if (ft_strcmp(var->spec, "l") == 0)
			var->spec = ft_strdup("ll");
		else
			var->spec = ft_strdup("l");
	}
	if (var->spec[0] == '0' || ft_strcmp(var->spec, "h") == 0 ||
		ft_strcmp(var->spec, "hh") == 0 || ft_strcmp(var->spec, "l") == 0 ||
		ft_strcmp(var->spec, "ll") == 0)
		ft_print_o_l(var, ap);
	else if (ft_strcmp(var->spec, "j") == 0 || ft_strcmp(var->spec, "z") == 0)
		ft_print_o_u(var, ap);
	return (var);
}
