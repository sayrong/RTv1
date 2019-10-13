/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balvyn-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:03:54 by balvyn-s          #+#    #+#             */
/*   Updated: 2019/10/09 18:06:54 by balvyn-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		red_x_button(void *param)
{
	(void)param;
	exit(0);
}

_Bool	is_move(int key)
{
	return (key == W_KEY || key == S_KEY || key == A_KEY || key == D_KEY ||
			key == Q_KEY || key == E_KEY);
}






void setup_mlx(t_rt *rt)
{
	if (!(rt->mlx_ptr = mlx_init()))
		put_error("Failed to set up mlx");
	rt->win_ptr = mlx_new_window(rt->mlx_ptr, WIDTH, HEIGHT, "RTv1");
	!rt->win_ptr ? put_error("Failed to create a new window") : 0;
}

int		deal_key(int key, void *param)
{
	t_rt	*rt;

	rt = (t_rt*)param;
	if (key == ESC)
		red_x_button(param);
	if (is_move(key))
		recalc_cam_dp(&rt->cam, key, v3_new(0.0, 1.0, 0.0),
						v2_set(25.0 * PI / 180,
							(double)WIDTH / (double)HEIGHT));
	draw(rt);
	return (0);
}
