/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_operators.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 03:05:09 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/29 15:58:08 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector3	*v3_copy(t_vector3 *v1, t_vector3 *v2)
{
	if (!v1 || !v2)
		null_error();
	v1->x = v2->x;
	v1->y = v2->y;
	v1->z = v2->z;
	return (v1);
}

t_vector3	*v3_plus(t_vector3 *v1, t_vector3 *v2)
{
	if (!v1 || !v2)
		null_error();
	v1->x += v2->x;
	v1->y += v2->y;
	v1->z += v2->z;
	return (v1);
}

t_vector3	*v3_minus(t_vector3 *v1, t_vector3 *v2)
{
	if (!v1 || !v2)
		null_error();
	v1->x -= v2->x;
	v1->y -= v2->y;
	v1->z -= v2->z;
	return (v1);
}

t_vector3	*v3_mult(t_vector3 *v, double a)
{
	if (!v)
		null_error();
	v->x *= a;
	v->y *= a;
	v->z *= a;
	return (v);
}

t_vector3	*v3_div(t_vector3 *v, double a)
{
	if (!v)
		null_error();
	v->x /= a;
	v->y /= a;
	v->z /= a;
	return (v);
}
