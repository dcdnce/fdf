/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:09:54 by pforesti          #+#    #+#             */
/*   Updated: 2021/10/26 15:25:57 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_word_len(char const *s, int start, char c)
{
	int	i;

	i = 0;
	while (s[start + i] != c && s[i])
		i++;
	return (i);
}

static int	ft_word_count(char const *s, char c)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			wc += 1;
		while (s[i] != c && s[i])
			i++;
	}
	return (wc);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;
	int		wc;

	if (!s)
		return (NULL);
	dest = malloc(sizeof(*dest) * (ft_word_count(s, c) + 1));
	if (!dest)
		return (NULL);
	dest[ft_word_count(s, c)] = NULL;
	wc = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			dest[wc] = ft_substr(s, i, (ft_word_len(s, i, c)));
			wc += 1;
		}
		while (s[i] != c && s[i])
			i++;
	}
	return (dest);
}
