/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 03:13:48 by cschoen           #+#    #+#             */
/*   Updated: 2019/10/08 22:00:00 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVEC_H
# define LIBVEC_H

# define RAD 0.01745329251994

# include <math.h>

typedef struct	s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

t_vec3			v3_new(double x, double y, double z);
t_vec3			v3_copy(t_vec3 v);
t_vec3			v3_add(t_vec3 v1, t_vec3 v2);
t_vec3			v3_sub(t_vec3 v1, t_vec3 v2);
t_vec3			v3_scale(t_vec3 v, double scale);
double			v3_dot(t_vec3 v1, t_vec3 v2);
double			v3_length(t_vec3 v);
t_vec3			v3_norm(t_vec3 v);
t_vec3			v3_cross(t_vec3 v1, t_vec3 v2);

t_vec3			v3_rot_x(t_vec3 v, double angle);
t_vec3			v3_rot_y(t_vec3 v, double angle);
t_vec3			v3_rot_z(t_vec3 v, double angle);
t_vec3			v3_rot_xyz(t_vec3 v, t_vec3 rotate);
t_vec3			v3_rot_zyx(t_vec3 v, t_vec3 rotate);

# endif
