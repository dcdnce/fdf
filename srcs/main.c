/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:09:14 by pforesti          #+#    #+#             */
/*   Updated: 2021/12/07 14:36:11 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fdf.h"

void	ft_error(char *strerror, int flag)
{
	ft_putstr_fd("fdf: ", 2);
	if (!flag)
		perror(strerror);
	else
		ft_printf("%s\n", strerror);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_fdf		fdf;

	if (ac == 2)
	{
		fdf.mlx.body = mlx_init();
		fdf.mlx.win = mlx_new_window(fdf.mlx.body, SCREEN_X, SCREEN_Y, "fdf");
		fdf.img.img = mlx_new_image(fdf.mlx.body, SCREEN_X, SCREEN_Y);
		fdf.img.addr = mlx_get_data_addr(fdf.img.img, &fdf.img.bpp,
				&fdf.img.size_line, &fdf.img.endian);
		ft_init(av[1], &fdf);
		ft_init_draw(&fdf);
		mlx_hook(fdf.mlx.win, 2, 1L << 0, ft_event_keypress, &fdf);
		mlx_hook(fdf.mlx.win, 17, 0, ft_exit, &fdf);
		mlx_loop(fdf.mlx.body);
	}
	else
		ft_error("Missing arguments", 1);
	return (0);
}
