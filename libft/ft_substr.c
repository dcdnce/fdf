/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:56:37 by pforesti          #+#    #+#             */
/*   Updated: 2021/10/21 10:52:31 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	dest = malloc(len + 1 * sizeof(*dest));
	if (!dest)
		return (NULL);
	i = 0;
	while (*s && i < len)
	{
		dest[i] = *(s + start + i);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
