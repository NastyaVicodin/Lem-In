/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_w.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_revcpy(char *dst, char *src)
{
	int len;
	int i;
	int start;

	len = ft_strlen(src);
	start = 8 - len;
	i = 0;
	while (start < 8)
	{
		dst[start] = src[i];
		start++;
		i++;
	}
	i = 0;
	while (dst[i])
	{
		dst[i] = dst[i] == 'x' ? '0' : dst[i];
		i++;
	}
	i = ft_btod(dst);
	return (i);
}

static char	ft_start_wch(char *str, int l)
{
	int		i;
	char	*tmp;
	char	res;

	tmp = ft_strdup("xxxxxxxx");
	i = 0;
	if (l != 1)
		while (i < l)
		{
			tmp[i] = '1';
			i++;
		}
	tmp[i] = '0';
	res = ft_revcpy(tmp, str);
	free(tmp);
	return (res);
}

char		*ft_fill_wchar(char *wchar, int bytes, int l, char *str)
{
	int		ind;
	char	*tmp;
	char	*tmp2;
	int		ij[2];

	ij[0] = 0;
	ij[1] = -1;
	tmp2 = ft_strdup("10xxxxxx");
	while (++ij[1] < l - 1)
	{
		ij[0]++;
		ind = (bytes - ij[0] * 6) ? (bytes - ij[0] * 6) : 0;
		tmp = ft_strsub(str, ind, 6);
		wchar[ij[1]] = ft_revcpy(tmp2, tmp);
		free(tmp);
	}
	ind = l != 1 ? (bytes - ij[0] * 6) : bytes;
	tmp = ft_strsub(str, 0, ind);
	wchar[ij[1]] = ft_start_wch(tmp, l);
	wchar[ij[1] + 1] = '\0';
	free(tmp);
	free(tmp2);
	return (wchar);
}

char		*ft_make_wchar(char *str, int l, int bytes)
{
	char	*wchar;

	wchar = (char*)malloc(sizeof(char) * (l + 1));
	wchar = ft_fill_wchar(wchar, bytes, l, str);
	wchar = ft_strrev(wchar);
	free(str);
	return (wchar);
}

t_printf	*ft_print_c_w(t_printf *var, va_list ap)
{
	int		len_origin;
	int		chr;
	char	*str;
	int		bytes;

	chr = va_arg(ap, int);
	str = ft_itoa_base(chr, 2);
	bytes = ft_strlen(str);
	str = ft_make_wchar(str, ft_count_bytes(chr), bytes);
	len_origin = ft_strlen(str) ? ft_strlen(str) : 1;
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
