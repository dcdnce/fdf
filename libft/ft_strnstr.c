/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:39:38 by pforesti          #+#    #+#             */
/*   Updated: 2021/10/19 18:56:16 by difool           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int		i;
	unsigned int		little_len;

	little_len = 0;
	while (little[little_len])
		little_len++;
	if (!little_len)
		return ((char *)big);
	while (*big != '\0' && len)
	{
		i = 0;
		while (little[i] == big[i] && i < len && little[i] != '\0')
			i++;
		if (i == little_len)
			return ((char *)big);
		big++;
		len--;
	}
	return (0);
}
