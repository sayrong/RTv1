/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:42:44 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/29 17:41:59 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ray_null(t_ray **ray)
{
	if (ray != NULL && *ray != NULL)
	{
		v3_del(&((*ray)->origin));
		v3_del(&((*ray)->direction));
		(*ray)->t_max = RAY_T_MAX;
	}
}

void	ray_del(t_ray **ray)
{
	if (ray != NULL && *ray != NULL)
	{
		ray_null(ray);
		free(*ray);
		*ray = NULL;
	}
}

t_ray		*ray_new(void)
{
	t_ray	*new_r;

	if (!(new_r = (t_ray*)malloc(sizeof(t_ray))))
		error("r_new: ");
	new_r->origin = v3_new3(0, 0, 0);
	new_r->direction = v3_new();
	new_r->t_max = RAY_T_MAX;
	return (new_r);
}

t_ray		*ray_new3(t_vector3 *origin, t_vector3 *dir, double t_max)
{
	t_ray	*new_r;

	if (!origin || !dir)
		null_error();
	if (!(new_r = (t_ray*)malloc(sizeof(t_ray))))
		error("r_new_fill: ");
	new_r->origin = v3_new_copy(origin);
	new_r->direction = v3_new_copy(dir);
	new_r->t_max = t_max;
	return (new_r);
}

t_ray		*ray_new_copy(t_ray *ray)
{
	t_ray	*new_r;

	if (!ray)
		null_error();
	if (!(new_r = (t_ray*)malloc(sizeof(t_ray))))
		error("r_new_copy: ");
	new_r->direction = v3_new_copy(ray->direction);
	new_r->origin = v3_new_copy(ray->origin);
	new_r->t_max = ray->t_max;
	return (new_r);
}

t_ray		*ray_copy(t_ray *ray1, t_ray *ray2)
{
	if (!ray1 || !ray2)
		null_error();
	v3_copy(ray1->origin, ray2->origin);
	v3_copy(ray1->direction, ray2->direction);
	ray1->t_max = ray2->t_max;
	return (ray1);
}

//point of intersection when found T value
t_vector3	*calculate(t_ray *ray, double t)
{
	t_vector3	*new_v;

	if (!ray)
		null_error();
	new_v = v3_new_copy(ray->direction);
	v3_mult(new_v, t);
	v3_plus(new_v, ray->origin);
	return (new_v);
}
