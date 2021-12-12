/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:07:35 by pforesti          #+#    #+#             */
/*   Updated: 2021/12/12 09:39:28 by difool           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fdf.h"

int	ft_exit(t_fdf *fdf)
{
	int	i;

	i = -1;
	while (++i < fdf->map.y)
		free(fdf->lst[i]);
	free(fdf->lst);
	mlx_destroy_image(fdf->mlx.body, fdf->img.img);
	mlx_destroy_window(fdf->mlx.body, fdf->mlx.win);
	exit(EXIT_SUCCESS);
	return (0);
}

static void	ft_event_keypress_arrow(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ARROW_UP)
		fdf->map.move.y += fdf->map.llen;
	if (keycode == KEY_ARROW_DOWN)
		fdf->map.move.y -= fdf->map.llen;
	if (keycode == KEY_ARROW_LEFT)
		fdf->map.move.x += fdf->map.llen;
	if (keycode == KEY_ARROW_RIGHT)
		fdf->map.move.x -= fdf->map.llen;
	ft_init_draw(fdf);
}

static void	ft_event_keypress_plus(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_P)
	{
		fdf->map.ang.y = 0;
		fdf->map.ang.x = 90;
	}
	if (keycode == KEY_C)
	{
		if (fdf->map.colbool)
			fdf->map.colbool = 0;
		else
			fdf->map.colbool = 1;
	}
	if (keycode == KEY_I)
	{
		fdf->map.ang.y = BASE_ANGLE_Y;
		fdf->map.ang.x = BASE_ANGLE_X;
	}
	ft_init_draw(fdf);
}

int	ft_event_keypress(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ECHAP)
		ft_exit(fdf);
	if (keycode == KEY_D)
		fdf->map.ang.y += 1;
	if (keycode == KEY_A)
		fdf->map.ang.y -= 1;
	if (keycode == KEY_W)
		fdf->map.ang.x += 1;
	if (keycode == KEY_S)
		fdf->map.ang.x -= 1;
	if (keycode == KEY_ARROW_LEFT || keycode == KEY_ARROW_UP
		|| keycode == KEY_ARROW_DOWN || keycode == KEY_ARROW_RIGHT)
		ft_event_keypress_arrow(keycode, fdf);
	if (keycode == KEY_J)
		if (fdf->map.llen > 1)
			fdf->map.llen -= 1;
	if (keycode == KEY_K)
		fdf->map.llen += 1;
	if (keycode == KEY_P || keycode == KEY_C || keycode == KEY_I)
		ft_event_keypress_plus(keycode, fdf);
	ft_init_draw(fdf);
	return (0);
}
