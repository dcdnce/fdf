/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difool <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:20:01 by difool            #+#    #+#             */
/*   Updated: 2022/06/12 09:54:12 by difool           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fdf.h"

static inline float lerp(const float lo, const float hi, const float t) {
	return (lo * (1 - t) + hi * t);
}

void	ft_shittylerp(t_fdf *fdf, int v)
{
	float 	t;
	int		r;
	int		g;
	int		b;

	t = (float)v / (float)fdf->map.maxheight;
	r = lerp(9, 249, t);
	g = lerp(25, 235, t);
	b = lerp(43, 224, t);
	fdf->map.col = ft_create_trgb(255, r, g, b);
}
