/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_rot_zyx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 23:04:59 by cschoen           #+#    #+#             */
/*   Updated: 2019/10/08 21:53:36 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3	v3_rot_zyx(t_vec3 v, t_vec3 rotate)
{
	v = v3_rot_z(v, rotate.z * RAD);
	v = v3_rot_y(v, rotate.y * RAD);
	v = v3_rot_x(v, rotate.x * RAD);
	return (v);
}
