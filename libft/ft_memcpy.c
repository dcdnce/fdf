/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 09:38:58 by pforesti          #+#    #+#             */
/*   Updated: 2021/10/20 10:14:26 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char	*dest_uc;
	unsigned char	*src_uc;
	size_t			i;

	if (!dest && !src)
		return (0);
	dest_uc = (unsigned char *)dest;
	src_uc = (unsigned char *)src;
	i = 0;
	while (i < size)
	{
		dest_uc[i] = src_uc[i];
		i++;
	}
	return (dest);
}
