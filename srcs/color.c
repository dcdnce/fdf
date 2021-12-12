/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difool <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:20:01 by difool            #+#    #+#             */
/*   Updated: 2021/12/07 15:06:57 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fdf.h"

void	ft_shittylerp(t_fdf *fdf, double v1Y, double v2Y)
{
	int	step;
	int	height;

	fdf->map.rgb.x = 100;
	fdf->map.rgb.y = 0;
	fdf->map.rgb.z = 0;
	v1Y = v1Y / fdf->map.llen;
	v2Y = v2Y / fdf->map.llen;
	height = fdf->map.maxheight - fdf->map.minheight;
	if (!height)
		return ;
	step = 665 / height + 1;
	if (step > 15)
		step = 15;
	if (v1Y < v2Y)
		v1Y = v2Y;
	v1Y -= fdf->map.minheight;
	ft_shittylerp2(v1Y, fdf, step);
	fdf->map.col = ft_create_trgb(0x00, fdf->map.rgb.x,
			fdf->map.rgb.y, fdf->map.rgb.z);
}

void	ft_shittylerp2(double v1Y, t_fdf *fdf, int step)
{
	while (v1Y)
	{
		if (fdf->map.rgb.x != 255)
		{
			fdf->map.rgb.x += step;
			if (fdf->map.rgb.x > 255)
				fdf->map.rgb.x = 255;
		}
		else if (fdf->map.rgb.x == 255 && fdf->map.rgb.y < 255)
		{
			fdf->map.rgb.y += step;
			if (fdf->map.rgb.y > 255)
				fdf->map.rgb.y = 255;
		}
		else if (fdf->map.rgb.y == 255 && fdf->map.rgb.z < 255)
		{
			fdf->map.rgb.z += step;
			if (fdf->map.rgb.z > 255)
				fdf->map.rgb.z = 255;
		}
		v1Y--;
	}
}
