/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:15:45 by cschoen           #+#    #+#             */
/*   Updated: 2019/10/02 01:00:39 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_plane	*plane_new(t_vector3 *position, t_vector3 *normal)
{
	t_plane	*new_plane;

	if (!(new_plane = (t_plane*)malloc(sizeof(t_plane))))
		error("plane_new: ");
	new_plane->position = v3_new_copy(position);
	new_plane->normal = v3_new_copy(normal);
	return (new_plane);
}

t_plane	*plane_new_dp(t_vector3 *position, t_vector3 *normal)
{
	t_plane	*new_plane;

	new_plane = plane_new(position, normal);
	v3_del(&position);
	v3_del(&normal);
	return (new_plane);
}

t_plane	*plane_new_copy(t_plane *plane)
{
	t_plane	*new_plane;

	if (!plane)
		null_error();
	if (!(new_plane = (t_plane*)malloc(sizeof(t_plane))))
		error("plane_new_copy: ");
	new_plane->position = v3_new_copy(plane->position);
	new_plane->normal = v3_new_copy(plane->normal);
	return (new_plane);
}

t_plane	*plane_copy(t_plane *plane1, t_plane *plane2)
{
	if (!plane2)
		plane_del(&plane1);
	else if (!plane1)
		plane1 = plane_new_copy(plane2);
	else
	{
		plane1->position = v3_copy(plane1->position, plane2->position);
		plane1->normal = v3_copy(plane1->normal, plane2->normal);
	}
	return (plane1);
}

_Bool	plane_intersect(t_inter *inter, t_shape *shape)
{
	t_vector3	*temp;
	double		d_dot_n;
	double		t;

	if (!inter || !inter->ray || !shape || !shape->plane)
		null_error();
	if ((d_dot_n = dot(inter->ray->direction, shape->plane->normal)) == 0.0)
		return (FALSE);
	temp = v3_new_minus(shape->plane->position, inter->ray->origin);
	t = dot(temp, shape->plane->normal) / d_dot_n;
	v3_del(&temp);
	if (t <= RAY_T_MIN || t >= RAY_T_MAX)
		return (FALSE);
	inter->t = t;
	inter->shape = shape_copy(inter->shape, shape);
	return (TRUE);
}

_Bool	plane_does_intersect(t_ray *ray, t_shape *shape)
{
	t_vector3	*temp;
	double		d_dot_n;
	double		t;

	if (!ray || !shape || !shape->plane)
		null_error();
	if ((d_dot_n = dot(ray->direction, shape->plane->normal)) == 0.0)
		return (FALSE);
	temp = v3_new_minus(shape->plane->position, ray->origin);
	t = dot(temp, shape->plane->normal) / d_dot_n;
	v3_del(&temp);
	if (t <= RAY_T_MIN || t >= RAY_T_MAX)
		return (FALSE);
	return (TRUE);
}
