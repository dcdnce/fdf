/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difool <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:58:59 by difool            #+#    #+#             */
/*   Updated: 2021/12/07 14:42:15 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fdf.h"

void	ft_m33_prod(t_Mat33 *mat, t_Mat33 x, t_Mat33 y)
{
	mat->x[0][0] = x.x[0][0] * y.x[0][0] + x.x[0][1] * y.x[1][0]
		+ x.x[0][2] * y.x[2][0];
	mat->x[0][1] = x.x[0][0] * y.x[0][1] + x.x[0][1] * y.x[1][1]
		+ x.x[0][2] * y.x[2][1];
	mat->x[0][2] = x.x[0][0] * y.x[0][2] + x.x[0][1] * y.x[1][2]
		+ x.x[0][2] * y.x[2][2];
	mat->x[1][0] = x.x[1][0] * y.x[0][0] + x.x[1][1] * y.x[1][0]
		+ x.x[1][2] * y.x[2][0];
	mat->x[1][1] = x.x[1][0] * y.x[0][1] + x.x[1][1] * y.x[1][1]
		+ x.x[1][2] * y.x[2][1];
	mat->x[1][2] = x.x[1][0] * y.x[0][2] + x.x[1][1] * y.x[1][2]
		+ x.x[1][2] * y.x[2][2];
	mat->x[2][0] = x.x[2][0] * y.x[0][0] + x.x[2][1] * y.x[1][0]
		+ x.x[2][2] * y.x[2][0];
	mat->x[2][1] = x.x[2][0] * y.x[0][1] + x.x[2][1] * y.x[1][1]
		+ x.x[2][2] * y.x[2][1];
	mat->x[2][2] = x.x[2][0] * y.x[0][2] + x.x[2][1] * y.x[1][2]
		+ x.x[2][2] * y.x[2][2];
}

t_Mat33	ft_m33_roty(float angle)
{
	t_Mat33	m;

	m.x[0][0] = cos(angle);
	m.x[0][1] = 0;
	m.x[0][2] = -sin(angle);
	m.x[1][0] = 0;
	m.x[1][1] = 1;
	m.x[1][2] = 0;
	m.x[2][0] = sin(angle);
	m.x[2][1] = 0;
	m.x[2][2] = cos(angle);
	return (m);
}

t_Mat33	ft_m33_rotx(float angle)
{
	t_Mat33	m;

	m.x[0][0] = 1;
	m.x[0][1] = 0;
	m.x[0][2] = 0;
	m.x[1][0] = 0;
	m.x[1][1] = cos(angle);
	m.x[1][2] = sin(angle);
	m.x[2][0] = 0;
	m.x[2][1] = -sin(angle);
	m.x[2][2] = cos(angle);
	return (m);
}

void	ft_mat33_x_vec3(t_vec3f *v, t_Mat33 m)
{
	t_vec3f	tmp;

	tmp = *v;
	v->x = m.x[0][0] * tmp.x + m.x[0][1] * tmp.y + m.x[0][2] * tmp.z;
	v->y = m.x[1][0] * tmp.x + m.x[1][1] * tmp.y + m.x[1][2] * tmp.z;
	v->z = m.x[2][0] * tmp.x + m.x[2][1] * tmp.y + m.x[2][2] * tmp.z;
}

float	ft_dtr(float angle)
{
	return (3.141593f * angle / 180.f);
}
