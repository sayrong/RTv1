/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 03:47:36 by cschoen           #+#    #+#             */
/*   Updated: 2019/10/02 01:55:00 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_point2	p2_set(int x, int y)
{
	t_point2	new_p2;

	new_p2.x = x;
	new_p2.y = y;
	return (new_p2);
}

t_vector2	v2_set(double u, double v)
{
	t_vector2	new_v2;

	new_v2.u = u;
	new_v2.v = v;
	return (new_v2);
}

void	v2_del(t_vector2 **vec)
{
	if (vec != NULL && *vec != NULL)
	{
		free(*vec);
		*vec = NULL;
	}
}

t_vector2	*v2_new(void)
{
	t_vector2	*new_vec;

	if (!(new_vec = (t_vector2*)malloc(sizeof(t_vector2))))
		error("v2_new: ");
	new_vec->u = 0.0;
	new_vec->v = 0.0;
	return (new_vec);
}

t_vector2	*v2_new1(double f)
{
	t_vector2	*new_vec;

	if (!(new_vec = (t_vector2*)malloc(sizeof(t_vector2))))
		error("v2_new1: ");
	new_vec->u = f;
	new_vec->v = f;
	return (new_vec);
}

t_vector2	*v2_new2(double u, double v)
{
	t_vector2	*new_vec;

	if (!(new_vec = (t_vector2*)malloc(sizeof(t_vector2))))
		error("v2_new2: ");
	new_vec->u = u;
	new_vec->v = v;
	return (new_vec);
}

t_vector2	*v2_new_copy(t_vector2 *vec)
{
	t_vector2	*new_vec;

	if (!vec)
		null_error();
	if (!(new_vec = (t_vector2*)malloc(sizeof(t_vector2))))
		error("v2_new_copy: ");
	new_vec->u = vec->u;
	new_vec->v = vec->v;
	return (new_vec);
}

t_vector2	*v2_copy(t_vector2 *vec1, t_vector2 *vec2)
{
	if (!vec2)
		v2_del(&vec1);
	else if (!vec1)
		vec1 = v2_new_copy(vec2);
	else
	{
		vec1->u = vec2->u;
		vec1->v = vec2->v;
	}
	return (vec1);
}
