/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:42:44 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/29 14:26:32 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ray		*ray(void)
{
	t_ray	*new_r;

	if (!(new_r = (t_ray*)malloc(sizeof(t_ray))))
		return (NULL);
	new_r->direction = vector();
	new_r->origin = new_vector(0, 0, 0);
	new_r->t_max = RAY_T_MAX;
	if (new_r->direction == NULL || new_r->origin == NULL)
		return (NULL);
	return (new_r);
}

t_ray		*ray_copy(t_ray *ray)
{
	t_ray	*new_r;

	if (!(new_r = (t_ray*)malloc(sizeof(t_ray))))
		return (NULL);
	new_r->direction = copy_vector(ray->direction);
	new_r->origin = copy_vector(ray->origin);
	new_r->t_max = ray->t_max;
	if (new_r->direction == NULL || new_r->origin == NULL)
		return (NULL);
	return (new_r);
}

t_ray		*ray_fill(t_vector3 *origin, t_vector3* direction, double t_max)
{
	t_ray	*new_r;

	if (!(new_r = (t_ray*)malloc(sizeof(t_ray))))
		return (NULL);
	new_r->direction = origin;
	new_r->origin = direction;
	new_r->t_max = t_max;
	if (new_r->direction == NULL || new_r->origin == NULL)
		return (NULL);
	return (new_r);
}

//point of intersection when found T value
t_vector3	*calculate(t_ray *ray, double t)
{
	t_vector3	*new_v;

	if (!(new_v = multiply_vectors_const(ray->direction, t)))
		return (NULL);
	plus_vector(&new_v, ray->origin);
	return (new_v);
}
