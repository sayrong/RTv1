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
//
//  4) Сделать цилиндр под стек +
//  5) Сделать конус под стек ++
 */


#include "rt.h"

//испрользовать просто error
void	put_error(char *str)
{
	if (str)
		ft_putendl(str);
	exit(1);
}

static void	input_hook(t_rt *rt)
{
	mlx_hook(rt->win_ptr, 17, 1, red_x_button, (void *)0);
	mlx_hook(rt->win_ptr, 2, 3, deal_key, (void *)rt);
}

void initial_setup(t_rt *rt)
{
	setup_mlx(rt);
	rt->img = img_new(WIDTH, HEIGHT, rt);
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
	mlx_loop(rt.mlx_ptr);
	return (0);
}
