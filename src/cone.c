//
//  cone.c
//  RTV2
//
//  Created by Babette Alvyn sharp on 04/10/2019.
//  Copyright © 2019 Babette Alvyn sharp. All rights reserved.
//

#include "rt.h"


////WRONG!!
_Bool	cone_intersect(t_inter *inter, t_list_shape *shape_in_list)
{
	double t1 = 0;
	double t2 = 0;
	
	t_cone *cone = (t_cone *)shape_in_list->content;
	t_ray	*local_ray = ray_new_copy(inter->ray);
	
	t_vector3 *O = local_ray->origin;
	t_vector3 *D = local_ray->direction;
	t_vector3 *V = cone->dir;
	t_vector3 *C = cone->position;
	
	double a = pow(dot(D, V),2) - pow(cos(cone->angle), 2);
	
	t_vector3 *CO = v3_new_minus(O, C);
	double tmp1 = dot(D, V);
	double tmp2 = dot(CO, V);
	double tmp3 = dot(D, CO) * pow(cos(cone->angle), 2);
	double tmp4 = tmp1 * tmp2;
	double tmp5 = tmp4 - tmp3;
	double b = 2 * tmp5;
	
	double tmp6 = pow(dot(CO, V), 2);
	double tmp7 = dot(CO, CO) * pow(cos(cone->angle), 2);
	double c = tmp6 - tmp7;
	
	double discr = pow(b, 2) - 4 * a * c;
	
	if (discr < 0)
		return FALSE;
	else if (discr == 0)
		t1 = -b / (2 * a);
	else
	{
		t1 = (-b - sqr(discr)) / (2 * a);
		t2 = (-b + sqr(discr)) / (2 * a);
	}
	//
	if (t1 > RAY_T_MIN && t1 < inter->t)
	{
		inter->t = t1;
		inter->shape = shape_in_list;
	}
	else if (t2 > RAY_T_MIN && t2 < inter->t)
		inter->t = t2;
	else
		return (FALSE);
	inter->shape = shape_in_list;
	return (TRUE);
}
