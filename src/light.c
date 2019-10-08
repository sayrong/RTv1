//
//  light.c
//  RTV2
//
//  Created by Babette Alvyn sharp on 04/10/2019.
//  Copyright © 2019 Babette Alvyn sharp. All rights reserved.
//

#include "rt.h"

double compute_specular(t_vector3 *normal_to_intersect, t_vector3 *light_vector, t_inter *inter, int object_specular)
{
	t_vector3 *tmp[3];
	double percent;
	double angle;
	t_vector3 *to_camera_vector;

	percent = 0;
	to_camera_vector = v3_new_mult_by_num(inter->ray->direction, -1);
	tmp[0] = v3_new_mult_by_num(normal_to_intersect, 2);
	tmp[1] = v3_new_mult_by_num(tmp[0], dot(normal_to_intersect, light_vector));
	tmp[2] = v3_new_minus(tmp[1], light_vector);
	angle = dot(tmp[2], to_camera_vector);
	if (angle > 0)
	{
		percent = pow(angle/(length(tmp[2]) * length(to_camera_vector)), object_specular);
	}
	return (percent);
}

t_vector3 *get_intersection_point(t_inter *inter)
{
	t_vector3 *tmp;
	t_vector3 *intersection_point;
	
	tmp = v3_new_mult_by_num(inter->ray->direction, inter->t);
	intersection_point = v3_new_plus(inter->ray->origin, tmp);
	free(tmp);
	return (intersection_point);
}

int is_in_shadow(t_list_light *light, t_vector3 *intersection_point, t_list_shape *scene)
{
	t_inter *inter;
	t_ray *ray;
	t_vector3 *tmp[3];
	double	dist;
	t_list_shape *obj;
	
	tmp[0] = v3_new_minus(light->light->position, intersection_point);
	dist = length(tmp[0]);
	tmp[1] = v3_new_minus(intersection_point, light->light->position);
	tmp[2] = new_normalize(tmp[1]);
	ray = ray_new3(light->light->position, tmp[2], RAY_T_MAX);
	inter = inter_new_ray(ray);
	
	obj = scene;
	while (obj != NULL) {
		shape_intersect(inter, obj);
		obj = obj->next;
	}
	if (inter->shape != NULL)
		if (inter->t < dist - 0.1)
			return (1);
	return (0);
}

double diffuse_light(t_list_light *light, t_inter *inter)
{
	double res;
	double angle;
	t_vector3 *light_vector;
	t_vector3 *intersection_point;
	t_vector3 *normal_to_intersect;
	
	
	res = 0;
	intersection_point = get_intersection_point(inter);
	normal_to_intersect = get_normal(inter);
	
	if (light->type == point)
		light_vector = v3_new_minus(light->light->position, intersection_point);
	else
		light_vector = light->light->position;
	angle = dot(normal_to_intersect, light_vector);
	if (angle > 0)
	{
		res += ((light->light->intensity * angle) / (length(normal_to_intersect) * length(light_vector)));
	}
	if (get_specular(inter) > 0)
	{
		angle = compute_specular(normal_to_intersect, light_vector, inter, get_specular(inter));
		res += (light->light->intensity * angle);
	}
	return (res);
}

double compute_light(t_inter *inter, t_list_shape *scene, t_list_light *lights)
{
	double res;
	t_list_light *light;
	
	res = 0;
	light = lights;
	while (light != NULL)
	{
		if (light->type == ambient)
			res += light->light->intensity;
		else
			if (!is_in_shadow(light, get_intersection_point(inter), scene))
				res += diffuse_light(light, inter);
		light = light->next;
	}
	if (res > 1)
		res = 1;
	return (res);
}
