/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 10:27:18 by pforesti          #+#    #+#             */
/*   Updated: 2021/10/22 10:35:18 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	char			c;

	if (n < 0)
	{
		write(fd, "-", sizeof(char));
		nb = n * -1;
	}
	else
		nb = n;
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		nb %= 10;
	}
	c = '0' + nb;
	write(fd, &c, sizeof(char));
}
