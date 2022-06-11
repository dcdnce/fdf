/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difool <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:20:01 by difool            #+#    #+#             */
/*   Updated: 2022/06/11 08:28:28 by difool           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fdf.h"

static inline float lerp(const float lo, const float hi, const float t) {
	return (lo * (1 - t) + hi * t);
}

void	ft_shittylerp(t_fdf *fdf, int v)
{
	float 	t;
	int		lr;

	t = (float)v / (float)fdf->map.maxheight;
	lr = lerp(0, 255, t);
	fdf->map.col = ft_create_trgb(255, 255 - lr, 255 - lr, 255 - lr);
}
