//
//  scene4.c
//  RTV1
//
//  Created by Dmitry Skorokohodov on 09/10/2019.
//  Copyright © 2019 Dmitry Skorokohodov. All rights reserved.
//

#include "rt.h"

void setup_light4(t_rt *rt)
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
	light->position = v3_new(-4, 5, -3);
	add_new_light(rt->lights, light, light->type);
}

void set_floor4(t_rt *rt)
{
	t_plane		*plane;

	plane = plane_new(v3_new(0, -3, 0), v3_new(0, 1, 0), 10);
	plane->color.r = 100;
	plane->color.g = 0;
	rt->shapes = new_shape_list((void*)plane, plane->shape);
}

void set_back4(t_rt *rt)
{
	t_plane		*plane;
	
	plane = plane_new(v3_new(0, 0, 90), v3_new(0, 0, 1), 10);
	plane->color.r = 0;
	plane->color.g = 0;
	add_new_shape(rt->shapes, (void*)plane, plane->shape);
}


void set_cone(t_rt *rt)
{
	t_cone	*cone;
	
	cone = cone_new(v3_new(-5, 2, 5), v3_new(3, 5, 0), 90, 10);
	cone->color.b = 0;
	add_new_shape(rt->shapes, (void*)cone, cone->shape);
}

void set_sphere(t_rt *rt)
{
	t_sphere    *sphere;
	
	sphere = sphere_new(v3_new(0, 0, 0), 4.0, 10);
	sphere->color.b = 0;
	sphere->color.g = 0;
	sphere->specular = 10;
	add_new_shape(rt->shapes, (void*)sphere, sphere->shape);
}

void set_cyl(t_rt *rt)
{
	t_cylinder    *cyl;

	cyl = cylinder_new(v3_new(5, 0, 3), v3_new(-5, 7, 1), 3, 10);
	cyl->color.r = 0;
	cyl->color.b = 0;
	add_new_shape(rt->shapes, (void*)cyl, cyl->shape);
}

void setup_obj4(t_rt *rt)
{
	set_floor4(rt);
	set_back4(rt);
	set_cone(rt);
	set_sphere(rt);
	set_cyl(rt);
}

void setup_camera4(t_rt *rt)
{
	t_vec3 origin;
	t_vec3 focus;
	
	origin = v3_new(0.0, 0.0, -35.0);
	focus = v3_new(0.0, 0.0, 0.0);
	rt->cam = camera_new(origin, focus);
}

void scene4(t_rt *rt)
{
	
	initial_setup(rt);
	setup_camera4(rt);
	setup_obj4(rt);
	setup_light4(rt);
	draw(rt);
	ft_putendl("ready");
}

