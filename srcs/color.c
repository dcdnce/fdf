/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difool <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:20:01 by difool            #+#    #+#             */
/*   Updated: 2022/09/06 15:33:39 by pforesti         ###   ########.fr       */
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

	t = ((float)v - (float)fdf->map.minheight) / ((float)fdf->map.maxheight - (float)fdf->map.minheight);
	r = lerp(249, 9, t);
	g = lerp(235, 25, t);
	b = lerp(224, 43, t);
	fdf->map.col = ft_create_trgb(0, r, g, b);
}
