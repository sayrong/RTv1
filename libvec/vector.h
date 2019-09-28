/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 19:31:47 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/28 23:53:38 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# define RAY_T_MIN 0.0001f
# define RAY_T_MAX 1.0e30f

# include <stdio.h>
# include <math.h>
# include <stdlib.h>

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_ray
{
	t_vector	*origin;
	t_vector	*direction;
	double		tMax;
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

t_vector		*v_new(void);
t_vector		*v_new1(double f);
t_vector		*v_new3(double x, double y, double z);
t_vector		*v_copy(t_vector *v);

double			length_sq(t_vector *v);
double			length(t_vector *v);
double			dot(t_vector *v1, t_vector *v2);
double			normalize(t_vector *v);

t_vector		*normalize_copy(t_vector *v);
t_vector		*v_new_mult_by_scalar(t_vector *v, double a);
t_vector		*v_new_div_by_scalar(t_vector *v, double a);
t_vector		*v_new_plus(t_vector *v1, t_vector *v2);
t_vector		*v_new_minus(t_vector *v1, t_vector *v2);
t_vector		*v_new_mult(t_vector *v1, t_vector *v2);
t_vector		*v_new_div(t_vector *v1, t_vector *v2);

void			v_plus(t_vector *v1, t_vector *v2);
void			v_minus(t_vector *v1, t_vector *v2);
void			v_mult(t_vector *v1, double a);
void			v_div(t_vector *v1, double a);

t_ray			*ray(void);
t_ray			*ray_copy(t_ray *ray);
t_ray			*ray_fill(t_vector *origin, t_vector* direction, double t_max);
t_vector		*calculate(t_ray *ray, double t);


#endif
