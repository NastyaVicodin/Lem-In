/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_btod(char *str)
{
	int k;
	int i;

	i = 0;
	k = 0;
	while (str[i])
	{
		k = 2 * k + str[i] - '0';
		++i;
	}
	return (k);
}

int			ft_count_bytes(int chr)
{
	char	*str;
	int		bytes;

	str = ft_itoa_base(chr, 2);
	bytes = ft_strlen(str);
	if (bytes <= 7)
		bytes = 1;
	else if (bytes <= 11)
		bytes = 2;
	else if (bytes <= 16)
		bytes = 3;
	else
		bytes = 4;
	free(str);
	return (bytes);
}

t_printf	*ft_check_align_s(t_printf *var, char *str, int len_origin)
{
	int		i;

	i = -1;
	if (var->flag[0] == '-')
	{
		write(1, str, len_origin);
		while (++i < var->width - len_origin)
			write(1, " ", 1);
	}
	else
	{
		while (++i < var->width - len_origin)
			var->flag[4] == '0' ? write(1, "0", 1) : write(1, " ", 1);
		write(1, str, len_origin);
	}
	var->res += var->width;
	return (var);
}

t_printf	*ft_print_proc(t_printf *var)
{
	if (var->width)
		ft_check_align_s(var, "%", 1);
	else
	{
		write(1, "%", 1);
		var->res += 1;
	}
	return (var);
}

t_printf	*ft_print_str(const char *form, t_printf *var, va_list ap)
{
	if (var->type == 's' || var->type == 'S')
		ft_print_s(var, ap);
	else if (var->type == '%')
		ft_print_proc(var);
	else if (var->type == 'c' || var->type == 'C' || var->type == '0')
		ft_print_c(form, var, ap);
	return (var);
}
