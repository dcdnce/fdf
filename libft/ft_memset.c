/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 09:34:18 by pforesti          #+#    #+#             */
/*   Updated: 2021/10/20 10:12:24 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *obj, int value, size_t size)
{
	unsigned char	*obj_uc;
	size_t			i;

	obj_uc = (unsigned char *)obj;
	i = 0;
	while (i < size)
	{
		obj_uc[i] = value;
		i++;
	}
	return (obj);
}
