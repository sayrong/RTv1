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

void	draw(t_rt *rt)
{
	ray_trace(rt, p2_set(0, 0));
	mlx_put_image_to_window(rt->win->mlx_ptr, rt->win->win_ptr,
							rt->img->img_ptr, 0, 0);
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

int		deal_key(int key, void *param)
{
	t_rt	*rt;

	rt = (t_rt*)param;
	if (key == ESC)
		red_x_button(param);
	if (is_move(key))
		recalc_cam_dp(rt->cam, key, v3_new3(0.0, 1.0, 0.0),
						v2_new2(25.0 * PI / 180,
							(double)rt->size.x / (double)rt->size.y));
	draw(rt);
	return (0);
}
