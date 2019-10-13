/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 12:21:01 by cschoen           #+#    #+#             */
/*   Updated: 2019/10/13 12:23:26 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_point2	p2_set(int x, int y)
{
	t_point2	new_p2;

	new_p2.x = x;
	new_p2.y = y;
	return (new_p2);
}

t_vec2		v2_set(double u, double v)
{
	t_vec2	new_v2;

	new_v2.u = u;
	new_v2.v = v;
	return (new_v2);
}

double		length_sq(t_vec3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

t_vec3		v3_div(t_vec3 v, double a)
{
	v.x /= a;
	v.y /= a;
	v.z /= a;
	return (v);
}
