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
	if (inter->shape->shape == SPHERE)
		return (get_sphere_normal((t_sphere*)inter->shape->content, hit_point));
	else if (inter->shape->shape == PLANE)
		return (get_plane_normal((t_plane*)inter->shape->content, inter->ray));
	else if (inter->shape->shape == CONE)
		return (get_cone_normal((t_cone*)inter->shape->content, inter->ray, hit_point, inter->t));
	else
		return (get_cyl_normal((t_cylinder*)inter->shape->content, inter->ray, hit_point, inter->t));
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

void	calculate(void *data);

void	draw(t_rt *rt)
{
	//ray_trace(rt, p2_set(0, 0));
	pthread_t	threads[THREADS_NUM];
	t_thread	data[THREADS_NUM];
	int			i;
	
	i = -1;
	while (++i < THREADS_NUM) {
		data[i].rt = rt;
		data[i].rt_id = i;
		if (pthread_create(threads + i, NULL, calculate, &(data[i])))
			put_error("Bad pthread_create return value");
	}
	while (i--)
		if (pthread_join(threads[i], NULL))
			put_error("Bad pthread_join return value");
	mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr,
							rt->img->img_ptr, 0, 0);
}

void	calculate(void *data)
{
	int			start_end[2];
	t_thread	*src;
	t_ray		r;
	t_vec2		screen_coord;
	int			*cur_pixel;
	t_inter		inter;
	double		light_percent;
	
	src = (t_thread *)data;
	start_end[0] = STEP * src->rt_id;
	start_end[1] = src->rt_id == THREADS_NUM - 1 ? HEIGHT * WIDTH : start_end[0] + STEP;
	r.origin = src->rt->cam.origin;
	r.t_max = RAY_T_MAX;
	inter_new_ray(&inter, &r);
	while (start_end[0] < start_end[1])
	{
		int x = start_end[0] % WIDTH;
		int y = start_end[0] / HEIGHT;
		screen_coord = v2_set((2.0 * x) / WIDTH - 1.0,
							  (-2.0 * y) / HEIGHT + 1.0);
		set_ray_direction(&r, &screen_coord, &src->rt->cam);
		cur_pixel = get_pixel(x, y, src->rt->img);
		inter.t = RAY_T_MAX;
		if (shapeset_intersect(&inter, src->rt->shapes))
		{
			light_percent = compute_light(&inter, src->rt->shapes, src->rt->lights);
			t_color *tmp = get_color_from_list(inter.shape);
			*cur_pixel = get_color(tmp, light_percent);
		}
		else
			*cur_pixel = 0;
		start_end[0]++;
	}
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
			
			if (size.x == 300 && size.y == 300)
			{
				int a = 1;
			}
			
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
