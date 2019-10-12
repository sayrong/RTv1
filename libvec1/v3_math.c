/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 22:17:12 by cschoen           #+#    #+#             */
/*   Updated: 2019/10/06 22:57:16 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void free_temp_v(t_vector3 **ar, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(ar[i]);
		i++;
	}
}

void	v3_del(t_vector3 **vec)
{
	if (vec != NULL && *vec != NULL)
	{
		free(*vec);
		*vec = NULL;
	}
}

double		length_sq(t_vector3 *v)
{
	if (!v)
		null_error();
	return (v->x * v->x + v->y * v->y + v->z * v->z);
}

double		length(t_vector3 *v)
{
	if (!v)
		null_error();
	return (sqrt(length_sq(v)));
}

double		normalize(t_vector3 *v)
{
	double	l;

	if (!v)
		null_error();
	l = length(v);
	v->x /= l;
	v->y /= l;
	v->z /= l;
	return (l);
}

t_vector3	*new_normalize(t_vector3 *v)
{
	t_vector3	*new_v;

	if (!v)
		null_error();
	new_v = v3_new_copy(v);
	normalize(new_v);
	return (new_v);
}

double		dot(t_vector3 *v1, t_vector3 *v2)
{
	if (!v1 || !v2)
		null_error();
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_vector3	*new_cross(t_vector3 *v1, t_vector3 *v2)
{
	t_vector3	*new_v;

	if (!v1 || !v2)
		null_error();
	new_v = v3_new();
	new_v->x = v1->y * v2->z - v1->z * v2->y;
	new_v->y = v1->z * v2->x - v1->x * v2->z;
	new_v->z = v1->x * v2->y - v1->y * v2->x;
	return (new_v);
}

t_vector3	*v3_new_plus(t_vector3 *v1, t_vector3 *v2)
{
	t_vector3	*new_v;

	if (!v1 || !v2)
		null_error();
	new_v = v3_new();
	new_v->x = v1->x + v2->x;
	new_v->y = v1->y + v2->y;
	new_v->z = v1->z + v2->z;
	return (new_v);
}

t_vector3	*v3_new_minus(t_vector3 *v1, t_vector3 *v2)
{
	t_vector3	*new_v;

	if (!v1 || !v2)
		null_error();
	new_v = v3_new();
	new_v->x = v1->x - v2->x;
	new_v->y = v1->y - v2->y;
	new_v->z = v1->z - v2->z;
	return (new_v);
}

t_vector3	*v3_new_mult(t_vector3 *v1, t_vector3 *v2)
{
	t_vector3	*new_v;

	if (!v1 || !v2)
		null_error();
	new_v = v3_new();
	new_v->x = v1->x * v2->x;
	new_v->y = v1->y * v2->y;
	new_v->z = v1->z * v2->z;
	return (new_v);
}

t_vector3	*v3_new_div(t_vector3 *v1, t_vector3 *v2)
{
	t_vector3	*new_v;

	if (!v1 || !v2)
		null_error();
	new_v = v3_new();
	new_v->x = v1->x / v2->x;
	new_v->y = v1->y / v2->y;
	new_v->z = v1->z / v2->z;
	return (new_v);
}

t_vector3	*v3_new_mult_by_num(t_vector3 *v, double a)
{
	t_vector3	*new_v;

	if (!v)
		null_error();
	new_v = v3_new_copy(v);
	new_v->x *= a;
	new_v->y *= a;
	new_v->z *= a;
	return (new_v);
}

t_vector3	*v3_new_div_by_num(t_vector3 *v, double a)
{
	t_vector3	*new_v;

	if (!v)
		null_error();
	new_v = v3_new_copy(v);
	new_v->x /= a;
	new_v->y /= a;
	new_v->z /= a;
	return (new_v);
}

t_vector3	*v3_new_div_on_num(double a, t_vector3 *v)
{
	t_vector3	*new_v;

	if (!v)
		null_error();
	new_v = v3_new1(a);
	new_v->x /= v->x;
	new_v->y /= v->y;
	new_v->z /= v->z;
	return (new_v);
}
