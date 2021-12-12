/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:27:34 by pforesti          #+#    #+#             */
/*   Updated: 2021/12/07 17:49:44 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fdf.h"

static void	ft_center(t_vec2 *center, t_fdf *fdf, t_Mat33 mat)
{
	int		elem;
	t_vec3f	v;

	elem = fdf->lst[fdf->map.y / 2][fdf->map.x / 2];
	v.x = (fdf->map.x / 2) * fdf->map.llen;
	v.y = -elem * fdf->map.llen;
	v.z = (fdf->map.y / 2) * fdf->map.llen;
	ft_mat33_x_vec3(&v, mat);
	center->x = SCREEN_X / 2 - round(v.x);
	center->y = SCREEN_Y / 2 - round(v.y);
}

void	ft_init_draw(t_fdf *fdf)
{
	t_Mat33	mat;

	mlx_destroy_image(fdf->mlx.body, fdf->img.img);
	fdf->img.img = mlx_new_image(fdf->mlx.body, SCREEN_X, SCREEN_Y);
	ft_m33_prod(&mat, ft_m33_rotx(ft_dtr(fdf->map.ang.x)),
		ft_m33_roty(ft_dtr(fdf->map.ang.y)));
	ft_draw(fdf, mat);
	mlx_put_image_to_window(fdf->mlx.body, fdf->mlx.win, fdf->img.img, 0, 0);
}

void	ft_draw(t_fdf *fdf, t_Mat33 mat)
{
	int	i;

	i = -1;
	ft_center(&fdf->map.center, fdf, mat);
	while (++i < fdf->map.y)
		ft_draw_horizontal(fdf->lst[i], fdf, i, mat);
	i = -1;
	while (++i < fdf->map.x - 1)
		ft_draw_vertical(fdf->lst, fdf, i, mat);
}

void	ft_draw_vertical(int **lst, t_fdf *fdf, int row, t_Mat33 mat)
{
	t_vec3f	v1;
	t_vec3f	v2;
	int		i;

	fdf->map.col = 0x00ffffff;
	i = -1;
	while (++i < fdf->map.y - 1)
	{
		v1.x = row * fdf->map.llen;
		v1.y = -lst[i][row] * fdf->map.llen;
		v1.z = i * fdf->map.llen;
		v2.x = row * fdf->map.llen;
		v2.y = -lst[i + 1][row] * fdf->map.llen;
		v2.z = (i + 1) * fdf->map.llen;
		if (fdf->map.colbool)
			ft_shittylerp(fdf, -v1.y, -v2.y);
		ft_mat33_x_vec3(&v1, mat);
		ft_mat33_x_vec3(&v2, mat);
		v1.x += fdf->map.move.x + fdf->map.center.x;
		v2.x += fdf->map.move.x + fdf->map.center.x;
		v1.y += fdf->map.move.y + fdf->map.center.y;
		v2.y += fdf->map.move.y + fdf->map.center.y;
		ft_bresenham(v1, v2, &fdf->img, fdf->map.col);
	}
}

void	ft_draw_horizontal(int *lst, t_fdf *fdf, int line, t_Mat33 mat)
{
	t_vec3f	v1;
	t_vec3f	v2;
	int		i;

	fdf->map.col = 0x00ffffff;
	i = 0;
	while (++i < fdf->map.x - 1)
	{
		v1.x = (i - 1) * fdf->map.llen;
		v1.y = -lst[i - 1] * fdf->map.llen;
		v1.z = line * fdf->map.llen;
		v2.x = i * fdf->map.llen;
		v2.y = -lst[i] * fdf->map.llen;
		v2.z = line * fdf->map.llen;
		if (fdf->map.colbool)
			ft_shittylerp(fdf, -v1.y, -v2.y);
		ft_mat33_x_vec3(&v1, mat);
		ft_mat33_x_vec3(&v2, mat);
		v1.x += fdf->map.move.x + fdf->map.center.x;
		v2.x += fdf->map.move.x + fdf->map.center.x;
		v1.y += fdf->map.move.y + fdf->map.center.y;
		v2.y += fdf->map.move.y + fdf->map.center.y;
		ft_bresenham(v1, v2, &fdf->img, fdf->map.col);
	}
}
