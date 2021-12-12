/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 08:52:43 by pforesti          #+#    #+#             */
/*   Updated: 2021/10/26 15:24:27 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_isset(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		begin;
	int		end;

	if (!s1)
		return (NULL);
	begin = -1;
	while (s1[++begin])
		if (!(ft_isset(s1[begin], set)))
			break ;
	end = ft_strlen(s1);
	while (--end)
		if (!(ft_isset(s1[end], set)))
			break ;
	if (end <= begin)
		return (ft_strdup(""));
	if (((end + 1 == (int)ft_strlen(s1)) && !begin) || !set)
		return (ft_strdup(s1));
	return (dest = ft_substr(s1, begin, (end + 1) - begin));
}
