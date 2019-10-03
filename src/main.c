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

double compute_light(t_vector3 *P, t_vector3 *N, t_shapeset *scene)
{
    double i;
    int count;
    t_light *light;
    t_vector3 *L;
    double res;
    
    i = 0;
    count = 0;
    while (count < 2)
    {
        light = scene->light[count];
        if (light->type == ambient)
            i += light->intensity;
        else
        {
            if (light->type == point)
                L = v3_new_minus(light->position, P);
            else
                L = light->position;
            res = dot(N, L);
            if (res > 0)
            {
                double tmp1 = light->intensity * res;
                double tmp2 = length(N) * length(L);
                double tmp3 = tmp1 / tmp2;
                i += tmp3;
            }
        }
        count++;
    }
    return (i);
}

void	ray_trace(t_img *img, t_cam *cam, t_shapeset *scene, t_point2 size)
{
	t_vector2	screen_coord;
	t_ray		*ray;
	int			*cur_pixel;
	t_inter		*inter;

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
                t_vector3 *tmp1 = v3_new_mult_by_num(ray->direction, inter->t);
                t_vector3 *P = v3_new_plus(cam->origin, tmp1);
                t_vector3 *N = v3_new_minus(P, v3_new3(1, 1, 1));
                N = v3_new_div_by_num(N, length(N));
                double l = compute_light(P, N, scene);
				////*cur_pixel = 255 << 16 | 255 << 8 | 255;
                *cur_pixel = get_color(inter->shape->sphere->color, l);
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

int testCodeDan()
{
    t_rt        *rt;
    t_plane        *floor;
    t_shape        *sh_plane;
    t_sphere    *sphere;
    t_shape        *sh_sphere;
    t_sphere    *sphere2;
    t_shape        *sh_sphere2;
    t_sphere    *sphere3;
    t_shape        *sh_sphere3;
    t_plane        *plane;
    t_shape        *shape_pl;
    
    if (!(rt = (t_rt*)malloc(sizeof(t_rt))))
        error("RT: ");
    rt->size = p2_set(WIDTH, HEIGHT);
    rt->win = win_new(rt->size.x, rt->size.y);
    rt->img = img_new(rt->size.x, rt->size.y, rt->win);
    // dp - means "delete params"
    rt->cam = camera_new_dp(v3_new3(-5.0, 0.0, 0.0),
                            v3_new3(0.0, 0.0, 0.0),
                            v3_new3(0.0, 1.0, 0.0),
                            v2_new2(25.0 * PI / 180,
                                    (double)rt->size.x / (double)rt->size.y));
    rt->scene = shapeset_new(2);
    
    floor = plane_new_dp(v3_new3(0.0, -4.0, 1.0), v3_new3(-1.0, 4.0, -2.0));
    plane = plane_new_dp(v3_new3(0.0, -4.0, 1.0), v3_new3(1.0, 8.0, -2.0));
    sphere = sphere_new_dp(v3_new3(3.0, 2.0, 1.4), 1.0);
    sphere2 = sphere_new_dp(v3_new3(3.0, 2.0, 2.0), 1.0);
    sphere3 = sphere_new_dp(v3_new3(3.0, 2.0, 0.8), 1.0);
    
    sh_plane = shape_new();
    sh_plane->plane = floor;
    sh_plane->type = PLANE;
    //    sh_plane = NULL;
    //    sh_plane = shape_copy_plane(sh_plane, floor);
    
    sh_sphere = shape_new();
    sh_sphere->sphere = sphere;
    sh_sphere->type = SPHERE;
    //    sh_sphere = NULL;
    //    sh_sphere = shape_copy_sphere(sh_sphere, sphere);
    
    shape_pl = NULL;
    shape_pl = shape_copy_plane(shape_pl, plane);
    
    sh_sphere2 = NULL;
    sh_sphere2 = shape_copy_sphere(sh_sphere2, sphere2);
    
    sh_sphere3 = NULL;
    sh_sphere3 = shape_copy_sphere(sh_sphere3, sphere3);
    
    rt->scene = add_shape(shape_pl, rt->scene);
    rt->scene = add_shape(sh_sphere, rt->scene);
    rt->scene = add_shape(sh_sphere3, rt->scene);
    rt->scene = add_shape(sh_sphere3, rt->scene);
    rt->scene = add_shape(sh_sphere2, rt->scene);
    rt->scene = add_shape(sh_sphere, rt->scene);
    rt->scene = add_shape(sh_sphere2, rt->scene);
    //    rt->scene = add_shape(sh_plane, rt->scene);
    
    ray_trace(rt->img, rt->cam, rt->scene, p2_set(0, 0));
    mlx_put_image_to_window(rt->win->mlx_ptr, rt->win->win_ptr,
                            rt->img->img_ptr, 0, 0);
    ft_putendl("ready");
    input_hook(rt);
    mlx_loop(rt->win->mlx_ptr);
    return (0);
}


int testCodeDim()
{
    t_rt        *rt;
    t_sphere    *sphere;
    t_shape     *sh_sphere;
    
    if (!(rt = (t_rt*)malloc(sizeof(t_rt))))
        error("RT: ");
    
    rt->size = p2_set(WIDTH, HEIGHT);
    rt->win = win_new(rt->size.x, rt->size.y);
    rt->img = img_new(rt->size.x, rt->size.y, rt->win);
    
    rt->cam = camera_new_dp(v3_new3(0.0, 0.0, 20.0),
                            v3_new3(0.0, 0.0, 0.0),
                            v3_new3(0.0, 1.0, 0.0),
                            v2_new2(25.0 * PI / 180,
                                    (double)rt->size.x / (double)rt->size.y));
    
    rt->scene = shapeset_new(2);
    
    sphere = sphere_new_dp(v3_new3(0, 0, 5), 3.0);
    sphere->color->g = 0;
    sphere->color->b = 0;
    
    sh_sphere = shape_new();
    sh_sphere->sphere = sphere;
    sh_sphere->type = SPHERE;
    
    rt->scene = add_shape(sh_sphere, rt->scene);
    
    //light
    t_light *l1 = (t_light*)malloc(sizeof(t_light));
    l1->type = ambient;
    l1->intensity = 0.2;
    l1->position = NULL;
    
    t_light *l2 = (t_light*)malloc(sizeof(t_light));
    l2->type = point;
    l2->intensity = 0.6;
    l2->position = v3_new3(4, 10, 5);
    
    rt->scene->light = (t_light**)malloc(sizeof(t_light*) * 2);
    rt->scene->light[0] = l1;
    rt->scene->light[1] = l2;
    
    t_sphere *sphere1 = sphere_new_dp(v3_new3(0, 2, 7), 2);
    sphere1->color->g = 255;
    sphere1->color->b = 0;
    
    t_shape     *sh_sphere1 = shape_new();
    sh_sphere1->sphere = sphere1;
    sh_sphere1->type = SPHERE;
    
    rt->scene = add_shape(sh_sphere1, rt->scene);
    ///
    
    ray_trace(rt->img, rt->cam, rt->scene, p2_set(0, 0));
    mlx_put_image_to_window(rt->win->mlx_ptr, rt->win->win_ptr,
                            rt->img->img_ptr, 0, 0);
    ft_putendl("ready");
    input_hook(rt);
    mlx_loop(rt->win->mlx_ptr);
    
    return (0);
}


int		main(void)
{
    //testCodeDan();
    testCodeDim();
}


