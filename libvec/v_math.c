/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_math.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 22:17:12 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/28 23:49:57 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double		length_sq(t_vector *v)
{
	return (v->x * v->x + v->y * v->y + v->z * v->z);
}

double		length(t_vector *v)
{
	return (sqrt(length_sq(v)));
}

double		normalize(t_vector *v)
{
	double	l;

	l = length(v);
	v->x /= l;
	v->y /= l;
	v->z /= l;
	return (l);
}

t_vector	*normalize_copy(t_vector *v)
{
	t_vector	*new_v;

	new_v = v_copy(v);
	normalize(new_v);
	return (new_v);
}

t_vector	*v_new_plus(t_vector *v1, t_vector *v2)
{
	t_vector	*new_v;

	new_v = v_new();
	new_v->x = v1->x + v2->x;
	new_v->y = v1->y + v2->y;
	new_v->z = v1->z + v2->z;
	return (new_v);
}

void		v_plus(t_vector *v1, t_vector *v2)
{
	v1->x += v2->x;
	v1->y += v2->y;
	v1->z += v2->z;
}

t_vector	*v_new_minus(t_vector *v1, t_vector *v2)
{
	t_vector	*new_v;

	new_v = v_new();
	new_v->x = v1->x - v2->x;
	new_v->y = v1->y - v2->y;
	new_v->z = v1->z - v2->z;
	return (new_v);
}

void		v_minus(t_vector *v1, t_vector *v2)
{
	v1->x -= v2->x;
	v1->y -= v2->y;
	v1->z -= v2->z;
}

t_vector	*v_new_mult(t_vector *v1, t_vector *v2)
{
	t_vector	*new_v;

	new_v = v_new();
	new_v->x = v1->x * v2->x;
	new_v->y = v1->y * v2->y;
	new_v->z = v1->z * v2->z;
	return (new_v);
}

t_vector	*v_new_div(t_vector *v1, t_vector *v2)
{
	t_vector	*new_v;

	new_v = v_new();
	new_v->x = v1->x / v2->x;
	new_v->y = v1->y / v2->y;
	new_v->z = v1->z / v2->z;
	return (new_v);
}

t_vector	*v_new_mult_by_scalar(t_vector *v1, double a)
{
	t_vector	*new_v;

	new_v = v_copy(v1);
	new_v->x *= a;
	new_v->y *= a;
	new_v->z *= a;
	return (new_v);
}

void		v_mult_by_scalar(t_vector *v1, double a)
{
	v1->x *= a;
	v1->y *= a;
	v1->z *= a;
}

t_vector	*v_new_div_by_scalar(t_vector *v, double a)
{
	t_vector	*new_v;

	new_v = v_copy(v);
	new_v->x /= a;
	new_v->y /= a;
	new_v->z /= a;
	return (new_v);
}

void		v_div_by_scalar(t_vector *v, double a)
{
	v->x /= a;
	v->y /= a;
	v->z /= a;
}


double		dot(t_vector *v1, t_vector *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_vector	*cross(t_vector *v1, t_vector *v2)
{
	t_vector	*new_v;

	new_v = v_new();
	new_v->x = v1->y * v2->z - v1->z * v2->y;
	new_v->y = v1->z * v2->x - v1->x * v2->z;
	new_v->z = v1->x * v2->y - v1->y * v2->x;
	return (new_v);
}
