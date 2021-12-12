/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:05:07 by pforesti          #+#    #+#             */
/*   Updated: 2021/10/20 11:41:50 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(void *obj1, void *obj2, size_t size)
{
	unsigned char	*o1_uc;
	unsigned char	*o2_uc;

	o1_uc = obj1;
	o2_uc = obj2;
	while (size--)
	{
		if (*o1_uc != *o2_uc)
			return (*o1_uc - *o2_uc);
		o1_uc++;
		o2_uc++;
	}
	return (0);
}
