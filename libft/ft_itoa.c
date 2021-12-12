/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:00:42 by pforesti          #+#    #+#             */
/*   Updated: 2021/10/21 15:25:44 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_hmchars(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i += 1;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*dest;
	int		sign;
	long	nb;

	nb = (long)n;
	sign = 0;
	i = ft_hmchars(nb);
	dest = malloc(sizeof(*dest) * i + 1);
	if (!dest)
		return (NULL);
	dest[i] = '\0';
	if (nb < 0)
	{
		sign = 1;
		dest[0] = '-';
		nb *= -1;
	}
	while (--i >= sign)
	{
		dest[i] = '0' + nb % 10;
		nb /= 10;
	}
	return (dest);
}
