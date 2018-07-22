/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_printf	*ft_align_u(t_printf *var, unsigned long long d, int l, int lo)
{
	int		i;
	int		tmp;

	i = -1;
	tmp = lo < var->prec ? var->prec : lo;
	if (var->flag[0] == '-')
	{
		while (++i < var->prec - lo)
			write(1, "0", 1);
		ft_putnbr_u(d);
		ft_print_end(i, l, tmp, ' ');
	}
	else
	{
		while (++i < l - tmp)
			var->flag[4] == '0' ? write(1, "0", 1) : write(1, " ", 1);
		ft_print_end(i, var->prec, lo, '0');
		ft_putnbr_u(d);
	}
	var->res = l > tmp ? (var->res + l) : (var->res + tmp);
	return (var);
}

static t_printf	*output_u(t_printf *var, unsigned long long digit)
{
	int					len;
	int					len_origin;
	char				*str;

	str = ft_itoa_u(digit);
	len_origin = ft_strlen(str);
	free(str);
	len = var->width <= var->prec ? var->prec : var->width;
	if (len < len_origin)
	{
		ft_putnbr_u(digit);
		var->res += len_origin;
	}
	else
		ft_align_u(var, digit, len, len_origin);
	return (var);
}

static t_printf	*ft_print_u_0(t_printf *var, va_list ap)
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
	{
		str = ft_strdup(" ");
		ft_check_align_s(var, str, 1);
		free(str);
		return (var);
	}
	else
		output_u(var, digit);
	return (var);
}

t_printf		*ft_print_u(t_printf *var, va_list ap)
{
	if (var->type == 'U')
	{
		if (ft_strcmp(var->spec, "l") == 0)
		{
			free(var->spec);
			var->spec = ft_strdup("ll");
		}
		else
		{
			free(var->spec);
			var->spec = ft_strdup("l");
		}
	}
	if (var->spec[0] == '0' || ft_strcmp(var->spec, "h") == 0 ||
		ft_strcmp(var->spec, "hh") == 0 || ft_strcmp(var->spec, "l") == 0 ||
		ft_strcmp(var->spec, "ll") == 0 || ft_strcmp(var->spec, "j") == 0 ||
		ft_strcmp(var->spec, "z") == 0)
		ft_print_u_0(var, ap);
	return (var);
}
