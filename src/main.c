/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:32:31 by cschoen           #+#    #+#             */
/*   Updated: 2019/10/02 03:41:02 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	put_error(char *str)
{
	if (str)
		ft_putendl(str);
	exit(1);
}

t_vector3 *get_center(t_inter		*inter)
{
	if (inter->shape->shape == SPHERE)
		return ((t_sphere*)inter->shape->content)->center;
	if (inter->shape->shape == PLANE)
		return ((t_plane*)inter->shape->content)->normal;
	if (inter->shape->shape == CONE)
		return ((t_cone*)inter->shape->content)->dir;
	else
		return NULL;
}


int get_specular(t_inter		*inter)
{
	if (inter->shape->shape == SPHERE)
		return ((t_sphere*)inter->shape->content)->specular;
	if (inter->shape->shape == PLANE)
		return ((t_plane*)inter->shape->content)->specular;
	else
		return 0;
}

void	ray_trace(t_img *img, t_cam *cam, t_list_shape *scene, t_point2 size, t_list_light *lights)
{
	t_vector2	screen_coord;
	t_ray		*ray;
	int			*cur_pixel;
	t_inter		*inter;
	double		light_percent;

	(!img || !cam || !scene) ? null_error() : 0;
	size.x = -1;
	while (++size.x < img->width)
	{
		size.y = -1;
		while (++size.y < img->height)
		{
			screen_coord = v2_set((2.0 * size.x) / img->width - 1.0,
								(-2.0 * size.y) / img->height + 1.0);
			ray = make_ray(&screen_coord, cam);
			cur_pixel = get_pixel(size.x, size.y, img);
			inter = inter_new_ray(ray);
			//ray_del(&ray);
			if (shapeset_intersect(inter, scene))
			{
				//*cur_pixel = 255 << 16 | 255 << 8 | 255;
				
				t_vector3 *tmp1 = v3_new_mult_by_num(ray->direction, inter->t);
				t_vector3 *P = v3_new_plus(cam->origin, tmp1);
				t_vector3 *N = v3_new_minus(P, get_center(inter));
				N = v3_new_div_by_num(N, length(N));
				
				t_vector3 *to_cam = v3_new_mult_by_num(ray->direction, -1);
				
				light_percent = compute_light(P, N, lights, to_cam, get_specular(inter));
				t_color *tmp = get_color_from_list(inter->shape);
				*cur_pixel = get_color(tmp, light_percent);
			}
			else
				*cur_pixel = 0;
			inter_del(&inter);
		}
	}
}

t_win	*win_new(int width, int height)
{
	t_win	*new_win;

	if (!(new_win = (t_win*)malloc(sizeof(t_win))))
		error("win_new: ");
	if (!(new_win->mlx_ptr = mlx_init()))
		put_error("Failed to set up the connection to the X server");
	new_win->win_ptr = mlx_new_window(new_win->mlx_ptr, width, height, "RTv1");
	!new_win->win_ptr ? put_error("Failed to create a new window") : 0;
	new_win->width = width;
	new_win->height = height;
	return (new_win);
}

int	red_x_button(void *param)
{
	(void)param;
	exit(0);
}

int	deal_key(int key, void *param)
{
	if (key == 53 || key == 65307)
		red_x_button(param);
	return (0);
}

static void	input_hook(t_rt *rt)
{
	mlx_hook(rt->win->win_ptr, 17, 1, red_x_button, (void *)0);
	mlx_hook(rt->win->win_ptr, 2, 3, deal_key, (void *)0);
}

int testCodeDim()
{
	t_rt        *rt;
	t_sphere    *sphere;
	
	//Create camera
	if (!(rt = (t_rt*)malloc(sizeof(t_rt))))
		error("RT: ");
	
	rt->size = p2_set(WIDTH, HEIGHT);
	rt->win = win_new(rt->size.x, rt->size.y);
	rt->img = img_new(rt->size.x, rt->size.y, rt->win);
	
	rt->cam = camera_new_dp(v3_new3(0.0, 5.0, 30.0),
							v3_new3(0.0, -20.0, -30.0),
							v3_new3(0.0, 1.0, 0.0),
							v2_new2(25.0 * PI / 180,
									(double)rt->size.x / (double)rt->size.y));
	
	
	//create object
	sphere = sphere_new_dp(v3_new3(0, 0, 13), 3.0);
	sphere->color->b = 0;
	sphere->color->g = 0;
	//add object to all shapes
	sphere->specular = 100;
	rt->shapes = new_shape_list((void*)sphere, sphere->shape);
	
	
	//create plane
	t_vector3 *posit = v3_new3(0, 0, 0);
	t_vector3 *norm = v3_new3(0, 1, 0);
	t_plane *plane = plane_new(posit, norm);
	plane->color = white();
	plane->color->r = 0;
	plane->color->g = 0;
	plane->shape = PLANE;
	plane->specular = 0;
	add_new_shape(rt->shapes, (void*)plane, plane->shape);
	
	
	//test CONE
	t_cone *cone = (t_cone*)malloc(sizeof(t_cone));
	cone->angle = 10;
	cone->color = white();
	cone->position = v3_new3(5, 0, -50);
	cone->dir = v3_new3(0, 1, 0);
	cone->shape = CONE;
	//add_new_shape(rt->shapes, (void*)cone, cone->shape);

	//create light
	
	t_light *l1 = (t_light*)malloc(sizeof(t_light));
	l1->type = ambient;
	l1->intensity = 0.2;
	l1->position = NULL;
	rt->light = new_light_list(l1, l1->type);
	
	t_light *light = (t_light*)malloc(sizeof(t_light));
	light->type = point;
	light->intensity = 0.5;
	light->position = v3_new3(0, 6, 17);
	add_new_light(rt->light, light, light->type);

	
	t_light *l2 = (t_light*)malloc(sizeof(t_light));
	l2->type = directional;
	l2->intensity = 0.2;
	l2->position = v3_new3(0, 8, 15);
	add_new_light(rt->light, l2, l2->type);

	
	
	ray_trace(rt->img, rt->cam, rt->shapes, p2_set(0, 0), rt->light);
	
	
	mlx_put_image_to_window(rt->win->mlx_ptr, rt->win->win_ptr,
							rt->img->img_ptr, 0, 0);
	ft_putendl("ready");
	input_hook(rt);
	mlx_loop(rt->win->mlx_ptr);
	
	return (0);
}



int		main(void)
{
	
	testCodeDim();
	
	return (0);
}
