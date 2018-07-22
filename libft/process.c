/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 15:44:56 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/01 15:46:14 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_printf	*calc_w(const char *f, int curr, va_list ap, t_printf *var)
{
	int		i;
	char	*str;

	if (f[curr] == '*')
	{
		var->width = va_arg(ap, int);
		curr++;
	}
	else
	{
		i = curr;
		while (f[curr] && '0' <= f[curr] && f[curr] <= '9')
			curr++;
		if (f[curr] && '0' <= f[curr - 1] && f[curr - 1] <= '9')
		{
			str = ft_strsub(f, i, curr);
			var->width = ft_atoi(str);
			free(str);
		}
		else
			var->width = 0;
	}
	var->curr = curr;
	return (var);
}

static	t_printf	*ft_width(const char *f, int c, va_list ap, t_printf *var)
{
	calc_w(f, c, ap, var);
	if (var->width < 0)
	{
		var->width *= -1;
		var->flag[0] = '-';
	}
	return (var);
}

static	t_printf	*ft_get_prec(const char *form, va_list ap, t_printf *var)
{
	int		i;
	char	*str;

	if (form[var->curr] == '.')
	{
		if (form[var->curr + 1] == '*')
		{
			var->prec = va_arg(ap, int);
			var->curr = var->curr + 2;
			var->star = 1;
		}
		else
		{
			i = var->curr + 1;
			while (form[i] && '0' <= form[i] && form[i] <= '9')
				i++;
			str = ft_strsub(form, var->curr + 1, i);
			var->prec = form[i] ? ft_atoi(str) : -1;
			free(str);
			var->curr = i;
		}
	}
	else
		var->prec = 0;
	return (var);
}

static	t_printf	*ft_put_flag(t_printf *var, char c)
{
	if (c == '-' && var->flag[0] == 'x')
		var->flag[0] = '-';
	else if (c == '+' && var->flag[1] == 'x')
		var->flag[1] = '+';
	else if (c == ' ' && var->flag[2] == 'x')
		var->flag[2] = ' ';
	else if (c == '#' && var->flag[3] == 'x')
		var->flag[3] = '#';
	else if (c == '0' && var->flag[4] == 'x')
		var->flag[4] = '0';
	else if (c == '\'' && var->flag[5] == 'x')
		var->flag[5] = '\'';
	return (var);
}

t_printf			*process(t_printf *var, const char *f, int c, va_list ap)
{
	while (f[c] && (f[c] == '-' || f[c] == '+' || f[c] == ' ' || f[c] == '#'
			|| f[c] == '0' || f[c] == '\''))
	{
		ft_put_flag(var, f[c]);
		c++;
	}
	var->curr = c;
	if (f[c])
		ft_width(f, c, ap, var);
	else
		return (var);
	var->dot = f[var->curr] == '.' ? 1 : 0;
	ft_get_prec(f, ap, var);
	ft_get_data(f, var, ap);
	free(var->flag);
	free(var->spec);
	return (var);
}
