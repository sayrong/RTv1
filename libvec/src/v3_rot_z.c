/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_rot_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 21:26:24 by cschoen           #+#    #+#             */
/*   Updated: 2019/10/07 21:27:49 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3	v3_rot_z(t_vec3 v, double angle)
{
	t_vec3	new_v;

	new_v.x = v.x * cos(angle) - v.y * sin(angle);
	new_v.y = v.x * sin(angle) + v.y * cos(angle);
	new_v.z = v.z;
	return (new_v);
}
