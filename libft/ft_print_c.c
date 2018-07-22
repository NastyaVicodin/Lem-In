/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_printf	*ft_check_align_c(t_printf *var, char chr, int len_origin)
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
			var->flag[4] == '0' ? write(1, "0", 1) : write(1, " ", 1);
		write(1, &chr, len_origin);
	}
	var->res += var->width;
	return (var);
}

static t_printf	*ft_print_c_1(const char *format, t_printf *var, va_list ap)
{
	int		len_origin;
	int		chr;

	if (var->type == '0')
	{
		chr = format[var->curr];
		if (!(chr))
			return (var);
	}
	else
	{
		chr = va_arg(ap, int);
		chr = (unsigned char)chr;
	}
	len_origin = 1;
	if (var->width <= len_origin)
	{
		write(1, &chr, 1);
		var->res += len_origin;
	}
	else
		ft_check_align_c(var, chr, len_origin);
	return (var);
}

t_printf		*ft_print_c(const char *format, t_printf *var, va_list ap)
{
	if (ft_strcmp(var->spec, "l") == 0 || var->type == 'C')
		ft_print_c_w(var, ap);
	else
		ft_print_c_1(format, var, ap);
	return (var);
}
