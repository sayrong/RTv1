/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 22:18:15 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/30 00:21:49 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ray_del(t_ray **ray)
{
	if (ray != NULL && *ray != NULL)
	{
		v3_del(&((*ray)->origin));
		v3_del(&((*ray)->direction));
		free(*ray);
		*ray = NULL;
	}
}

void	plane_del(t_plane **plane)
{
	if (plane != NULL && *plane != NULL)
	{
		v3_del(&((*plane)->position));
		v3_del(&((*plane)->normal));
		free(*plane);
		*plane = NULL;
	}
}

void	sphere_del(t_sphere **sphere)
{
	if (sphere != NULL && *sphere != NULL)
	{
		v3_del(&((*sphere)->center));
		free(*sphere);
		*sphere = NULL;
	}
}

void	shape_del(t_shape **shape)
{
	if (shape != NULL && *shape != NULL)
	{
		plane_del(&(*shape)->plane);
//TO DO SPHERE CONE CYLINDER
/*
		sphere_del(&(*shape)->sphere);
		cone_del(&(*shape)->cone);
		cylinder_del(&(*shape)->cylinder);
*/
		free(*shape);
		*shape = NULL;
	}
}

void	inter_del(t_inter **inter)
{
	if (inter != NULL && *inter != NULL)
	{
		ray_del(&(*inter)->ray);
		shape_del(&(*inter)->shape);
		free(*inter);
		*inter = NULL;
	}
}
