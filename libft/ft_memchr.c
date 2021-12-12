/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:58:15 by pforesti          #+#    #+#             */
/*   Updated: 2021/10/20 14:23:59 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *o, int c, size_t size)
{
	unsigned char	*ou;
	size_t			i;

	ou = (unsigned char *)o;
	i = 0;
	while (i < size)
	{
		if (ou[i] == (unsigned char)c)
			return ((void *)ou + i);
		i++;
	}
	return (NULL);
}
