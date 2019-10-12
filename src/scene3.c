//
//  scene3.c
//  RTV1
//
//  Created by Dmitry Skorokohodov on 09/10/2019.
//  Copyright © 2019 Dmitry Skorokohodov. All rights reserved.
//

#include "rt.h"

/*

void setup_light3(t_rt *rt)
{
	t_light		*light;
	t_light		*l1;
	
	l1 = (t_light*)malloc(sizeof(t_light));
	l1->type = ambient;
	l1->intensity = 0.05;
	l1->position = NULL;
	rt->lights = new_light_list(l1, l1->type);
	
	light = (t_light*)malloc(sizeof(t_light));
	light->type = point;
	light->intensity = 0.5;
	light->position = v3_new3(-4, 0, -3);
	add_new_light(rt->lights, light, light->type);
}

void set_floor3(t_rt *rt)
{
	t_vec3 	*posit;
	t_vec3	*norm;
	t_plane		*plane;
	
	posit = v3_new3(0, -3, 0);
	norm = v3_new3(0, 1, 0);
	plane = plane_new(posit, norm);
	plane->color = white();
	plane->color->r = 0;
	plane->color->g = 0;
	plane->shape = PLANE;
	plane->specular = 0;
	rt->shapes = new_shape_list((void*)plane, plane->shape);
}

void setup_obj3(t_rt *rt)
{
	t_cone	*cone;
	
	set_floor3(rt);
	cone = (t_cone*)malloc(sizeof(t_cone));
	cone->angle = 90;
	cone->color = white();
	cone->color->b = 0;
	cone->position = v3_new3(0, 0, 2);
	cone->dir = v3_new3(0, 1, 0);
	cone->specular = 10;
	cone->shape = CONE;
	add_new_shape(rt->shapes, (void*)cone, cone->shape);
}

void setup_camera3(t_rt *rt)
{
	t_vec3 *origin;
	t_vec3 *focus;
	
	origin = v3_new3(0.0, 0.0, -20.0);
	focus = v3_new3(0.0, 0.0, 0.0);
	rt->cam = camera_new_dp(origin, focus, rt);
}

void scene3(t_rt *rt)
{
	
	initial_setup(rt);
	setup_camera3(rt);
	setup_obj3(rt);
	setup_light3(rt);
	ray_trace(rt, p2_set(0, 0));
	mlx_put_image_to_window(rt->win->mlx_ptr, rt->win->win_ptr,
							rt->img->img_ptr, 0, 0);
	ft_putendl("ready");
}

*/
