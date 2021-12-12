/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:25:16 by pforesti          #+#    #+#             */
/*   Updated: 2021/10/26 14:36:16 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char	*dest_uc;
	unsigned char	*src_uc;

	if (!dest && !src)
		return (NULL);
	dest_uc = (unsigned char *)dest;
	src_uc = (unsigned char *)src;
	if (dest_uc < src_uc)
		while (size--)
			*dest_uc++ = *src_uc++;
	else
	{
		dest_uc += size - 1;
		src_uc += size - 1;
		while (size--)
			*dest_uc-- = *src_uc--;
	}
	return (dest);
}
