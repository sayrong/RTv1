//
//  light.c
//  RTV2
//
//  Created by Babette Alvyn sharp on 04/10/2019.
//  Copyright © 2019 Babette Alvyn sharp. All rights reserved.
//

#include "rt.h"

double compute_specular(t_vector3 *normal_to_intersect, t_vector3 *light_vector, t_vector3 *to_camera_vector, int object_specular)
{
	t_vector3 *return_light_vector;
	t_vector3 *tmp1;
	double tmp2;
	t_vector3 *tmp3;
	double res;
	double percent;

	percent = 0;
	tmp1 = v3_new_mult_by_num(normal_to_intersect, 2);
	tmp2 = dot(normal_to_intersect, light_vector);
	tmp3 = v3_new_mult_by_num(tmp1, tmp2);
	return_light_vector = v3_new_minus(tmp3, light_vector);
	res = dot(return_light_vector, to_camera_vector);
	if (res > 0)
	{
		percent = pow(res/(length(return_light_vector) * length(to_camera_vector)), object_specular);
	}
	v3_del(&tmp1);
	v3_del(&tmp3);
	v3_del(&return_light_vector);
	return (percent);
}


double compute_light(t_vector3 *intersection_point, t_vector3 *normal_to_intersect, t_list_light *lights, t_vector3 *to_camera_vector, int specular)
{
	double res;
	t_list_light *tmp;
	t_vector3 *light_vector;
	double percent;

	res = 0;
	tmp = lights;

	while (tmp != NULL)
	{
		if (tmp->type == ambient)
			res += tmp->light->intensity;
		else {
			if (tmp->type == point)
				light_vector = v3_new_minus(tmp->light->position, intersection_point);
			else
				light_vector = tmp->light->position;
			percent = dot(normal_to_intersect, light_vector);
			if (percent > 0)
			{
				res += ((tmp->light->intensity * percent) / (length(normal_to_intersect) * length(light_vector)));

			}
			if (specular > 0)
			{
				percent = compute_specular(normal_to_intersect, light_vector, to_camera_vector, specular);
				res += (tmp->light->intensity * percent);
			}

		}
		tmp = tmp->next;
	}
	if (res > 1)
		res = 1;
	return (res);
}
