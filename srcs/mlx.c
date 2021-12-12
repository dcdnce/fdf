/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:46:25 by pforesti          #+#    #+#             */
/*   Updated: 2021/12/07 14:43:05 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fdf.h"

int	ft_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_my_mlx_pixel_put(t_imgdata *img, int x, int y, int color)
{
	char	*dst;

	if ((x >= SCREEN_X || y >= SCREEN_Y) || (x < 0 || y < 0))
		return ;
	dst = img->addr + (y * img->size_line + x * 4);
	*(unsigned int *)dst = color;
}
