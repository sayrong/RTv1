//
//  ray_trace.c
//  RTV2
//
//  Created by Babette Alvyn sharp on 09/10/2019.
//  Copyright © 2019 Babette Alvyn sharp. All rights reserved.
//



#include "rt.h"

t_vec3 get_normal(t_inter *inter)
{
	t_vec3	hit_point;
	t_vec3	tmp;
	
	tmp = v3_scale(inter->ray->direction, inter->t);
	hit_point = v3_add(inter->ray->origin, tmp);
	//if (inter->shape->shape == SPHERE)
	return (get_sphere_normal((t_sphere*)inter->shape->content, hit_point));
	
	/*
	else if (inter->shape->shape == PLANE)
	{
		v3_del(&hit_point);
		return (get_plane_normal((t_plane*)inter->shape->content, inter->ray));
	}
	else if (inter->shape->shape == CONE)
		return (get_cone_normal((t_cone*)inter->shape->content, inter->ray, hit_point, inter->t));
	else if (inter->shape->shape == CYLINDER)
		return (get_cyl_normal((t_cylinder*)inter->shape->content, inter->ray, hit_point, inter->t));
	return NULL;
	*/
}

int get_specular(t_inter		*inter)
{
	if (inter->shape->shape == SPHERE)
		return ((t_sphere*)inter->shape->content)->specular;
	else if (inter->shape->shape == PLANE)
		return ((t_plane*)inter->shape->content)->specular;
	else if (inter->shape->shape == CONE)
		return ((t_cone*)inter->shape->content)->specular;
	else
		return ((t_cylinder*)inter->shape->content)->specular;
}

void	ray_trace(t_rt *rt, t_point2 size)
{
	t_vec2		screen_coord;
	t_ray		ray;
	int			*cur_pixel;
	t_inter		inter;
	double		light_percent;
	
	(!rt->img || !rt->shapes) ? put_error("null raytrace func") : 0;
	size.x = -1;
	while (++size.x < rt->img->width)
	{
		size.y = -1;
		while (++size.y < rt->img->height)
		{
			screen_coord = v2_set((2.0 * size.x) / rt->img->width - 1.0,
								  (-2.0 * size.y) / rt->img->height + 1.0);
			//ray = make_ray(&screen_coord, rt->cam);
			ray.origin = rt->cam.origin;
			ray.t_max = RAY_T_MAX;
			set_ray_direction(&ray, &screen_coord, &rt->cam);
			cur_pixel = get_pixel(size.x, size.y, rt->img);
			inter_new_ray(&inter, &ray);
			if (shapeset_intersect(&inter, rt->shapes))
			{
				light_percent = compute_light(&inter, rt->shapes, rt->lights);
				t_color *tmp = get_color_from_list(inter.shape);
				*cur_pixel = get_color(tmp, light_percent);
			}
			else
				*cur_pixel = 0;
		}
	}
}
