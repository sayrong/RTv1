/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:15:02 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/29 14:19:21 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# define RAY_T_MIN 0.0001f
# define RAY_T_MAX 1.0e30f

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
	t_shape		*shape;
	t_ray		*ray;
	double		t;
}				t_intersection;

t_ray			*ray(void);
t_ray			*ray_copy(t_ray *ray);
t_ray			*ray_fill(t_vector3 *origin, t_vector3* direction, double t_max);
t_vector3		*calculate(t_ray *ray, double t);

#endif
