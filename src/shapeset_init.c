/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapeset_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 23:48:51 by cschoen           #+#    #+#             */
/*   Updated: 2019/10/13 12:45:41 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

_Bool		shapeset_intersect(t_inter *inter, t_list_shape *shape_list)
{
	_Bool	does_intersect;
	int		i;
	t_list_shape *shape;

	i = 0;
	shape = shape_list;
	if (!inter || !shape)
		p_error("shape intersect");
	does_intersect = FALSE;

	//iterate throw all object in scene
	while (shape != NULL) {
		i += shape_intersect(inter, shape);
		shape = shape->next;
	}
	if (i > 0)
		does_intersect = TRUE;
	return (does_intersect);
}

_Bool	shape_intersect(t_inter *inter, t_list_shape *shape)
{
	if (!inter || !shape)
		p_error("NULL shape");
	if (shape->shape == PLANE)
		return (plane_intersect(inter, shape));
	if (shape->shape == SPHERE)
		return (sphere_intersect(inter, shape));
	if (shape->shape == CONE)
		return (cone_intersect(inter, shape));
	if (shape->shape == CYLINDER)
		return (cylinder_intersect(inter, shape));
	return (FALSE);
}
