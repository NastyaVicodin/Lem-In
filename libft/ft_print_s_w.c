/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s_w.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_print_c_ws(int chr, char *new)
{
	char	*str;
	int		bytes;
	char	*tmp;

	str = ft_itoa_base(chr, 2);
	bytes = ft_strlen(str);
	if (bytes <= 7)
		str = ft_make_wchar(str, 1, bytes);
	else if (bytes <= 11)
		str = ft_make_wchar(str, 2, bytes);
	else if (bytes <= 16)
		str = ft_make_wchar(str, 3, bytes);
	else
		str = ft_make_wchar(str, 4, bytes);
	tmp = ft_strjoin(new, str);
	free(str);
	free(new);
	return (tmp);
}

static t_printf		*ft_print_wide_str(t_printf *var, int len, t_unichar *unch)
{
	int		j;
	int		i;
	char	*k;
	int		n;

	j = 0;
	n = 0;
	i = 0;
	while (j < unch->len && unch->arr_ind[j] && i + unch->arr_ind[j] <= len)
	{
		k = ft_strsub(unch->new_s, n, unch->arr_ind[j]);
		write(1, k, ft_strlen(k));
		var->res += unch->arr_ind[j];
		i += unch->arr_ind[j];
		j++;
		n = i;
		free(k);
	}
	return (var);
}

static t_printf		*ft_align_s_w(t_printf *var, t_unichar *unch, int l_or)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (unch->arr_ind[j] && i + unch->arr_ind[j] <= l_or)
		i += unch->arr_ind[j++];
	j = -1;
	if (var->flag[0] == '-')
	{
		ft_print_wide_str(var, i, unch);
		while (++j < var->width - i)
			write(1, " ", 1);
	}
	else
	{
		while (++j < var->width - i)
			var->flag[4] == '0' ? write(1, "0", 1) : write(1, " ", 1);
		ft_print_wide_str(var, i, unch);
	}
	var->res += var->width - i;
	return (var);
}

static t_unichar	*ft_make_unchar(t_unichar *unchar, wchar_t *str)
{
	int i;

	i = 0;
	unchar->new_s = ft_memalloc(0);
	while (str[i])
	{
		unchar->new_s = ft_print_c_ws(str[i], unchar->new_s);
		i++;
	}
	unchar->arr_ind = (int *)malloc(sizeof(int) * i);
	unchar->len = i;
	i = 0;
	while (str[i])
	{
		unchar->arr_ind[i] = ft_count_bytes(str[i]);
		i++;
	}
	return (unchar);
}

t_printf			*ft_print_s_w(t_printf *var, va_list ap)
{
	int			len_origin;
	wchar_t		*str;
	t_unichar	*unchar;

	str = va_arg(ap, wchar_t *);
	if (!str)
	{
		ft_print_s_s(var, ap);
		return (var);
	}
	unchar = (t_unichar *)malloc(sizeof(t_unichar));
	unchar = ft_make_unchar(unchar, str);
	len_origin = ft_strlen(unchar->new_s);
	if (var->dot == 1)
		len_origin = var->prec >= len_origin ? len_origin : var->prec;
	if (var->width <= len_origin)
		ft_print_wide_str(var, len_origin, unchar);
	else
		ft_align_s_w(var, unchar, len_origin);
	free(unchar->new_s);
	free(unchar->arr_ind);
	free(unchar);
	return (var);
}
