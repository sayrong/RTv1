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
	l1->intensity = 0.05;
	l1->position = NULL;
	rt->lights = new_light_list(l1, l1->type);
	
	light = (t_light*)malloc(sizeof(t_light));
	light->type = point;
	light->intensity = 0.5;
	light->position = v3_new3(-4, 5, -3);
	add_new_light(rt->lights, light, light->type);
}

void set_floor4(t_rt *rt)
{
	t_vector3 	*posit;
	t_vector3	*norm;
	t_plane		*plane;
	
	posit = v3_new3(0, -3, 0);
	norm = v3_new3(0, 1, 0);
	plane = plane_new(posit, norm);
	plane->color = white();
	plane->color->r = 100;
	plane->color->g = 0;
	plane->shape = PLANE;
	plane->specular = 0;
	rt->shapes = new_shape_list((void*)plane, plane->shape);
}

void set_back4(t_rt *rt)
{
	t_vector3 	*posit;
	t_vector3	*norm;
	t_plane		*plane;
	
	posit = v3_new3(0, 0, 90);
	norm = v3_new3(0, 0, 1);
	plane = plane_new(posit, norm);
	plane->color = white();
	plane->color->r = 0;
	plane->color->g = 0;
	plane->shape = PLANE;
	plane->specular = 0;
	add_new_shape(rt->shapes, (void*)plane, plane->shape);
}


void set_cone(t_rt *rt)
{
	t_cone	*cone;
	t_vector3 *dir;
	
	
	cone = (t_cone*)malloc(sizeof(t_cone));
	cone->angle = 90;
	cone->color = white();
	cone->color->b = 0;
	cone->position = v3_new3(-5, 2, 5);
	
	//dir must be normalized
	dir = v3_new3(3, 5, 0);
	normalize(dir);
	cone->dir = dir;
	cone->specular = 10;
	cone->shape = CONE;
	add_new_shape(rt->shapes, (void*)cone, cone->shape);
}

void set_sphere(t_rt *rt)
{
	t_sphere    *sphere;
	
	sphere = sphere_new_dp(v3_new3(0, 0, 0), 4.0);
	sphere->color->b = 0;
	sphere->color->g = 0;
	sphere->specular = 10;
	add_new_shape(rt->shapes, (void*)sphere, sphere->shape);
}

void set_cyl(t_rt *rt)
{
	t_cylinder    *cyl;
	t_vector3 *dir;
	
	cyl = (t_cylinder*)malloc(sizeof(t_cylinder));
	cyl->position = v3_new3(5, 0, 3);
	
	dir = v3_new3(-5, 7, 1);
	normalize(dir);
	cyl->dir = dir;
	cyl->color = white();
	cyl->color->r = 0;
	cyl->color->b = 0;
	cyl->radius = 3;
	cyl->shape = CYLINDER;
	cyl->specular = 10;
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
	t_vector3 *origin;
	t_vector3 *focus;
	
	origin = v3_new3(0.0, 0.0, -35.0);
	focus = v3_new3(0.0, 0.0, 0.0);
	rt->cam = camera_new_dp(origin, focus, rt);
}

void scene4(t_rt *rt)
{
	
	initial_setup(rt);
	setup_camera4(rt);
	setup_obj4(rt);
	setup_light4(rt);
	ray_trace(rt, p2_set(0, 0));
	mlx_put_image_to_window(rt->win->mlx_ptr, rt->win->win_ptr,
							rt->img->img_ptr, 0, 0);
	ft_putendl("ready");
}

