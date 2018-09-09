/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 10:07:27 by alukyane          #+#    #+#             */
/*   Updated: 2017/09/26 10:09:06 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(char const *s, char c)
{
	int		i;
	int		words;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c) || (s[i - 1] == c && s[i] != c))
			++words;
		i++;
	}
	return (words);
}

static char		*ft_record_word(const char *s, char c, int i)
{
	char	*new_word;
	int		start;
	int		length;

	start = 0;
	length = 0;
	start = i;
	while (s[i] != c && s[i] != '\0')
	{
		++length;
		i++;
	}
	i--;
	new_word = ft_strsub(s, start, length);
	return (new_word);
}

static char		**ft_make_array(char const *s, int words, char c)
{
	char	**array;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(array = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c) || (s[i - 1] == c && s[i] != c))
		{
			array[j] = ft_record_word(s, c, i);
			j++;
		}
		i++;
	}
	array[j] = NULL;
	return (array);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		words;

	if (s)
	{
		words = ft_count_words(s, c);
		array = ft_make_array(s, words, c);
		if (array != 0)
			return (array);
	}
	return (NULL);
}
