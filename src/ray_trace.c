/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:58:10 by cschoen           #+#    #+#             */
/*   Updated: 2019/10/13 18:04:01 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3	get_normal(t_inter *inter)
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
		return (get_cone_normal((t_cone*)inter->shape->content, inter->ray,
							hit_point, inter->t));
	else
		return (get_cyl_normal((t_cylinder*)inter->shape->content, inter->ray,
							hit_point, inter->t));
}

int		get_specular(t_inter *inter)
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

void	draw(t_rt *rt)
{
	pthread_t	threads[THREADS_NUM];
	t_thread	data[THREADS_NUM];
	int			i;

	i = -1;
	while (++i < THREADS_NUM)
	{
		data[i].rt = rt;
		data[i].rt_id = i;
		if (pthread_create(threads + i, NULL, calculate, &(data[i])))
			p_error("pthread_create");
	}
	while (i--)
		if (pthread_join(threads[i], NULL))
			p_error("pthread_join");
	mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->img->img_ptr, 0, 0);
}

void	send_ray(t_inter *inter, int position, t_thread *src)
{
	int		x_y[2];
	t_vec2	screen_coord;
	int		*cur_pixel;
	double	light_percent;
	t_color	*tmp;

	x_y[0] = position % WIDTH;
	x_y[1] = position / HEIGHT;
	screen_coord = v2_set((2.0 * x_y[0]) / WIDTH - 1.0,
						(-2.0 * x_y[1]) / HEIGHT + 1.0);
	set_ray_direction(inter->ray, &screen_coord, &src->rt->cam);
	inter->t = RAY_T_MAX;
	cur_pixel = get_pixel(x_y[0], x_y[1], src->rt->img);
	if (shapeset_intersect(inter, src->rt->shapes))
	{
		light_percent = compute_light(inter, src->rt->shapes, src->rt->lights);
		tmp = get_color_from_list(inter->shape);
		*cur_pixel = get_color(tmp, light_percent);
	}
	else
		*cur_pixel = 0;
}

void	*calculate(void *data)
{
	int			start_end[2];
	t_thread	*src;
	t_ray		r;
	t_inter		inter;

	src = (t_thread *)data;
	start_end[0] = STEP * src->rt_id;
	start_end[1] = (src->rt_id == THREADS_NUM - 1) ?
					HEIGHT * WIDTH : start_end[0] + STEP;
	r.origin = src->rt->cam.origin;
	r.t_max = RAY_T_MAX;
	inter_new_ray(&inter, &r);
	while (start_end[0] < start_end[1])
	{
		send_ray(&inter, start_end[0], src);
		start_end[0]++;
	}
	return (NULL);
}
