/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 23:59:26 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/29 00:00:28 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_intersection	*intersection(void)
{
	t_intersection	*new;

	if (!(new = (t_intersection*)malloc(sizeof(t_intersection))))
		return (NULL);
	new->ray = Ray();
	new->shape = NULL;
	new->t = RAY_T_MAX;
	return (new);
}

t_intersection	*intersection_copy(t_intersection *inter)
{
	t_intersection	*new;

	if (!(new = (t_intersection*)malloc(sizeof(t_intersection))))
		return (NULL);
	new->ray = Ray_copy(inter->ray);
	//TO-DO
	new->shape = NULL;
	new->t = inter->t;
	return (new);
}


t_intersection	*intersection_ray(t_ray *ray)
{
	t_intersection	*new;

	if (!(new = (t_intersection*)malloc(sizeof(t_intersection))))
		return (NULL);
	new->ray = Ray_copy(ray);
	//TO-DO
	new->shape = NULL;
	new->t = ray->tMax;
	return (new);
}

int				intersectrd(t_intersection *inter)
{
	return (inter->shape != NULL);
}

t_vector		*position(t_intersection *inter)
{
	return (calculate(inter->ray, inter->t));
}
