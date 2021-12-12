/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:37:51 by pforesti          #+#    #+#             */
/*   Updated: 2021/11/07 08:59:15 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_checkbase(char *base, char c, int i)
{
	while (base[i])
	{
		if (c == base[i + 1] || c == '+' || c == '-')
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base_ui_pf(unsigned int nbr, char *base, int *read_c)
{
	size_t			n_b;
	int				i;
	unsigned int	n;

	i = 0;
	n_b = ft_strlen(base);
	if (!(n_b > 1))
		return ;
	while (base[i])
	{
		if (!(ft_checkbase(base, base[i], i)))
			return ;
		i++;
	}
	n = nbr;
	if (n > (n_b - 1))
		ft_putnbr_base_ui_pf((n / n_b), base, read_c);
	write(FT_STDOUT, &base[n % n_b], sizeof(char));
	*read_c += 1;
}

void	ft_putnbr_base_st_pf(size_t nbr, char *base, int *read_c)
{
	size_t			n_b;
	int				i;
	size_t			n;

	i = 0;
	n_b = ft_strlen(base);
	if (!(n_b > 1))
		return ;
	while (base[i])
	{
		if (!(ft_checkbase(base, base[i], i)))
			return ;
		i++;
	}
	n = nbr;
	if (n > (n_b - 1))
		ft_putnbr_base_st_pf((n / n_b), base, read_c);
	write(FT_STDOUT, &base[n % n_b], sizeof(char));
	*read_c += 1;
}

void	ft_putnbr_ui_pf(unsigned int n, int *read_c)
{
	char	c;

	if (n > 9)
	{
		ft_putnbr_ui_pf(n / 10, read_c);
		n %= 10;
	}
	c = '0' + n;
	write(FT_STDOUT, &c, sizeof(char));
	*read_c += 1;
}

void	ft_putnbr_pf(int n, int *read_c)
{
	unsigned int	nb;
	char			c;

	if (n < 0)
	{
		write(FT_STDOUT, "-", sizeof(char));
		*read_c += 1;
		nb = n * -1;
	}
	else
		nb = n;
	if (nb > 9)
	{
		ft_putnbr_pf(nb / 10, read_c);
		nb %= 10;
	}
	c = '0' + nb;
	write(FT_STDOUT, &c, sizeof(char));
	*read_c += 1;
}
