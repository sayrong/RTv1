/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:44:23 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/29 15:55:52 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector3	*v3_new(void)
{
	t_vector3	*new_v;

	if (!(new_v = (t_vector3*)malloc(sizeof(t_vector3))))
		error("v3_new: ");
	new_v->x = 0.0f;
	new_v->y = 1.0f;
	new_v->z = 0.0f;
	return (new_v);
}

t_vector3	*v3_new1(double f)
{
	t_vector3	*new_v;

	if (!(new_v = (t_vector3*)malloc(sizeof(t_vector3))))
		error("v3_new1: ");
	new_v->x = f;
	new_v->y = f;
	new_v->z = f;
	return (new_v);
}

t_vector3	*v3_new3(double x, double y, double z)
{
	t_vector3	*new_v;

	if (!(new_v = (t_vector3*)malloc(sizeof(t_vector3))))
		error("v3_new3: ");
	new_v->x = x;
	new_v->y = y;
	new_v->z = z;
	return (new_v);
}

t_vector3	*v3_new_copy(t_vector3 *v)
{
	t_vector3	*new_v;

	if (!v)
		null_error();
	if (!(new_v = (t_vector3*)malloc(sizeof(t_vector3))))
		error("v3_new_copy: ");
	new_v->x = v->x;
	new_v->y = v->y;
	new_v->z = v->z;
	return (new_v);
}
