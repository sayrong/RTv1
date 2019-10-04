/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 23:59:26 by cschoen           #+#    #+#             */
/*   Updated: 2019/10/02 00:11:21 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_inter		*inter_new(void)
{
	t_inter	*new_inter;

	if (!(new_inter = (t_inter*)malloc(sizeof(t_inter))))
		error("inter_new: ");
	new_inter->ray = ray_new();
	new_inter->t = RAY_T_MAX;
	new_inter->shape = NULL;
	return (new_inter);
}

t_inter		*inter_new_ray(t_ray *ray)
{
	t_inter	*new_inter;

	if (!ray)
		null_error();
	if (!(new_inter = (t_inter*)malloc(sizeof(t_inter))))
		error("inter_new_ray: ");
	new_inter->ray = ray_new_copy(ray);
	new_inter->t = ray->t_max;
	new_inter->shape = NULL;
	return (new_inter);
}

//t_inter		*inter_new_copy(t_inter *inter)
//{
//	t_inter	*new_inter;
//
//	if (!inter)
//		null_error();
//	if (!(new_inter = (t_inter*)malloc(sizeof(t_inter))))
//		error("inter_new_copy: ");
//	new_inter->ray = ray_new_copy(inter->ray);
//	new_inter->t = inter->t;
//	new_inter->shape = shape_new_copy(inter->shape);
//	return (new_inter);
//}

//t_inter		*inter_copy(t_inter *inter1, t_inter *inter2)
//{
//	if (!inter2)
//		inter_del(&inter1);
//	else if (!inter1)
//		inter1 = inter_new_copy(inter2);
//	else
//	{
//		inter1->ray = ray_copy(inter1->ray, inter2->ray);
//		inter1->t = inter2->t;
//		inter1->shape = shape_copy(inter1->shape, inter2->shape);
//	}
//	return (inter1);
//}

t_vector3	*position(t_inter *inter)
{
	if (!inter)
		null_error();
	return (calculate(inter->ray, inter->t));
}

_Bool		intersected(t_inter *inter)
{
	if (!inter)
		null_error();
	return (inter->shape != NULL);
}
