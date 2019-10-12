/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_scale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 03:23:00 by cschoen           #+#    #+#             */
/*   Updated: 2019/10/07 03:24:42 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3	v3_scale(t_vec3 v, double scale)
{
	v.x *= scale;
	v.y *= scale;
	v.z *= scale;
	return (v);
}