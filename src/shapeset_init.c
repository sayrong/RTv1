/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapeset_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 23:48:51 by cschoen           #+#    #+#             */
/*   Updated: 2019/10/02 02:32:55 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

//t_shapeset	*shapeset_new(int size)
//{
//	t_shapeset	*new_set;
//	int			i;
//
//	if (size < 1 || size > 100)
//		put_error("Error: wrong shapeset size.\nRange of size [1...100]");
//	if (!(new_set = (t_shapeset*)malloc(sizeof(t_shapeset))))
//		error("shapeset_new: ");
//	if (!(new_set->shapes = (t_shape**)malloc(sizeof(t_shape*) * (size + 1))))
//		error("shapeset_new: ");
//	i = -1;
//	while (++i <= size)
//		new_set->shapes[i] = NULL;
//	new_set->max_size = size;
//	new_set->size = 0;
//	return (new_set);
//}
//
//t_shapeset	*resize_set(t_shapeset *set, int new_size)
//{
//	t_shape	**temp;
//	int		min;
//	int		i;
//
//	if (!set)
//		null_error();
//	if (new_size == set->max_size)
//		return (set);
//	temp = set->shapes;
//	if (!(set->shapes = (t_shape**)malloc(sizeof(t_shape*) * (new_size + 1))))
//		error("resize_set: ");
//	min = (new_size < set->size) ? new_size : set->size;
//	i = -1;
//	while (++i < min)
//		set->shapes[i] = temp[i];
//	if (new_size < set->size)
//		while (i < set->size)
//			shape_del(&temp[i++]);
//	else
//		while (i < new_size)
//			set->shapes[i++] = NULL;
//	ft_memdel((void**)temp);
//	set->shapes[new_size] = NULL;
//	set->max_size = new_size;
//	return (set);
//}

//t_shapeset	*add_shape(t_shape *shape, t_shapeset *set)
//{
//	if (!set)
//		null_error();
//	if (!shape)
//		return (set);
//	if (set->size == set->max_size && set->max_size == 100)
//		put_error("Error: Shapeset Overflow.");
//	if (set->size == set->max_size)
//	{
//		if (set->max_size * 2 < 100)
//			set = resize_set(set, set->max_size * 2);
//		else
//			set = resize_set(set, 100);
//	}
//	set->shapes[set->size] = shape_copy(set->shapes[set->size], shape);
//	++set->size;
//	return (set);
//}


_Bool		shapeset_intersect(t_inter *inter, t_list_shape *shape_list)
{
	_Bool	does_intersect;
	int		i;
	t_list_shape *shape;

	i = 0;
	shape = shape_list;
	if (!inter || !shape)
		put_error("shape intersect");
	does_intersect = FALSE;
	
	//iterate throw all object in scene
	while (shape != NULL) {
		i += shape_intersect(inter, shape);
		shape = shape->next;
	}
	if (i > 0)
		does_intersect = TRUE;
	return (does_intersect);
}

//_Bool		shapeset_does_intersect(t_ray *ray, t_shapeset *set)
//{
//	int	i;
//
//	if (!ray || !set)
//		null_error();
//	i = -1;
//	while (++i < set->size)
//		if (shape_does_intersect(ray, set->shapes[i]))
//			return (TRUE);
//	return (FALSE);
//}

