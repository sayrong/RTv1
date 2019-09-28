/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:44:23 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/28 22:44:10 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void		error(char *str)
{
	perror(str);
	exit(1);
}

t_vector	*v_new(void)
{
	t_vector	*new_v;

	if (!(new_v = (t_vector*)malloc(sizeof(t_vector))))
		error("v_new: ");
	new_v->x = 0;
	new_v->y = 1;
	new_v->z = 0;
	return (new_v);
}

t_vector	*v_new1(double f)
{
	t_vector	*new_v;

	if (!(new_v = (t_vector*)malloc(sizeof(t_vector))))
		error("v_new1: ");
	new_v->x = f;
	new_v->y = f;
	new_v->z = f;
	return (new_v);
}

t_vector	*v_new3(double x, double y, double z)
{
	t_vector	*new_v;

	if (!(new_v = (t_vector*)malloc(sizeof(t_vector))))
		error("v_new3: ");
	new_v->x = x;
	new_v->y = y;
	new_v->z = z;
	return (new_v);
}

t_vector	*v_copy(t_vector *v)
{
	t_vector	*new_v;

	if (!(new_v = (t_vector*)malloc(sizeof(t_vector))))
		error("v_copy: ");
	new_v->x = v->x;
	new_v->y = v->y;
	new_v->z = v->z;
	return (new_v);
}
