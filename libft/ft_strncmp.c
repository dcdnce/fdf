/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 13:22:49 by pforesti          #+#    #+#             */
/*   Updated: 2021/10/26 14:51:53 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!(n))
		return (0);
	while (s1[i] && s2[i] && (s1[i] == s2[i]) && i < n)
	{
		i++;
	}
	if (!(i < n))
		return (s1[i - 1] - s2[i - 1]);
	return ((unsigned char)s1[i] - s2[i]);
}
