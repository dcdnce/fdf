/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:59:37 by pforesti          #+#    #+#             */
/*   Updated: 2022/06/11 08:20:28 by difool           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "../libft/libft.h"
# include "mlx_keycodes.h"
# include "fdf_struct.h"

# define SCREEN_X 400 
# define SCREEN_Y 400
# define BASE_ANGLE_X 35 
# define BASE_ANGLE_Y 45

/* event.c			*/
int		ft_event_keypress(int keycode, t_fdf *fdf);
int		ft_exit(t_fdf *fdf);

/* draw.c 			*/
void	ft_init_draw(t_fdf *fdf);
void	ft_draw_horizontal(int *lst, t_fdf *fdf, int line, t_Mat33 mat);
void	ft_draw_vertical(int **lst, t_fdf *fdf, int row, t_Mat33 mat);
void	ft_draw(t_fdf *fdf, t_Mat33 mat);

/* parse.c			*/
int		ft_init(char *path, t_fdf *fdf);

/* mlx.c			*/
int		ft_create_trgb(int t, int r, int g, int b);
void	ft_my_mlx_pixel_put(t_imgdata *img, int x, int y, int color);

/* ft_bresenham.c	*/
void	ft_bresenham(t_vec3f a, t_vec3f b, t_imgdata *img, int color);

/* matrices.c		*/
void	ft_mat33_x_vec3(t_vec3f *v, t_Mat33 m);
void	ft_m33_prod(t_Mat33 *mat, t_Mat33 x, t_Mat33 y);
t_Mat33	ft_m33_rotx(float angle);
t_Mat33	ft_m33_roty(float angle);
float	ft_dtr(float angle);

/* color.c			*/
//void	ft_shittylerp(t_fdf *fdf, double v1Y, double v2Y);
void	ft_shittylerp2(double v1Y, t_fdf *fdf, int step);
void	ft_shittylerp(t_fdf *fdf, int v);

/* main.c			*/
void	ft_error(char *strerror, int flag);

#endif
