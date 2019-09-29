/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 19:31:47 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/29 03:30:06 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# define RAY_T_MIN 0.0001f
# define RAY_T_MAX 1.0e30f

# include <math.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_vector3
{
	double		x;
	double		y;
	double		z;
}				t_vector3;

typedef struct	s_vector2
{
	double		u;
	double		v;
}				t_vector2;

typedef struct	s_ray
{
	t_vector3	*origin;
	t_vector3	*direction;
	double		t_max;
}				t_ray;

typedef struct	s_shape
{

}				t_shape;

typedef struct	s_intersection
{
	t_shape		*shape;
	t_ray		*ray;
	double		t;
}				t_intersection;

void			error(char *str);

t_vector3		*v3_new(void);
t_vector3		*v3_new1(double f);
t_vector3		*v3_new3(double x, double y, double z);
t_vector3		*v3_new_copy(t_vector3 *v);

t_vector3		*v3_copy(t_vector3 *v1, t_vector3 *v2);
t_vector3		*v3_plus(t_vector3 *v1, t_vector3 *v2);
t_vector3		*v3_minus(t_vector3 *v1, t_vector3 *v2);
t_vector3		*v3_mult(t_vector3 *v, double a);
t_vector3		*v3_div(t_vector3 *v, double a);

t_vector3		*v3_new_plus(t_vector3 *v1, t_vector3 *v2);
t_vector3		*v3_new_minus(t_vector3 *v1, t_vector3 *v2);
t_vector3		*v3_new_mult(t_vector3 *v1, t_vector3 *v2);
t_vector3		*v3_new_div(t_vector3 *v1, t_vector3 *v2);
t_vector3		*v3_new_mult_by_scalar(t_vector3 *v, double a);
t_vector3		*v3_new_div_by_scalar(t_vector3 *v, double a);
t_vector3		*v3_new_div_on_scalar(double a, t_vector3 *v);
t_vector3		*cross(t_vector3 *v1, t_vector3 *v2);
t_vector3		*normalized(t_vector3 *v);

double			length_sq(t_vector3 *v);
double			length(t_vector3 *v);
double			normalize(t_vector3 *v);
double			dot(t_vector3 *v1, t_vector3 *v2);

t_ray			*ray(void);
t_ray			*ray_copy(t_ray *ray);
t_ray			*ray_fill(t_vector3 *origin, t_vector3* direction, double t_max);
t_vector3		*calculate(t_ray *ray, double t);

#endif
