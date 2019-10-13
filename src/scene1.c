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
	l1->intensity = 0.1;
	rt->lights = new_light_list(l1, l1->type);
	
	light = (t_light*)malloc(sizeof(t_light));
	light->type = point;
	light->intensity = 0.5;
	light->position = v3_new(-3, 0, -5);
	add_new_light(rt->lights, light, light->type);
}

void setup_obj1(t_rt *rt)
{
	t_sphere    *sphere;
	
	sphere = sphere_new(v3_new(0, 0, 0), 3.0, 10);
	sphere->color.b = 0;
	sphere->color.g = 0;
	sphere->specular = 10;
	rt->shapes = new_shape_list((void*)sphere, sphere->shape);
}

void setup_camera1(t_rt *rt)
{
	t_vec3 origin;
	t_vec3 focus;
	
	origin = v3_new(0.0, 0.0, -30.0);
	focus = v3_new(0.0, 0.0, 0.0);
	rt->cam = camera_new(origin, focus);
}

void scene1(t_rt *rt)
{
	
	initial_setup(rt);
	setup_camera1(rt);
	setup_obj1(rt);
	setup_light1(rt);
	draw(rt);
	ft_putendl("ready");
}
