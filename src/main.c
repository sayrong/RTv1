/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:32:31 by cschoen           #+#    #+#             */
/*   Updated: 2019/10/13 12:48:59 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	input_hook(t_rt *rt)
{
	mlx_hook(rt->win_ptr, 17, 1, red_x_button, (void *)0);
	mlx_hook(rt->win_ptr, 2, 3, deal_key, (void *)rt);
}

void		initial_setup(t_rt *rt)
{
	setup_mlx(rt);
	rt->img = img_new(WIDTH, HEIGHT, rt);
}

int		main(int argc, char *argv[])
{
	t_rt	rt;
	int		fd;
	int		parse_line;

	fd = 0;
	parse_line = 0;
	rt.cam_flg = FALSE;
	rt.amb_flg = FALSE;
	if (argc != 2)
		usage(argv[0]);
	parser(argv[1], &rt, fd, parse_line);
	initial_setup(&rt);
	draw(&rt);
	input_hook(&rt);
	mlx_loop(rt.mlx_ptr);
	return (0);
}
