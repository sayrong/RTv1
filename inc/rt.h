/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:15:02 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/29 17:57:24 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# define RAY_T_MIN 1e-4
# define RAY_T_MAX 1e30

# include "../libvec/vector.h"
# include "../libft/libft.h"

typedef struct	s_ray
{
	t_vector3	*origin;
	t_vector3	*direction;
	double		t_max;
}				t_ray;

typedef struct	s_shape
{

}				t_shape;

typedef struct	s_intersection
{
	t_ray		*ray;
	double		t;
	t_shape		*shape;
}				t_inter;

void			ray_null(t_ray **ray);
void			ray_del(t_ray **ray);

t_ray			*ray_new(void);
t_ray			*ray_new3(t_vector3 *origin, t_vector3 *dir, double t_max);
t_ray			*ray_new_copy(t_ray *ray);
t_ray			*ray_copy(t_ray *ray1, t_ray *ray2);
t_vector3		*calculate(t_ray *ray, double t);

t_inter			*inter_new(void);
t_inter			*inter_new_copy(t_inter *inter);
t_inter			*inter_copy(t_inter *inter1, t_inter *inter2);
t_inter			*inter_new_ray(t_ray *ray);
t_vector3		*position(t_inter *inter);
_Bool			intersected(t_inter *inter);

#endif
