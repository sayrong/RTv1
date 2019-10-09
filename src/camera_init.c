/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 01:59:27 by cschoen           #+#    #+#             */
/*   Updated: 2019/10/06 23:06:05 by cschoen          ###   ########.fr       */
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
	t_cam	*new_cam;

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

t_cam	*recalc_cam_dp(t_cam *cam, int key, t_vector3 *upguide,
						t_vector2 *fov_ratio)
{
	key == W_KEY ? ++cam->origin->y : 0;
	key == S_KEY ? --cam->origin->y : 0;
	key == D_KEY ? ++cam->origin->x : 0;
	key == A_KEY ? --cam->origin->x : 0;
	key == Q_KEY ? ++cam->origin->z : 0;
	key == E_KEY ? --cam->origin->z : 0;
	key == EIGHT_NUM ? ++cam->forward->y : 0;
	key == TWO_NUM ? --cam->forward->y : 0;
	key == FOUR_NUM ? ++cam->forward->x : 0;
	key == SIX_NUM ? --cam->forward->x : 0;
	key == PLUS ? ++cam->forward->z : 0;
	key == MINUS ? --cam->forward->z : 0;
	normalize(cam->forward);
	v3_del(&cam->right);
	cam->right = new_cross(cam->forward, upguide);
	normalize(cam->right);
//	key == EIGHT_KEY ? ++cam->right : 0;
//	key == TWO_KEY ? --cam->right : 0;
//	key == FOUR_KEY ? ++cam->right : 0;
//	key == SIX_KEY ? --cam->right : 0;
//	key == PLUS_KEY ? ++cam->right : 0;
//	key == MINUS_KEY ? --cam->right : 0;
	v3_del(&cam->up);
	cam->up = new_cross(cam->right, cam->forward);
	normalize(cam->up);
	cam->h = tan(fov_ratio->u);
	cam->w = cam->h * fov_ratio->v;
	v3_del(&upguide);
	v2_del(&fov_ratio);
	return (cam);
}

t_cam	*camera_new_dp(t_vector3 *origin, t_vector3 *target, t_rt *rt)
{
	t_cam		*new_cam;
	t_vector3	*upguide;
	t_vector2	*fov_ratio;

	upguide = v3_new3(0.0, 1.0, 0.0);
	fov_ratio = v2_new2(25.0 * PI / 180,
						(double)rt->size.x / (double)rt->size.y);
	new_cam = camera_new(origin, target, upguide, fov_ratio);
	v3_del(&origin);
	v3_del(&target);
	v3_del(&upguide);
	v2_del(&fov_ratio);
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
