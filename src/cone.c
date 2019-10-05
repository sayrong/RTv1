//
//  cone.c
//  RTV2
//
//  Created by Babette Alvyn sharp on 04/10/2019.
//  Copyright © 2019 Babette Alvyn sharp. All rights reserved.
//

#include "rt.h"


int define_t(double t1, double t2, double *t)
{
	double tmp = -1;
	if (t1 > RAY_T_MIN && t1 < t2)
		tmp = t1;
	if (t2 > RAY_T_MIN && t2 < t1)
		tmp = t2;
	if (tmp == -1)
		return (1);
	if (tmp < *t)
	{
		*t = tmp;
		return (0);
	}
	return (1);
}


double degrees_to_rad(double angleInDegrees)
{
	return ((angleInDegrees * M_PI / 180.0) / 2);
}

////WRONG!!
_Bool	cone_intersect(t_inter *inter, t_list_shape *shape_in_list)
{
	double t1 = 0;
	double t2 = 0;

	t_cone *cone = ((t_cone*)shape_in_list->content);
	t_ray *local_ray = ray_new_copy(inter->ray);
	
	t_vector3 *x = v3_new_minus(local_ray->origin, cone->position);

	double tmp1 = length_sq(local_ray->direction);
	double angleRad = degrees_to_rad(cone->angle);
	double tmp2 = 1 + tan(angleRad) * tan(angleRad);
	double tmp3 = pow(dot(local_ray->direction, cone->dir),2);
	double a = tmp1 - tmp2 * tmp3;


	double tmp4 = dot(local_ray->direction, x);
	double tmp5 = dot(local_ray->direction, cone->dir);
	double tmp6 = dot(x, cone->dir);
	double b = 2 * (tmp4 - tmp2 * tmp5 * tmp6);

	double tmp7 = length_sq(x);
	double tmp8 = pow(dot(x, cone->dir),2);
	double c = tmp7 - tmp2 * tmp8;

	double Discr = pow(b, 2) - 4 * a * c;

	if (Discr < 0)
		return (FALSE);
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
	
	
//	double abc[3];
//	double t[2];
//	t_vector3 *x;
//	double discr_k[2];
//
//	discr_k[1] = 1 + pow(tan(cone->angle), 2);
//	x = v3_new_minus(local_ray->origin, cone->position);
//	abc[0] = dot(local_ray->direction, local_ray->direction) - discr_k[1] * pow(dot(local_ray->direction, cone->dir), 2);
//	abc[1] = 2 * (dot(local_ray->direction, x) - discr_k[1] * dot(local_ray->direction, cone->dir) * dot(x, cone->dir));
//	abc[2] = dot(x, x) - discr_k[1] * pow(dot(x, cone->dir), 2);
//	discr_k[0] = abc[1] * abc[1] - 4 * abc[0] * abc[2];
//	if (discr_k[0] < 0)
//		return (0);
//	t[0] = (-abc[1] + sqrt(discr_k[0])) / (2 * abc[0]);
//	t[1] = (-abc[1] - sqrt(discr_k[0])) / (2 * abc[0]);
//	t[0] = t[0] < t[1] && t[0] > RAY_T_MIN ? t[0] : t[1];
//	if (t[0] > RAY_T_MIN && t[0] < inter->t)
//	{
//		inter->t = t[0];
//		inter->shape = shape_in_list;
//		return (1);
//	}
//	return (0);
	
	
}
