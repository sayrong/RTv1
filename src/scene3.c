//
//  scene3.c
//  RTV1
//
//  Created by Dmitry Skorokohodov on 09/10/2019.
//  Copyright © 2019 Dmitry Skorokohodov. All rights reserved.
//

#include "rt.h"


void setup_light3(t_rt *rt)
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
	light->position = v3_new(-4, 0, -3);
	add_new_light(rt->lights, light, light->type);
}

void set_floor3(t_rt *rt)
{
	t_plane		*plane;
	
	plane = plane_new(v3_new(0, -3, 0), v3_new(0, 1, 0), 0);
	plane->color.r = 0;
	plane->color.g = 0;
	rt->shapes = new_shape_list((void*)plane, plane->shape);
}

void setup_obj3(t_rt *rt)
{
	t_cone	*cone;

	cone = cone_new(v3_new(0, 0, 2), v3_new(0, 1, 0), 90, 10);
	cone->color.b = 0;
	add_new_shape(rt->shapes, (void*)cone, cone->shape);
}

void setup_camera3(t_rt *rt)
{
	t_vec3 origin;
	t_vec3 focus;
	
	origin = v3_new(0.0, 0.0, -20.0);
	focus = v3_new(0.0, 0.0, 0.0);
	rt->cam = camera_new(origin, focus);
}

void scene3(t_rt *rt)
{
	
	initial_setup(rt);
	setup_camera3(rt);
	set_floor3(rt);
	setup_obj3(rt);
	setup_light3(rt);
	draw(rt);
	ft_putendl("ready");
}

