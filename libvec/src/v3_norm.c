/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_norm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 03:38:49 by cschoen           #+#    #+#             */
/*   Updated: 2019/10/07 03:40:41 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3	v3_norm(t_vec3 v)
{
	return (v3_scale(v, 1.0 / v3_length(v)));
}