//
//  ray_init.c
//  RTv1
//
//  Created by Babette Alvyn sharp on 26/09/2019.
//  Copyright © 2019 Babette Alvyn sharp. All rights reserved.
//

#include "vector.h"

t_ray *Ray(void)
{
	t_ray *new;
	if (!(new = (t_ray*)malloc(sizeof(t_ray))))
		return (NULL);
	new->direction = vector();
	new->origin = new_vector(0, 0, 0);
	new->tMax = RAY_T_MAX;
	if (new->direction == NULL || new->origin == NULL)
		return (NULL);
	return (new);
}

t_ray *Ray_copy(t_ray *ray)
{
	t_ray *new;
	if (!(new = (t_ray*)malloc(sizeof(t_ray))))
		return (NULL);
	new->direction = copy_vector(ray->direction);
	new->origin = copy_vector(ray->origin);
	new->tMax = ray->tMax;
	if (new->direction == NULL || new->origin == NULL)
		return (NULL);
	return (new);
}

t_ray *Ray_fill(t_vector *origin, t_vector* direction, double tMax)
{
	t_ray *new;
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
t_vector *calculate(t_ray *ray, double t)
{
	t_vector *new;
	
	if (!(new = multiply_vectors_const(ray->direction, t)))
		return (NULL);
	plus_vector(&new,ray->origin);
	return (new);
}
