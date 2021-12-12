/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:26:36 by pforesti          #+#    #+#             */
/*   Updated: 2021/10/21 08:34:11 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	j = 0;
	n = ft_strlen(dest);
	while (dest[i] && i < size)
		i++;
	if (i == size)
		return (i + ft_strlen(src));
	while (i < (size - 1) && src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (n + ft_strlen(src));
}
