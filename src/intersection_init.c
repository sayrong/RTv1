/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 23:59:26 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/29 14:28:25 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_intersection	*intersection(void)
{
	t_intersection	*new_i;

	if (!(new_i = (t_intersection*)malloc(sizeof(t_intersection))))
		return (NULL);
	new_i->ray = Ray();
	new_i->shape = NULL;
	new_i->t = RAY_T_MAX;
	return (new_i);
}

t_intersection	*intersection_copy(t_intersection *inter)
{
	t_intersection	*new_i;

	if (!(new_i = (t_intersection*)malloc(sizeof(t_intersection))))
		return (NULL);
	new_i->ray = Ray_copy(inter->ray);
	//TO-DO
	new_i->shape = NULL;
	new_i->t = inter->t;
	return (new_i);
}


t_intersection	*intersection_ray(t_ray *ray)
{
	t_intersection	*new_i;

	if (!(new_i = (t_intersection*)malloc(sizeof(t_intersection))))
		return (NULL);
	new_i->ray = Ray_copy(ray);
	//TO-DO
	new_i->shape = NULL;
	new_i->t = ray->t_max;
	return (new_i);
}

int				intersectrd(t_intersection *inter)
{
	return (inter->shape != NULL);
}

t_vector3		*position(t_intersection *inter)
{
	return (calculate(inter->ray, inter->t));
}
