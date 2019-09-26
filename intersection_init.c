//
//  intersection_init.c
//  RTv1
//
//  Created by Babette Alvyn sharp on 26/09/2019.
//  Copyright © 2019 Babette Alvyn sharp. All rights reserved.
//

#include "vector.h"

t_intersection *Intersection(void)
{
	t_intersection *new;
	
	if (!(new = (t_intersection*)malloc(sizeof(t_intersection))))
		return (NULL);
	new->ray = Ray();
	new->shape = NULL;
	new->t = RAY_T_MAX;
	return (new);
}

t_intersection *Intersection_copy(t_intersection *inter)
{
	t_intersection *new;
	
	if (!(new = (t_intersection*)malloc(sizeof(t_intersection))))
		return (NULL);
	new->ray = Ray_copy(inter->ray);
	//TO-DO
	new->shape = NULL;
	new->t = inter->t;
	return (new);
}


t_intersection *Intersection_ray(t_ray *ray)
{
	t_intersection *new;
	
	if (!(new = (t_intersection*)malloc(sizeof(t_intersection))))
		return (NULL);
	new->ray = Ray_copy(ray);
	//TO-DO
	new->shape = NULL;
	new->t = ray->tMax;
	return (new);
}

int intersectrd(t_intersection *inter)
{
	return (inter->shape != NULL);
}

t_vector *position(t_intersection *inter)
{
	return (calculate(inter->ray, inter->t));
}
