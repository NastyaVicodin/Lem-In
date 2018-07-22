/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 15:44:56 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/01 15:46:14 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_printf	*ft_make_struct(void)
{
	t_printf	*var;
	int			i;

	i = -1;
	var = (t_printf *)malloc(sizeof(t_printf));
	var->flag = (char*)malloc(sizeof(char) * 7);
	while (++i < 6)
		var->flag[i] = 'x';
	var->flag[i] = '\0';
	var->width = 0;
	var->curr = 0;
	var->prec = 0;
	var->res = 0;
	var->dot = 0;
	var->star = 0;
	return (var);
}

static int		ft_new_ind(const char *format, int i, t_printf *var)
{
	if (!(format[i + 1]))
		i++;
	else if (format[var->curr])
		i = var->curr + 1;
	else
		i = var->curr;
	return (i);
}

static t_printf	*find_pr(t_printf *var, const char *f, int i, va_list ap)
{
	i++;
	process(var, f, i, ap);
	return (var);
}

static	int		ft_print_chars(int i, const char *format, int *res)
{
	int		tmp;
	char	*str;

	tmp = i;
	while (format[i] && format[i] != '%')
		i++;
	if (i - tmp)
	{
		str = ft_strsub(format, tmp, i - tmp);
		write(1, str, ft_strlen(str));
		free(str);
		*res += ft_strlen(str);
	}
	return (i);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			res;
	t_printf	*var;

	i = 0;
	res = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			var = ft_make_struct();
			if (format[i + 1])
				find_pr(var, format, i, ap);
			res += var->res;
			i = ft_new_ind(format, i, var);
			free(var);
		}
		else
			i = ft_print_chars(i, format, &res);
	}
	va_end(ap);
	return (res);
}
