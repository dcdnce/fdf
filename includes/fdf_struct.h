/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:59:30 by pforesti          #+#    #+#             */
/*   Updated: 2021/12/07 15:55:02 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

typedef struct s_Mat33
{
	double	x[3][3];
}				t_Mat33;

typedef struct s_vec2
{
	int	x;
	int	y;
}				t_vec2;

typedef struct s_vec2f
{
	double	x;
	double	y;
}				t_vec2f;

typedef struct s_vec3f
{
	double	x;
	double	y;
	double	z;
}				t_vec3f;

typedef struct s_vec3
{
	int	x;
	int	y;
	int	z;
}				t_vec3;

typedef struct s_bresen
{
	t_vec2	v1;
	t_vec2	v2;
	t_vec2	pixel;
	int		op;
	int		inverted;
	int		m;
	int		slope;
}				t_bresen;

typedef struct s_mlxdata
{
	void	*body;
	void	*win;
}				t_mlxdata;

typedef struct s_imgdata
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}				t_imgdata;

typedef struct s_map
{
	int		x;
	int		y;
	int		llen;
	t_vec2	move;
	t_vec2	ang;
	int		maxheight;
	int		minheight;
	t_vec2	center;
	t_vec3	rgb;
	int		col;
	int		colbool;
}				t_map;

typedef struct s_fdf
{
	t_mlxdata	mlx;
	t_imgdata	img;
	t_map		map;
	int			**lst;
}				t_fdf;

#endif
