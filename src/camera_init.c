/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 01:59:27 by cschoen           #+#    #+#             */
/*   Updated: 2019/10/13 15:56:47 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_cam	camera_new(t_vec3 origin, t_vec3 target)
{
	t_cam	new_cam;
	t_vec2	fov_ratio;
	t_vec3	upguide;

	fov_ratio = v2_set(25.0 * PI / 180, (double)WIDTH / (double)HEIGHT);
	upguide = v3_new(0.0, 1.0, 0.0);
	new_cam.origin = origin;
	new_cam.forward = v3_sub(target, origin);
	new_cam.forward = v3_norm(new_cam.forward);
	new_cam.right = v3_cross(new_cam.forward, upguide);
	new_cam.right = v3_norm(new_cam.right);
	new_cam.up = v3_cross(new_cam.right, new_cam.forward);
	new_cam.h = tan(fov_ratio.u);
	new_cam.w = new_cam.h * fov_ratio.v;
	return (new_cam);
}

t_cam	*recalc_cam_dp(t_cam *cam, int key, t_vec3 upguide, t_vec2 fov_ratio)
{
	key == W_KEY ? ++cam->origin.y : 0;
	key == S_KEY ? --cam->origin.y : 0;
	key == D_KEY ? ++cam->origin.x : 0;
	key == A_KEY ? --cam->origin.x : 0;
	key == Q_KEY ? ++cam->origin.z : 0;
	key == E_KEY ? --cam->origin.z : 0;
	key == EIGHT_NUM ? ++cam->forward.y : 0;
	key == TWO_NUM ? --cam->forward.y : 0;
	key == FOUR_NUM ? ++cam->forward.x : 0;
	key == SIX_NUM ? --cam->forward.x : 0;
	key == PLUS ? ++cam->forward.z : 0;
	key == MINUS ? --cam->forward.z : 0;
	cam->forward = v3_norm(cam->forward);
	cam->right = v3_cross(cam->forward, upguide);
	cam->right = v3_norm(cam->right);
	cam->up = v3_cross(cam->right, cam->forward);
	cam->up = v3_norm(cam->up);
	cam->h = tan(fov_ratio.u);
	cam->w = cam->h * fov_ratio.v;
	return (cam);
}
