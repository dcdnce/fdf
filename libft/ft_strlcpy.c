/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 09:41:58 by pforesti          #+#    #+#             */
/*   Updated: 2021/10/21 08:33:55 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	n;

	n = ft_strlen(src);
	i = -1;
	if (n + 1 < size)
	{
		while (++i < n + 1)
			dest[i] = src[i];
	}
	else if (size)
	{
		while (++i < size - 1)
			dest[i] = src[i];
		dest[i] = 0;
	}
	return (n);
}
