/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:42:44 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/29 00:00:46 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_ray		*ray(void)
{
	t_ray	*new;

	if (!(new = (t_ray*)malloc(sizeof(t_ray))))
		return (NULL);
	new->direction = vector();
	new->origin = new_vector(0, 0, 0);
	new->tMax = RAY_T_MAX;
	if (new->direction == NULL || new->origin == NULL)
		return (NULL);
	return (new);
}

t_ray		*ray_copy(t_ray *ray)
{
	t_ray	*new;

	if (!(new = (t_ray*)malloc(sizeof(t_ray))))
		return (NULL);
	new->direction = copy_vector(ray->direction);
	new->origin = copy_vector(ray->origin);
	new->tMax = ray->tMax;
	if (new->direction == NULL || new->origin == NULL)
		return (NULL);
	return (new);
}

t_ray		*ray_fill(t_vector *origin, t_vector* direction, double tMax)
{
	t_ray	*new;

	if (!(new = (t_ray*)malloc(sizeof(t_ray))))
		return (NULL);
	new->direction = origin;
	new->origin = direction;
	new->tMax = tMax;
	if (new->direction == NULL || new->origin == NULL)
		return (NULL);
	return (new);
}

//point of intersection when found T value
t_vector	*calculate(t_ray *ray, double t)
{
	t_vector	*new;

	if (!(new = multiply_vectors_const(ray->direction, t)))
		return (NULL);
	plus_vector(&new,ray->origin);
	return (new);
}
