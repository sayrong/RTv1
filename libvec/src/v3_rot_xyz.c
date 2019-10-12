/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_rot_xyz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 21:28:32 by cschoen           #+#    #+#             */
/*   Updated: 2019/10/07 23:02:01 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3	v3_rot_xyz(t_vec3 v, t_vec3 rotate)
{
	v = v3_rot_x(v, rotate.x * RAD);
	v = v3_rot_y(v, rotate.y * RAD);
	v = v3_rot_z(v, rotate.z * RAD);
	return (v);
}
