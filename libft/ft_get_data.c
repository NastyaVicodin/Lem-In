/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 15:44:56 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/01 15:46:14 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_printf	*ft_strcut_spec(const char *format, t_printf *var)
{
	int		len;
	char	*str;
	int		i;
	int		start;

	i = 0;
	start = var->curr;
	if ((format[start] == 'l' && format[start + 1] == 'l') ||
		(format[start] == 'h' && format[start + 1] == 'h'))
		len = 2;
	else
		len = 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
		str[i++] = format[start++];
	str[i] = '\0';
	var->spec = ft_strdup(str);
	free(str);
	var->curr = var->curr + len;
	return (var);
}

static t_printf	*ft_get_spec(const char *format, t_printf *var)
{
	int		j;
	char	*str;

	j = 0;
	str = ft_strdup("lhjz");
	while (format[var->curr] && str[j] && format[var->curr] != str[j])
	{
		if (format[var->curr] == str[j])
			break ;
		j++;
	}
	if (format[var->curr] && str[j] && format[var->curr] == str[j])
		ft_strcut_spec(format, var);
	else
		var->spec = ft_strdup("0");
	free(str);
	return (var);
}

static t_printf	*ft_get_type(const char *format, t_printf *var)
{
	int		j;
	char	*str;

	j = 0;
	str = ft_strdup("sSpdDioOuUxXcCbB%");
	while (format[var->curr] && str[j] && format[var->curr] != str[j])
	{
		if (format[var->curr] == str[j])
			break ;
		j++;
	}
	if (format[var->curr] && str[j] && format[var->curr] == str[j])
		var->type = format[var->curr];
	else
		var->type = '0';
	free(str);
	return (var);
}

static t_printf	*ft_print_part(const char *format, t_printf *var, va_list ap)
{
	int i;

	i = 0;
	if (var->type == 'd' || var->type == 'i' || var->type == 'o' ||
		var->type == 'O' || var->type == 'x' || var->type == 'X' ||
		var->type == 'D' || var->type == 'u' || var->type == 'U' ||
		var->type == 'p' || var->type == 'b' || var->type == 'B')
		ft_print_nbr(var, ap);
	else if (var->type == 's' || var->type == 'S' || var->type == 'c' ||
		var->type == 'C' || var->type == '%' || var->type == '0')
		ft_print_str(format, var, ap);
	return (var);
}

int				ft_get_data(const char *format, t_printf *var, va_list ap)
{
	int		res;

	if (format[var->curr])
	{
		ft_get_spec(format, var);
		ft_get_type(format, var);
		ft_print_part(format, var, ap);
		res = var->res;
	}
	else
		res = -1;
	return (var->res);
}
