/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 09:26:02 by pforesti          #+#    #+#             */
/*   Updated: 2021/11/07 08:58:40 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putstr_pf(char *s, int *read_c)
{
	if (s)
	{
		write(FT_STDOUT, s, ft_strlen(s));
		*read_c += ft_strlen(s);
	}
	else
	{
		write(FT_STDOUT, "(null)", ft_strlen("(null)"));
		*read_c += ft_strlen("(null)");
	}
}

void	ft_putchar_pf(char c, int *read_c)
{
	write(FT_STDOUT, &c, sizeof(c));
	*read_c += 1;
}
