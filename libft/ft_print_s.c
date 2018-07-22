/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_printf	*ft_print_s_s(t_printf *var, va_list ap)
{
	int		len_origin;
	char	*str;

	if (var->type == 's' && ft_strcmp(var->spec, "l") != 0)
	{
		str = va_arg(ap, char*);
		if (!str)
			str = ft_strdup("(null)");
		else
			str = ft_strdup(str);
	}
	else
		str = ft_strdup("(null)");
	len_origin = ft_strlen(str);
	if (var->dot == 1 && var->prec >= 0)
		len_origin = var->prec >= len_origin ? len_origin : var->prec;
	if (var->width <= len_origin)
	{
		write(1, str, len_origin);
		var->res += len_origin;
	}
	else
		ft_check_align_s(var, str, len_origin);
	free(str);
	return (var);
}

t_printf	*ft_print_s(t_printf *var, va_list ap)
{
	if (var->type == 'S' || ft_strcmp(var->spec, "l") == 0)
		ft_print_s_w(var, ap);
	else
		ft_print_s_s(var, ap);
	return (var);
}
