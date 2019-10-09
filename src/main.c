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

/*
//	1) Переписать под норму код для пересечения цилиндра +
//	2) Переписать под норму код для пересечения конуса +
//	3) Переписать свет под норму +
//	4) Сдлеать сцены как задании
 */


#include "rt.h"

void	put_error(char *str)
{
	if (str)
		ft_putendl(str);
	exit(1);
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

//	rt->cam = camera_new_dp(v3_new3(0.0, 8.0, 50.0),
//							v3_new3(0.0, 0.0, 0.0),
//							v3_new3(0.0, 1.0, 0.0),
//							v2_new2(25.0 * PI / 180,
//									(double)rt->size.x / (double)rt->size.y));


	//create object
	sphere = sphere_new_dp(v3_new3(-5, 0, 13), 3.0);
	sphere->color->b = 0;
	sphere->color->g = 0;
	//add object to all shapes
	sphere->specular = 300;
	rt->shapes = new_shape_list((void*)sphere, sphere->shape);


	t_sphere *sphere1 = sphere_new_dp(v3_new3(4, 5, 0), 3.0);
	sphere1->color->b = 0;
	sphere1->color->g = 0;
	//add object to all shapes
	sphere1->specular = 300;
	//add_new_shape(rt->shapes, (void*)sphere1, sphere1->shape);
    //rt->shapes = new_shape_list((void*)sphere1, sphere1->shape);
    
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
	//rt->shapes = new_shape_list((void*)plane, plane->shape);


	t_vector3 *posit1 = v3_new3(0, 0, -55);
	t_vector3 *norm1 = v3_new3(0, 0, 1);
	t_plane *plane1 = plane_new(posit1, norm1);
	plane1->color = white();
	plane1->color->r = 0;
	plane1->color->g = 0;
	plane1->shape = PLANE;
	plane1->specular = 0;
	//add_new_shape(rt->shapes, (void*)plane1, plane1->shape);
	

	//test CONE
	t_cone *cone = (t_cone*)malloc(sizeof(t_cone));
	cone->angle = 90;
	cone->color = white();
	cone->color->r = 0;
	cone->color->b = 0;
	cone->position = v3_new3(4, 5, 0);
	cone->dir = v3_new3(0, 1, 0);
	cone->shape = CONE;
	//add_new_shape(rt->shapes, (void*)cone, cone->shape);
	//rt->shapes = new_shape_list((void*)cone, cone->shape);

	//create light

	t_light *l1 = (t_light*)malloc(sizeof(t_light));
	l1->type = ambient;
	l1->intensity = 0.2;
	l1->position = NULL;
	rt->lights = new_light_list(l1, l1->type);


	t_sphere *sun = sphere_new_dp(v3_new3(10, 10, 6), 0.3); //10 10 6
	sun->color->b = 0;
	sun->specular = -1;
	//add_new_shape(rt->shapes, (void*)sun, sun->shape);

	t_light *light = (t_light*)malloc(sizeof(t_light));
	light->type = point;
	light->intensity = 0.5;
	light->position = v3_new3(10, 10, 6);
	add_new_light(rt->lights, light, light->type);


	t_light *l2 = (t_light*)malloc(sizeof(t_light));
	l2->type = directional;
	l2->intensity = 0.4;
	l2->position = v3_new3(0, 0, 1);
	//add_new_light(rt->light, l2, l2->type);


	//CYL test
	t_cylinder *cyl = (t_cylinder*)malloc(sizeof(t_cylinder));
	cyl->position = v3_new3(4, 5, 0);
	cyl->dir = v3_new3(0, 1, 0);
	cyl->color = white();
	cyl->color->g = 0;
	cyl->radius = 3;
	//cyl->lenght = 5; // ???
	cyl->shape = CYLINDER;
	cyl->specular = 10;
	add_new_shape(rt->shapes, (void*)cyl, cyl->shape);

	//ray_trace(rt->img, rt->cam, rt->shapes, p2_set(0, 0), rt->lights);


	mlx_put_image_to_window(rt->win->mlx_ptr, rt->win->win_ptr,
							rt->img->img_ptr, 0, 0);
	ft_putendl("ready");
	input_hook(rt);
	mlx_loop(rt->win->mlx_ptr);

	return (0);
}

void initial_setup(t_rt *rt)
{
	rt->size = p2_set(WIDTH, HEIGHT);
	rt->win = win_new(rt->size.x, rt->size.y);
	rt->img = img_new(rt->size.x, rt->size.y, rt->win);
}


int select_scene(char *name, t_rt *rt)
{
	if (!ft_strcmp(name, "scene1"))
		scene1(rt);
	else if (!ft_strcmp(name, "scene2"))
		scene2(rt);
	else if (!ft_strcmp(name, "scene3"))
		scene3(rt);
	else if (!ft_strcmp(name, "scene4"))
		scene4(rt);
	else if (!ft_strcmp(name, "scene5"))
		scene1(rt);
	else if (!ft_strcmp(name, "scene6"))
		scene1(rt);
	else if (!ft_strcmp(name, "scene7"))
		scene1(rt);
	else if (!ft_strcmp(name, "exp"))
		scene1(rt);
	else
		return (1);
	return (0);
}

int		main(int argc, char *argv[])
{
	t_rt        rt;
	
	if (argc == 1)
		put_error("Select one of scenes - argv:[scene1 - scene7]");
	else if (argc > 2)
		put_error("Too many arguments");
	else if (select_scene(argv[1], &rt))
		put_error("Wrong argument");
	input_hook(&rt);
	mlx_loop(rt.win->mlx_ptr);
	return (0);
}
