/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:32:31 by cschoen           #+#    #+#             */
/*   Updated: 2019/10/06 23:19:58 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw(t_rt *rt)
{
	ray_trace(rt->img, rt->cam, rt->shapes, p2_set(0, 0), rt->light);

	mlx_put_image_to_window(rt->win->mlx_ptr, rt->win->win_ptr,
							rt->img->img_ptr, 0, 0);
}

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

t_vector3 *get_normal(t_inter		*inter, t_ray *ray, double t)
{
	t_vector3	*hit_point;
	t_vector3	*tmp;

	tmp = v3_new_mult_by_num(ray->direction, t);
	hit_point = v3_new_plus(ray->origin, tmp);
	v3_del(&tmp);

	if (inter->shape->shape == SPHERE)
		return (get_sphere_normal((t_sphere*)inter->shape->content, hit_point));
	if (inter->shape->shape == PLANE)
		return (get_plane_normal((t_plane*)inter->shape->content, ray));
	if (inter->shape->shape == CONE)
	{
		t_cone *cone = (t_cone*)inter->shape->content;

		double angleRad = degrees_to_rad(cone->angle);
		double k = tan(angleRad);

        double tmp1 = dot(ray->direction, cone->dir) * t;
        t_vector3 *x = v3_new_minus(ray->origin, cone->position);
        double tmp2 = dot(x, cone->dir);
        double m = tmp1 + tmp2;
        
        t_vector3 *tmp3;
        t_vector3 *tmp4;
        t_vector3 *tmp5;
        t_vector3 *tmp6;
        if (hit_point->y < cone->position->y) {
            
  
            tmp3 = v3_new_minus(hit_point, cone->position);
            tmp4 = v3_new_mult_by_num(cone->dir, m);
            tmp5 = v3_new_minus(tmp3, tmp4);
            tmp6 = v3_new_mult_by_num(cone->dir, m);
        } else {
            t_vector3 *d = v3_new_mult_by_num(cone->dir, -1);
            
            tmp3 = v3_new_minus(hit_point, cone->position);
            tmp4 = v3_new_mult_by_num(d, m);
            tmp5 = v3_new_minus(tmp3, tmp4);
            tmp6 = v3_new_mult_by_num(d, m);
        }
		

		//t_vector3 *tmp6 = v3_new_mult_by_num(cone->dir, m);
		t_vector3 *tmp7 = v3_new_mult_by_num(tmp6, k);
		t_vector3 *tmp8 = v3_new_mult_by_num(tmp7, k);

        t_vector3 *fin;
        if (hit_point->y < cone->position->y)
            fin = v3_new_minus(tmp5, tmp8);
        else
            fin = v3_new_minus(tmp5, tmp5);

		t_vector3 *N = v3_new_div_by_num(fin, length(fin));
		v3_del(&tmp3);
		v3_del(&tmp4);
		v3_del(&tmp5);
		v3_del(&tmp6);
		v3_del(&tmp7);
		v3_del(&tmp8);
		v3_del(&fin);
		return N;

		//////////////////////

//		double tmp1 = dot(ray->direction, cone->dir) * t;
//		t_vector3 *x = v3_new_minus(ray->origin, cone->position);
//		double tmp2 = dot(x, cone->dir);
//		double m = tmp1 + tmp2;
//
//		//search intersec point
//		t_vector3 *tmp3 = v3_new_mult_by_num(ray->direction, t);
//		t_vector3 *P = v3_new_plus(ray->origin, tmp3);
//
//		t_vector3 *tmp4 = v3_new_minus(P, cone->position);
//
//		double angleRad = degrees_to_rad(cone->angle);
//		double tmp5 = 1 + tan(angleRad) * tan(angleRad);
//
//		t_vector3 *tmp6 = v3_new_mult_by_num(cone->dir, tmp5);
//		t_vector3 *tmp7 = v3_new_mult_by_num(tmp6, m);
//
//		t_vector3 *fin = v3_new_minus(tmp4, tmp7);
//
//		t_vector3 *N = v3_new_div_by_num(fin, length(fin));
//		return N;

		//////////////////////

//		t_vector3 *dirC = v3_new_mult_by_num(cone->dir, -1);
//
//		t_vector3 *tmp1 = v3_new_mult_by_num(ray->direction, t);
//		t_vector3 *tmp2 = v3_new_plus(ray->origin, tmp1);
//		t_vector3 *tmp3 = v3_new_minus(tmp2, cone->position);
//
//
//        double angleRad = degrees_to_rad(cone->angle);
//        double angleTmp = 1 + tan(angleRad) * tan(angleRad);
//		double tmp4 = dot(tmp3, dirC) * angleTmp;
//
//		t_vector3 *tmp5 = v3_new_mult_by_num(dirC, tmp4);
//		t_vector3 *tmp6 = v3_new_minus(tmp3, tmp5);
//
//		t_vector3 *N = v3_new_div_by_num(tmp6, length(tmp6));
//
//		return N;


	}
	else if (inter->shape->shape == CYLINDER)
		return (get_cyl_normal((t_cylinder*)inter->shape->content, ray, hit_point, t));
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
			if (shapeset_intersect(inter, scene))
			{
				t_vector3 *tmp1 = v3_new_mult_by_num(ray->direction, inter->t);
				t_vector3 *P = v3_new_plus(ray->origin, tmp1);
				t_vector3 *N;

				N = get_normal(inter, ray, inter->t);
				t_vector3 *to_cam = v3_new_mult_by_num(ray->direction, -1);

				light_percent = compute_light(P, N, lights, to_cam, get_specular(inter));
				t_color *tmp = get_color_from_list(inter->shape);
				*cur_pixel = get_color(tmp, light_percent);
				v3_del(&P);
				v3_del(&N);
				v3_del(&tmp1);
			}
			else
				*cur_pixel = 0;
			ray_del(&ray);
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

_Bool	is_move(int key)
{
	return (key == W_KEY || key == S_KEY || key == A_KEY || key == D_KEY ||
			key == Q_KEY || key == E_KEY);
}

int	deal_key(int key, void *param)
{
	t_rt	*rt;

	rt = (t_rt*)param;
	if (key == ESC)
		red_x_button(param);
	if (is_move(key))
		recalc_cam_dp(rt->cam, key, v3_new3(0.0, 1.0, 0.0),
			v2_new2(25.0 * PI / 180, (double)rt->size.x / (double)rt->size.y));
	draw(rt);
	return (0);
}

static void	input_hook(t_rt *rt)
{
	mlx_hook(rt->win->win_ptr, 17, 1, red_x_button, (void *)0);
	mlx_hook(rt->win->win_ptr, 2, 3, deal_key, (void *)rt);
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

	rt->cam = camera_new_dp(v3_new3(0.0, 8.0, 50.0),
							v3_new3(0.0, 0.0, 0.0),
							v3_new3(0.0, 1.0, 0.0),
							v2_new2(25.0 * PI / 180,
									(double)rt->size.x / (double)rt->size.y));


	//create object
	sphere = sphere_new_dp(v3_new3(-5, 0, 13), 3.0);
	sphere->color->b = 0;
	sphere->color->g = 0;
	//add object to all shapes
	sphere->specular = 300;
	rt->shapes = new_shape_list((void*)sphere, sphere->shape);


	t_sphere *sphere1 = sphere_new_dp(v3_new3(5, 0, 13), 3.0);
	sphere1->color->b = 0;
	sphere1->color->g = 0;
	//add object to all shapes
	sphere1->specular = 300;
	add_new_shape(rt->shapes, (void*)sphere1, sphere1->shape);


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


	t_vector3 *posit1 = v3_new3(0, 0, -55);
	t_vector3 *norm1 = v3_new3(0, 0, 1);
	t_plane *plane1 = plane_new(posit1, norm1);
	plane1->color = white();
	plane1->color->r = 0;
	plane1->color->g = 0;
	plane1->shape = PLANE;
	plane1->specular = 0;
	add_new_shape(rt->shapes, (void*)plane1, plane->shape);


	//test CONE
	t_cone *cone = (t_cone*)malloc(sizeof(t_cone));
	cone->angle = 90;
	cone->color = white();
	cone->color->r = 0;
	cone->color->b = 0;
	cone->position = v3_new3(4, 5, 0);
	cone->dir = v3_new3(0, 1, 0);
	cone->shape = CONE;
	add_new_shape(rt->shapes, (void*)cone, cone->shape);

	//create light

	t_light *l1 = (t_light*)malloc(sizeof(t_light));
	l1->type = ambient;
	l1->intensity = 0.2;
	l1->position = NULL;
	rt->light = new_light_list(l1, l1->type);


	t_sphere *sun = sphere_new_dp(v3_new3(4, 5, 5), 0.3);
	sun->color->b = 0;
	sun->specular = -1;
	add_new_shape(rt->shapes, (void*)sun, sun->shape);

	t_light *light = (t_light*)malloc(sizeof(t_light));
	light->type = point;
	light->intensity = 0.5;
	light->position = v3_new3(4, 5, 5);
	add_new_light(rt->light, light, light->type);


	t_light *l2 = (t_light*)malloc(sizeof(t_light));
	l2->type = directional;
	l2->intensity = 0.4;
	l2->position = v3_new3(0, 2, 2);
	add_new_light(rt->light, l2, l2->type);


	//CYL test
	t_cylinder *cyl = (t_cylinder*)malloc(sizeof(t_cylinder));
	cyl->position = v3_new3(0, 0, 10);
	cyl->dir = v3_new3(0, 1, 0);
	cyl->color = white();
	cyl->color->g = 0;
	cyl->radius = 2;
	cyl->lenght = 5; // ???
	cyl->shape = CYLINDER;
	add_new_shape(rt->shapes, (void*)cyl, cyl->shape);

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
