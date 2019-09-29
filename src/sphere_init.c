/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 00:05:54 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/30 00:58:48 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double		sqr(double num)
{
	return (num * num);
}

t_sphere	*sphere_new(t_vector3 *center, double radius)
{
	t_sphere	*new_sphere;

	if (!(new_sphere = (t_sphere*)malloc(sizeof(t_sphere))))
		error("sphere_new: ");
	new_sphere->center = v3_new_copy(center);
	new_sphere->radius = radius;
	return (new_sphere);
}

t_sphere	*sphere_new_copy(t_sphere *sphere)
{
	t_sphere	*new_sphere;

	if (!sphere)
		null_error();
	if (!(new_sphere = (t_sphere*)malloc(sizeof(t_sphere))))
		error("sphere_new_copy: ");
	new_sphere->center = v3_new_copy(sphere->center);
	new_sphere->radius = sphere->radius;
	return (new_sphere);
}

t_sphere	*sphere_copy(t_sphere *sphere1, t_sphere *sphere2)
{
	if (!sphere2)
		sphere_del(&sphere1);
	else if (!sphere1)
		sphere1 = sphere_new_copy(sphere2);
	else
	{
		v3_copy(sphere1->center, sphere2->center);
		sphere1->radius = sphere2->radius;
	}
	return (sphere1);
}

_Bool	sphere_intersect(t_inter *inter, t_shape *shape)
{
	t_ray	*local_ray;
	double	coef[3];
	double	discriminant;
	double	t[2];

	(!inter || !inter->ray || !shape || !shape->sphere) ? null_error() : 0;
	local_ray = ray_new_copy(inter->ray);
	v3_minus(local_ray->origin, shape->sphere->center);
	coef[0] = length_sq(local_ray->direction);
	coef[1] = 2.0 * dot(local_ray->direction, local_ray->origin);
	coef[2] = length_sq(local_ray->origin) - sqr(shape->sphere->radius);
	discriminant = coef[1] * coef[1] - 4.0 * coef[0] * coef[2];
	ray_del(&local_ray);
	if (discriminant < 0.0)
		return (FALSE);
	t[0] = (-coef[1] - sqrt(discriminant)) / (2.0 * coef[0]);
	t[1] = (-coef[1] + sqrt(discriminant)) / (2.0 * coef[0]);
	if (t[0] > RAY_T_MIN && t[0] < inter->t)
		inter->t = t[0];
	else if (t[1] > RAY_T_MIN && t[1] < inter->t)
		inter->t = t[1];
	else
		return (FALSE);
	shape_copy(inter->shape, shape);
	return (TRUE);
}

_Bool	sphere_does_intersect(t_ray *ray, t_shape *shape)
{
	t_ray	*local_ray;
	double	coef[3];
	double	discriminant;
	double	t[2];

	(!ray || !shape || !shape->sphere) ? null_error() : 0;
	local_ray = ray_new_copy(ray);
	v3_minus(local_ray->origin, shape->sphere->center);
	coef[0] = length_sq(local_ray->direction);
	coef[1] = 2.0 * dot(local_ray->direction, local_ray->origin);
	coef[2] = length_sq(local_ray->origin) - sqr(shape->sphere->radius);
	discriminant = coef[1] * coef[1] - 4.0 * coef[0] * coef[2];
	ray_del(&local_ray);
	if (discriminant < 0.0)
		return (FALSE);
	t[0] = (-coef[1] - sqrt(discriminant)) / (2.0 * coef[0]);
	if (t[0] > RAY_T_MIN && t[0] < ray->t_max)
		return (TRUE);
	t[1] = (-coef[1] + sqrt(discriminant)) / (2.0 * coef[0]);
	if (t[1] > RAY_T_MIN && t[1] < ray->t_max)
		return (TRUE);
	return (FALSE);
}
