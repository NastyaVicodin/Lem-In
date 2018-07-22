/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 10:07:27 by alukyane          #+#    #+#             */
/*   Updated: 2017/09/26 10:09:06 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	int		l1;
	int		l2;
	char	*s;

	s = (char *)str;
	l1 = 0;
	if (to_find[0] == 0)
		return (s);
	while (str[l1] != '\0')
	{
		l2 = 0;
		while (s[l1] == to_find[l2])
		{
			if (to_find[l2 + 1] == '\0')
			{
				return (&(*(s + l1 - l2)));
			}
			l1++;
			l2++;
		}
		l1 = l1 - l2;
		l1++;
	}
	return (0);
}
