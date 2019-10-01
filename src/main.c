/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:32:31 by cschoen           #+#    #+#             */
/*   Updated: 2019/10/01 03:38:41 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	put_error(char *str)
{
	if (!str)
		ft_putendl(str);
	exit(1);
}

void	ray_trace(t_img *img, t_cam *cam, t_shapeset *scene)
{
	t_point		size;
	t_vector2	*screen_coord;
	t_ray		*ray;
	int			*cur_pixel;
	t_inter		*inter;


	if (!img || !cam || !scene)
		null_error();
	size.x = -1;
	while (++size.x < img->width)
	{
		size.y = -1;
		while (++size.y < img->height)
		{
			screen_coord = v2_new2((2.0 * size.x) / img->width - 1.0,
								(-2.0 * size.y) / img->height + 1.0);
			ray = make_ray(screen_coord, cam);
			v2_del(&screen_coord);
			cur_pixel = get_pixel(size.x, size.y, img);
			inter = inter_new_ray(ray);
			ray_del(&ray);
			if (shapeset_intersect(inter, scene))
				*cur_pixel = 255 << 16 | 255 << 8 | 255;
			else
				*cur_pixel = 255 << 16;
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

static void	input_hook(t_win *win)
{
	mlx_hook(win->win_ptr, 17, 1, red_x_button, (void *)0);
	mlx_hook(win->win_ptr, 2, 3, deal_key, (void*)0);
}

int		main(void)
{
	int		width = 400;
	int		height = 200;
	t_win	*win = win_new(width, height);
	t_img	*img = img_new(width, height, win);
	t_cam	*cam = camera_new(v3_new3(-5.0, 1.0, 0.0), v3_new3(0.0, 1.0, 0.0),
		v3_new(), v2_new2(25.0 * PI / 180.0, (double)width / (double)height));
	t_plane	*floor = plane_new(v3_new3(0.0, 0.0, 0.0), v3_new());
	t_sphere	*sphere = sphere_new(v3_new3(0.0, 1.0, 0.0), 1.0);
	t_shape	*sh_plane = shape_new();
	t_shape	*sh_sphere = shape_new();
	t_shapeset	*scene;
	sh_plane->plane = floor;
	sh_plane->type = PLANE;
	sh_plane->sphere = sphere;
	sh_plane->type = SPHERE;
	//	shape_copy_plane(sh_plane, floor);
	//	shape_copy_sphere(sh_sphere, sphere);
	scene = shapeset_new(2);
	add_shape(sh_plane, scene);
	add_shape(sh_sphere, scene);
	ray_trace(img, cam, scene);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->img_ptr, 0, 0);
	ft_putendl("ready");
	input_hook(win);
	mlx_loop(win->mlx_ptr);
	return (0);
}
