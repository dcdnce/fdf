/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:32:56 by pforesti          #+#    #+#             */
/*   Updated: 2021/11/07 08:58:14 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_which_arg(const char *format, size_t i, va_list *ap, int *read_c)
{
	if (format[i + 1] == 'c')
		ft_putchar_pf((unsigned char)va_arg(*ap, int), read_c);
	else if (format[i + 1] == 's')
		ft_putstr_pf((char *)va_arg(*ap, char *), read_c);
	else if (format[i + 1] == '%')
		ft_putchar_pf('%', read_c);
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		ft_putnbr_pf((int)va_arg(*ap, int), read_c);
	else if (format[i + 1] == 'u')
		ft_putnbr_ui_pf((unsigned int)va_arg(*ap, unsigned int), read_c);
	else if (format[i + 1] == 'x')
		ft_putnbr_base_ui_pf(va_arg(*ap, unsigned int), BASE_LOWX, read_c);
	else if (format[i + 1] == 'X')
		ft_putnbr_base_ui_pf(va_arg(*ap, unsigned int), BASE_UPX, read_c);
	else if (format[i + 1] == 'p')
	{
		ft_putstr_pf("0x", read_c);
		ft_putnbr_base_st_pf((size_t)va_arg(*ap, void *), BASE_LOWX, read_c);
	}
	else
		return (0);
	return (1);
}	

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	size_t			i;
	int				read_c;

	va_start(ap, format);
	i = -1;
	read_c = 0;
	while (format[++i])
	{
		if (format[i] != '%')
			ft_putchar_pf(format[i], &read_c);
		else
			i += ft_which_arg(format, i, &ap, &read_c);
	}
	va_end(ap);
	return (read_c);
}
