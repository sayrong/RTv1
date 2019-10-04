/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 18:36:44 by cschoen           #+#    #+#             */
/*   Updated: 2019/10/02 03:17:24 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

//t_shape	*shape_init_null(t_shape *shape)
//{
//	if (!shape)
//		null_error();
//	shape->type = CNT_OF_TYPES;
//	shape->plane = NULL;
//	shape->sphere = NULL;
//	shape->cone = NULL;
//	shape->cylinder = NULL;
//	return (shape);
//}

//t_shape	*shape_new(void)
//{
//	t_shape	*new_shape;
//
//	if (!(new_shape = (t_shape*)malloc(sizeof(t_shape))))
//		error("shape_new: ");
//	return (shape_init_null(new_shape));
//}

//t_shape	*shape_copy_plane(t_shape *shape, t_plane *plane)
//{
//	if (!shape)
//		shape = shape_new();
//	if (!plane)
//	{
//		plane_del(&shape->plane);
//		shape->type = CNT_OF_TYPES;
//	}
//	else
//	{
//		shape->plane = plane_copy(shape->plane, plane);
//		shape->type = PLANE;
//	}
//	return (shape);
//}

//t_shape	*shape_copy_sphere(t_shape *shape, t_sphere *sphere)
//{
//	if (!shape)
//		shape = shape_new();
//	if (!sphere)
//	{
//		sphere_del(&shape->sphere);
//		shape->type = CNT_OF_TYPES;
//	}
//	else
//	{
//		shape->sphere = sphere_copy(shape->sphere, sphere);
//		shape->type = SPHERE;
//	}
//	return (shape);
//}

//t_shape	*shape_new_copy(t_shape *shape)
//{
//	t_shape	*new_shape;
//
//	if (!shape)
//		null_error();
//	if (!(new_shape = (t_shape*)malloc(sizeof(t_shape))))
//		error("shape_new_copy: ");
//	shape_init_null(new_shape);
//	new_shape->type = shape->type;
//	if (new_shape->type == PLANE)
//		new_shape->plane = plane_new_copy(shape->plane);
//	else if (new_shape->type == SPHERE)
//		new_shape->sphere = sphere_new_copy(shape->sphere);
////TO DO CONE CYLINDER
//	/*
//	else if (new_shape->type == CONE)
//		new_shape->cone = cone_new_copy(shape->cone);
//	else if (new_shape->type == CYLINDER)
//		new_shape->cylinder = cylinder_new_copy(shape->cylinder);
//*/
//	return (new_shape);
//}

//t_shape	*shape_copy(t_shape *shape1, t_shape *shape2)
//{
//	if (!shape2)
//		shape_del(&shape1);
//	else if (!shape1)
//		shape1 = shape_new_copy(shape2);
//	else
//	{
//		if (shape1->type != shape2->type)
//		{
//			shape_del(&shape1);
//			shape1 = shape_new_copy(shape2);
//		}
//		else
//		{
//			if (shape1->type == PLANE)
//				shape1->plane = plane_copy(shape1->plane, shape2->plane);
//			else if (shape1->type == SPHERE)
//				shape1->sphere = sphere_copy(shape1->sphere, shape2->sphere);
////TODO CONE CYLINDER
///*
//			else if (shape1->type == CONE)
//				cone_copy(shape1->cone, shape2->cone);
//			else if (shape1->type == CYLINDER)
//				cylinder_copy(shape1->cylinder, shape2->cylinder);
//*/
//		}
//	}
//	return (shape1);
//}

_Bool	shape_intersect(t_inter *inter, t_list_shape *shape)
{
	if (!inter || !shape)
		null_error();
	if (shape->shape == PLANE)
		return (plane_intersect(inter, shape));
	if (shape->shape == SPHERE)
		return (sphere_intersect(inter, shape));
//TODO CONE CYLINDER
/*
	if (shape->type == CONE)
		return (cone_intersect(inter, shape));
	if (shape->type == CYLINDER)
		return (cylinder_intersect(inter, shape));
*/
	return (FALSE);
}

//_Bool	shape_does_intersect(t_ray *ray, t_shape *shape)
//{
//	if (!ray || !shape)
//		null_error();
//	if (shape->type == PLANE)
//		return (plane_does_intersect(ray, shape));
//	if (shape->type == SPHERE)
//		return (sphere_does_intersect(ray, shape));
////TODO CONE CYLINDER
///*
//	if (shape->type == CONE)
//		return (cone_does_intersect(ray, shape));
//	if (shape->type == CYLINDER)
//		return (cylinder_does_intersect(ray, shape));
//*/
//	return (FALSE);
//}

