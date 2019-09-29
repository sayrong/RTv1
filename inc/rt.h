/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:15:02 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/29 16:14:53 by cschoen          ###   ########.fr       */
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
	t_shape		*shape;
	t_ray		*ray;
	double		t;
}				t_intersection;

t_ray			*r_new(void);
t_ray			*r_new3(t_vector3 *origin, t_vector3 *direction, double t_max);
t_ray			*r_new_copy(t_ray *ray);
t_ray			*r_copy(t_ray *ray1, t_ray *ray2);
t_vector3		*calculate(t_ray *ray, double t);

#endif
