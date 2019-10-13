//
//  scene2.c
//  RTV1
//
//  Created by Dmitry Skorokohodov on 09/10/2019.
//  Copyright © 2019 Dmitry Skorokohodov. All rights reserved.
//

#include "rt.h"


void setup_light2(t_rt *rt)
{
	t_light		*light;
	t_light		*l1;
	
	l1 = (t_light*)malloc(sizeof(t_light));
	l1->type = ambient;
	l1->intensity = 0.1;
	rt->lights = new_light_list(l1, l1->type);
	
	light = (t_light*)malloc(sizeof(t_light));
	light->type = point;
	light->intensity = 0.4;
	light->position = v3_new(-4, 0, -5);
	add_new_light(rt->lights, light, light->type);
}

void setup_obj2(t_rt *rt)
{
	t_cylinder    *cyl;
	
	cyl = cylinder_new(v3_new(0, 0, 0), v3_new(0, 1, 0), 2, 10);
	cyl->color.b = 0;
	cyl->color.r = 0;
	rt->shapes = new_shape_list((void*)cyl, cyl->shape);
}

void setup_camera2(t_rt *rt)
{
	t_vec3 origin;
	t_vec3 focus;
	
	origin = v3_new(0.0, 0.0, -10.0);
	focus = v3_new(0.0, 0.0, 0.0);
	rt->cam = camera_new(origin, focus);
}

void scene2(t_rt *rt)
{
	
	initial_setup(rt);
	setup_camera2(rt);
	setup_obj2(rt);
	setup_light2(rt);
	ray_trace(rt, p2_set(0, 0));
	mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr,
							rt->img->img_ptr, 0, 0);
	ft_putendl("ready");
}


 
