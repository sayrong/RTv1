/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balvyn-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:10:14 by balvyn-s          #+#    #+#             */
/*   Updated: 2019/10/09 18:37:19 by balvyn-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** a = D|D - (D|V)^2
** b/2 = D|X - (D|V)*(X|V)
** c = X|X - (X|V)^2 - r*r
*/

/*

_Bool	cylinder_intersect(t_inter *inter, t_list_shape *shape_in_list)
{
	double		abcd[4];
	double		t[2];
	t_vec3	*x;
	t_cylinder	*cylinder;

	cylinder = ((t_cylinder*)shape_in_list->content);
	x = v3_new_minus(inter->ray->origin, cylinder->position);
	abcd[0] = dot(inter->ray->direction, inter->ray->direction)
		- pow(dot(inter->ray->direction, cylinder->dir), 2);
	abcd[1] = 2 * (dot(inter->ray->direction, x)
			- (dot(inter->ray->direction, cylinder->dir)
				* dot(x, cylinder->dir)));
	abcd[2] = dot(x, x) - pow(dot(x, cylinder->dir), 2)
		- cylinder->radius * cylinder->radius;
	abcd[3] = pow(abcd[1], 2) - 4 * abcd[0] * abcd[2];
	free(x);
	if (abcd[3] < 0)
		return (FALSE);
	t[0] = (-abcd[1] + sqrt(abcd[3])) / (2 * abcd[0]);
	t[1] = (-abcd[1] - sqrt(abcd[3])) / (2 * abcd[0]);
	if (!define_t(t[0], t[1], inter, shape_in_list))
		return (TRUE);
	return (FALSE);
}



t_vec3	*get_cyl_normal(t_cylinder *cyl, t_ray *ray, t_vec3 *hit_point, double t)
{
	double		m;
	t_vec3	*x;
	t_vec3	*tmp[3];
	t_vec3	*normal;

	x = v3_new_minus(ray->origin, cyl->position);
	m = dot(ray->direction, cyl->dir) * t + dot(x, cyl->dir);
	tmp[0] = v3_new_minus(hit_point, cyl->position);
	tmp[1] = v3_new_mult_by_num(cyl->dir, m);
	tmp[2] = v3_new_minus(tmp[0], tmp[1]);
	normal = v3_new_div_by_num(tmp[2], length(tmp[2]));
	free_temp_v(tmp, 3);
	v3_del(&x);
	v3_del(&hit_point);
	return (normal);
}

*/
