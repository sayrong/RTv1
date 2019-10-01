/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 01:59:27 by cschoen           #+#    #+#             */
/*   Updated: 2019/10/01 02:16:22 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_cam	*cam_init_null(t_cam *cam)
{
	if (!cam)
		null_error();
	cam->h = 0;
	cam->w = 0;
	cam->origin = NULL;
	cam->forward = NULL;
	cam->up = NULL;
	cam->right = NULL;
	return (cam);
}

t_cam	*camera_new(t_vector3 *origin, t_vector3 *target,
					t_vector3 *upguide, t_vector2 *fov_ratio)
{
	t_cam		*new_cam;

	if (!fov_ratio)
		null_error();
	if (!(new_cam = (t_cam*)malloc(sizeof(t_cam))))
		error("camera_new: ");
	cam_init_null(new_cam);
	new_cam->origin = v3_new_copy(origin);
	new_cam->forward = v3_new_minus(target, origin);
	normalize(new_cam->forward);
	new_cam->right = new_cross(new_cam->forward, upguide);
	normalize(new_cam->right);
	new_cam->up = new_cross(new_cam->right, new_cam->forward);
	new_cam->h = tan(fov_ratio->u);
	new_cam->w = new_cam->h * fov_ratio->v;
	return (new_cam);
}

t_ray	*make_ray(t_vector2 *point, t_cam *cam)
{
	t_vector3	*direction;
	t_vector3	*temp;
	t_ray		*ray;

	if (!point || !cam)
		null_error();
	temp = v3_new_mult_by_num(cam->right, point->u * cam->w);
	direction = v3_new_mult_by_num(cam->up, point->v * cam->h);
	v3_plus(direction, temp);
	v3_del(&temp);
	v3_plus(direction, cam->forward);
	normalize(direction);
	ray = ray_new3(cam->origin, direction, RAY_T_MAX);
	v3_del(&direction);
	return (ray);
}
