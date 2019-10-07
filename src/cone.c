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
	if (t1 > RAY_T_MIN && t1 <= t2)
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

_Bool	cone_intersect(t_inter *inter, t_list_shape *shape_in_list)
{
	//  a   = D|D - (1+k*k)*(D|V)^2
	//  b/2 = D|X - (1+k*k)*(D|V)*(X|V)
	//  c   = X|X - (1+k*k)*(X|V)^2
	//	X equals O-C.
	
//	double		abc[3];
//	double		t[2];
//	t_vector3	*x;
//	t_cone		*cone;
//	double		k_and_discr[2];
//
//	cone = ((t_cone*)shape_in_list->content);
//	x = v3_new_minus(inter->ray->origin, cone->position);
//	k_and_discr[0] = 1 + tan(degrees_to_rad(cone->angle)) * tan(degrees_to_rad(cone->angle));
//	abc[0] = length_sq(inter->ray->direction) - k_and_discr[0] * pow(dot(inter->ray->direction, cone->dir),2);
//	abc[1] = 2 * (dot(inter->ray->direction, x) - k_and_discr[0] * dot(inter->ray->direction, cone->dir) * dot(x, cone->dir));
//	abc[2] = length_sq(x) - k_and_discr[0] * pow(dot(x, cone->dir),2);
//	k_and_discr[1] = abc[1] * abc[1] - 4 * abc[0] * abc[2];
//	free(x);
//	if (k_and_discr[1] < 0)
//		return (FALSE);
//	t[0] = (-abc[1] + sqrt(k_and_discr[1])) / 2 * abc[0];
//	t[1] = (-abc[1] - sqrt(k_and_discr[1])) / 2 * abc[0];
//	if (!define_t(t[0], t[1], &(inter->t)))
//	{
//		inter->shape = shape_in_list;
//		return (TRUE);
//	}
//	return (FALSE);
	
	
	
	//GOT DIFFERENCE. DONT KNOW WHY
	
	
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

	ray_del(&local_ray);
	v3_del(&x);
	if (Discr < 0)
		return (FALSE);
	if (Discr == 0)
		t1 = -b / (2 * a);
	else
	{
		t1 = (-b + sqrt(Discr)) / (2 * a);
		t2 = (-b - sqrt(Discr)) / (2 * a);
	}
	//	if (!define_t(t1, t2, &(inter->t)))
	//	{
	//
	//		inter->shape = shape_in_list;
	//		return (TRUE);
	//	}
	t1 = t1 < t2 && t1 > RAY_T_MIN ? t1 : t2;
	if (t1 > RAY_T_MIN && t1 < inter->t)
	{
		//		t_vector3	*tmp = v3_new_mult_by_num(local_ray->direction, t1);
		//		t_vector3	*hit_point = v3_new_plus(local_ray->origin, tmp);
		
		//remove up
		//		if (cone->position->y < hit_point->y)
		//		{
		//			return (FALSE);
		//		}
		inter->shape = shape_in_list;
		inter->t = t1;
		return (TRUE);
	}
	
	return (FALSE);

	 

}


t_vector3 *get_cone_normal(t_cone *cone, t_ray *ray, t_vector3 *hit_point, double t)
{
	double		k;
	double		m;
	t_vector3	*tmp[8];
	t_vector3	*normal;
	
	//N = nrm( P-C-V*m - V*m*k*k )
	k = tan(degrees_to_rad(cone->angle));
	tmp[0] = v3_new_minus(ray->origin, cone->position);
	m = dot(ray->direction, cone->dir) * t + dot(tmp[0], cone->dir);
	tmp[1] = v3_new_minus(hit_point, cone->position);
	tmp[2] = v3_new_mult_by_num(cone->dir, m);
	tmp[3] = v3_new_minus(tmp[1], tmp[2]);
	tmp[4] = v3_new_mult_by_num(cone->dir, m);
	tmp[5] = v3_new_mult_by_num(tmp[4], k);
	tmp[6] = v3_new_mult_by_num(tmp[5], k);
	tmp[7] = v3_new_minus(tmp[3], tmp[6]);
	normal = v3_new_div_by_num(tmp[7], length(tmp[7]));
	free_temp_v(tmp, 8);
	return (normal);
}







