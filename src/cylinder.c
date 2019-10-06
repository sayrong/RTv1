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
	double t1 = 0;
	double t2 = 0;

	t_cylinder *cylinder = ((t_cylinder*)shape_in_list->content);
	t_ray *local_ray = ray_new_copy(inter->ray);

	t_vector3 *x = v3_new_minus(local_ray->origin, cylinder->position);

	double tmp1 = dot(local_ray->direction, local_ray->direction);
	double tmp2 = pow(dot(local_ray->direction, cylinder->dir), 2);
	double a = tmp1 - tmp2;
	
	//a = dot(local_ray->direction, local_ray->direction) - pow(dot(local_ray->direction, cylinder->dir), 2);

	double tmp3 = dot(local_ray->direction, x);
	double tmp4 = dot(local_ray->direction, cylinder->dir);
	double tmp5 = dot(x, cylinder->dir);
	double tmp6 = tmp4 * tmp5;
	double b = 2 * (tmp3 - tmp6);
	
	//b = (dot(local_ray->direction, x) - dot(local_ray->direction, cylinder->dir) * dot(x, cylinder->dir)) * 2;

	double tmp7 = dot(x, x);
	double tmp8 = pow(dot(x, cylinder->dir), 2) + cylinder->radius * cylinder->radius;
	double c = tmp7 - tmp8;

	double Discr = pow(b, 2) - 4 * a * c;

	if (Discr < 0)
		return (FALSE);
//	t1 = (-b + sqrt(Discr)) / (2 * a);
//	t2 = (-b - sqrt(Discr)) / (2 * a);
//	t1 = t1 < t2 && t1 > RAY_T_MIN ? t1 : t2;
//	if (t1 > RAY_T_MIN && t1 < inter->t)
//	{
//		inter->t = t1;
//		inter->shape = shape_in_list;
//		return (1);
//	}
//	return (0);
	
	
	
	if (Discr == 0)
		t1 = -b / (2 * a);
	else
	{
		t1 = (-b + sqrt(Discr)) / (2 * a);
		t2 = (-b - sqrt(Discr)) / (2 * a);
	}
	if (!define_t(t1, t2, &(inter->t)))
	{
		inter->shape = shape_in_list;
		return (TRUE);
	}
	return (FALSE);

///////////////////////////////////////////////////
	
//	double t[2];
//	double discr;
//	double abc[3];
//	t_vector3 *tmp;
//
//	t_cylinder *cyl = ((t_cylinder*)shape_in_list->content);
//	t_ray *ray = ray_new_copy(inter->ray);
//
//
//	tmp = v3_new_minus(ray->origin, cyl->position);
//	abc[0] = dot(ray->direction, ray->direction)
//	- pow(dot(ray->direction, cyl->dir), 2);
//	abc[1] = (dot(ray->direction, tmp)
//			  - dot(ray->direction, cyl->dir)
//			  * dot(tmp, cyl->dir)) * 2;
//	abc[2] = dot(tmp, tmp) - pow(dot(tmp, cyl->dir), 2) - cyl->radius * cyl->radius;
//	discr = abc[1] * abc[1] - 4 * abc[0] * abc[2];
//	if (discr < 0)
//		return (0);
//	t[0] = (-abc[1] + sqrt(discr)) / (2 * abc[0]);
//	t[1] = (-abc[1] - sqrt(discr)) / (2 * abc[0]);
//	t[0] = t[0] < t[1] && t[0] > RAY_T_MIN ? t[0] : t[1];
//	if (t[0] > RAY_T_MIN && t[0] < inter->t)
//	{
//		inter->t = t[0];
//		inter->shape = shape_in_list;
//		return (1);
//	}
//	return (0);
	
}



t_vector3 *get_cyl_normal(t_cylinder *cyl, t_ray *ray, t_vector3 *hit_point, double t)
{
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
