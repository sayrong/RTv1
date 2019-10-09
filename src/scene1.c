//
//  scene1.c
//  RTV1
//
//  Created by Dmitry Skorokohodov on 09/10/2019.
//  Copyright © 2019 Dmitry Skorokohodov. All rights reserved.
//

#include "rt.h"

void setup_light1(t_rt *rt)
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
	light->position = v3_new3(-3, 0, -5);
	add_new_light(rt->lights, light, light->type);
}

void setup_obj1(t_rt *rt)
{
	t_sphere    *sphere;
	
	sphere = sphere_new_dp(v3_new3(0, 0, 0), 3.0);
	sphere->color->b = 0;
	sphere->color->g = 0;
	sphere->specular = 10;
	rt->shapes = new_shape_list((void*)sphere, sphere->shape);
}

void setup_camera1(t_rt *rt)
{
	t_vector3 *origin;
	t_vector3 *focus;
	
	origin = v3_new3(0.0, 0.0, -10.0);
	focus = v3_new3(0.0, 0.0, 0.0);
	rt->cam = camera_new_dp(origin, focus, rt);
}

void scene1(t_rt *rt)
{
	
	initial_setup(rt);
	setup_camera1(rt);
	setup_obj1(rt);
	setup_light1(rt);
	ray_trace(rt, p2_set(0, 0));
	mlx_put_image_to_window(rt->win->mlx_ptr, rt->win->win_ptr,
							rt->img->img_ptr, 0, 0);
	ft_putendl("ready");
}
