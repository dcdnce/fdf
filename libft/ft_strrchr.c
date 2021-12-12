/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:22:10 by pforesti          #+#    #+#             */
/*   Updated: 2021/10/22 10:51:04 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int				i;
	unsigned char	uc;

	i = 1;
	uc = (unsigned char)c;
	while (*str++ != '\0')
		i++;
	while (i--)
	{
		str--;
		if (*str == uc)
			return ((char *)str);
	}
	return (0);
}
