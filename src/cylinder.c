//
//  cylinder.c
//  RTV2
//
//  Created by Babette Alvyn sharp on 05/10/2019.
//  Copyright © 2019 Babette Alvyn sharp. All rights reserved.
//

#include "rt.h"

_Bool	cylinder_intersect(t_inter *inter, t_list_shape *shape_in_list)
{
	// a = D|D - (D|V)^2
	// b/2 = D|X - (D|V)*(X|V)
	// c = X|X - (X|V)^2 - r*r
	
	double		abc[3];
	double		t[2];
	t_vector3	*x;
	t_cylinder	*cylinder;
	double		d;
	
	cylinder = ((t_cylinder*)shape_in_list->content);
	x = v3_new_minus(inter->ray->origin, cylinder->position);
	abc[0] = dot(inter->ray->direction, inter->ray->direction) - pow(dot(inter->ray->direction, cylinder->dir), 2);
	abc[1] = 2 * (dot(inter->ray->direction, x) - (dot(inter->ray->direction, cylinder->dir) * dot(x, cylinder->dir)));
	abc[2] = dot(x, x) - pow(dot(x, cylinder->dir), 2) - cylinder->radius * cylinder->radius;
	d = pow(abc[1],2) - 4 * abc[0] * abc[2];
	free(x);
	if (d < 0)
		return (FALSE);
	t[0] = (-abc[1] + sqrt(d)) / (2 * abc[0]);
	t[1] = (-abc[1] - sqrt(d)) / (2 * abc[0]);
	if (!define_t(t[0], t[1], &(inter->t)))
	{
		inter->shape = shape_in_list;
		return (TRUE);
	}
	return (FALSE);
}



t_vector3 *get_cyl_normal(t_cylinder *cyl, t_ray *ray, t_vector3 *hit_point, double t)
{
	//N = nrm( P-C-V*m )
	//m = D|V*t + X|V
	//scalar that determines the closest point on the axis
	double		m;
	t_vector3	*x;
	t_vector3	*tmp[3];
	t_vector3	*normal;

	x = v3_new_minus(ray->origin, cyl->position);
	m = dot(ray->direction, cyl->dir) * t + dot(x, cyl->dir);;
	tmp[0] = v3_new_minus(hit_point, cyl->position);
	tmp[1] = v3_new_mult_by_num(cyl->dir, m);
	tmp[2] = v3_new_minus(tmp[0], tmp[1]);
	normal = v3_new_div_by_num(tmp[2], length(tmp[2]));
	free_temp_v(tmp, 3);
	return (normal);
}
