/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:32:31 by cschoen           #+#    #+#             */
/*   Updated: 2019/10/14 04:01:55 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			red_x_button(void *param)
{
	(void)param;
	exit(0);
}

static void	input_hook(t_rt *rt)
{
	mlx_hook(rt->win_ptr, 17, 1, red_x_button, (void *)0);
	mlx_hook(rt->win_ptr, 2, 3, deal_key, (void *)rt);
}

static void	basic_init(t_rt *rt)
{
	rt->cam_flg = FALSE;
	rt->amb_flg = FALSE;
	rt->lights = NULL;
	rt->shapes = NULL;
}

static void	secondary_init(t_rt *rt)
{
	if (!(rt->mlx_ptr = mlx_init()))
		p_error("Failed to set up the connection to the X server");
	rt->win_ptr = mlx_new_window(rt->mlx_ptr, WIDTH, HEIGHT, "RTv1");
	!rt->win_ptr ? p_error("Failed to create a new window") : 0;
	rt->img = img_new(WIDTH, HEIGHT, rt);
}

int			main(int argc, char **argv)
{
	t_rt	rt;
	int		fd;
	int		parse_line;

	fd = 0;
	parse_line = 0;
	if (argc != 2)
		usage(argv[0]);
	basic_init(&rt);
	parser(argv[1], &rt, fd, parse_line);
	secondary_init(&rt);
	draw(&rt);
	input_hook(&rt);
	mlx_loop(rt.mlx_ptr);
	return (0);
}
