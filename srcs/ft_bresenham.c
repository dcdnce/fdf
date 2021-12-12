/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difool <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 23:15:18 by difool            #+#    #+#             */
/*   Updated: 2021/12/07 14:34:21 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fdf.h"

static void	ft_swap_both(t_vec2 *a, t_vec2 *b)
{
	t_vec2	tmp;

	tmp.x = a->x;
	tmp.y = a->y;
	a->x = b->x;
	a->y = b->y;
	b->x = tmp.x;
	b->y = tmp.y;
}

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	ft_bresenham_case(t_bresen *b)
{
	if (b->v1.x > b->v2.x)
		ft_swap_both(&b->v1, &b->v2);
	b->pixel.x = b->v1.x;
	b->pixel.y = b->v1.y;
	if ((b->v1.y > b->v2.y))
		b->op = -1;
	if ((b->v2.x - b->v1.x) < (b->v2.y - b->v1.y))
	{
		ft_swap(&b->v1.x, &b->v1.y);
		ft_swap(&b->v2.x, &b->v2.y);
		b->pixel.x = b->v1.x;
		b->pixel.y = b->v1.y;
		b->inverted = 1;
	}
	else if (abs(b->v2.x - b->v1.x) < abs(b->v2.y - b->v1.y)
		&& (b->v1.y > b->v2.y))
	{
		ft_swap(&b->v1.x, &b->v1.y);
		ft_swap(&b->v2.x, &b->v2.y);
		b->pixel.x = b->v2.x;
		b->pixel.y = b->v2.y;
		ft_swap(&b->v1.x, &b->v2.x);
		b->inverted = 1;
	}
}

void	ft_bresenham(t_vec3f va, t_vec3f vb, t_imgdata *img, int color)
{
	t_bresen	b;

	b.v1.x = va.x;
	b.v2.x = vb.x;
	b.v1.y = va.y;
	b.v2.y = vb.y;
	b.op = 1;
	b.inverted = 0;
	ft_bresenham_case(&b);
	b.m = 2 * abs(b.v2.y - b.v1.y);
	b.slope = b.m - abs(b.v2.x - b.v1.x);
	while (b.pixel.x++ < b.v2.x)
	{
		if (!b.inverted)
			ft_my_mlx_pixel_put(img, b.pixel.x, b.pixel.y, color);
		else
			ft_my_mlx_pixel_put(img, b.pixel.y, b.pixel.x, color);
		b.slope += b.m;
		if (b.slope >= 0)
		{
			b.pixel.y += b.op;
			b.slope -= 2 * abs(b.v2.x - b.v1.x);
		}
	}
}
