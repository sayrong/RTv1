/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_rot_y.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 21:24:32 by cschoen           #+#    #+#             */
/*   Updated: 2019/10/07 21:25:52 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3	v3_rot_y(t_vec3 v, double angle)
{
	t_vec3	new_v;

	new_v.x = v.x * cos(angle) + v.z * sin(angle);
	new_v.y = v.y;
	new_v.z = v.z * cos(angle) - v.x * sin(angle);
	return (new_v);
}
