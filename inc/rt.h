/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:15:02 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/30 00:46:23 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# define RAY_T_MIN 1e-4
# define RAY_T_MAX 1e30

# define TRUE 1
# define FALSE 0

# include "../libvec/vector.h"
# include "../libft/libft.h"

typedef enum	e_shape_type
{
	PLANE,
	SPHERE,
	CONE,
	CYLINDER,
	CNT_OF_TYPES
}				t_type;

typedef struct	s_ray
{
	t_vector3	*origin;
	t_vector3	*direction;
	double		t_max;
}				t_ray;

typedef struct	s_plane
{
	t_vector3	*position;
	t_vector3	*normal;
}				t_plane;

typedef struct	s_sphere
{
	t_vector3	*center;
	double		radius;
}				t_sphere;

typedef struct	s_cone
{

}				t_cone;

typedef struct	s_cylinder
{

}				t_cylinder;

typedef struct	s_shape
{
	t_type		type;
	t_plane		*plane;
	t_sphere	*sphere;
	t_cone		*cone;
	t_cylinder	*cylinder;
}				t_shape;

typedef struct	s_intersection
{
	t_ray		*ray;
	double		t;
	t_shape		*shape;
}				t_inter;

void			ray_del(t_ray **ray);
void			plane_del(t_plane **plane);
void			sphere_del(t_sphere **sphere);
void			cone_del(t_cone **cone);
void			cylinder_del(t_cylinder **cylinder);
void			shape_del(t_shape **shape);
void			inter_del(t_inter **inter);

t_ray			*ray_new(void);
t_ray			*ray_new3(t_vector3 *origin, t_vector3 *dir, double t_max);
t_ray			*ray_new_copy(t_ray *ray);
t_ray			*ray_copy(t_ray *ray1, t_ray *ray2);
t_vector3		*calculate(t_ray *ray, double t);

t_plane			*plane_new(t_vector3 *position, t_vector3 *normal);
t_plane			*plane_new_copy(t_plane *plane);
t_plane			*plane_copy(t_plane *plane1, t_plane *plane2);
_Bool			plane_intersect(t_inter *inter, t_shape *shape);
_Bool			plane_does_intersect(t_ray *ray, t_shape *shape);

t_sphere		*sphere_new(t_vector3 *center, double radius);
t_sphere		*sphere_new_copy(t_sphere *sphere);
t_sphere		*sphere_copy(t_sphere *sphere1, t_sphere *sphere2);
_Bool			sphere_intersect(t_inter *inter, t_shape *shape);
_Bool			sphere_does_intersect(t_ray *ray, t_shape *shape);

t_shape			*shape_init_null(t_shape *shape);
t_shape			*shape_new(void);
t_shape			*shape_new_copy(t_shape *shape);
t_shape			*shape_copy(t_shape *shape1, t_shape *shape2);
_Bool			shape_intersect(t_inter *inter, t_shape *shape);
_Bool			shape_does_intersect(t_ray *ray, t_shape *shape);

t_inter			*inter_new(void);
t_inter			*inter_new_copy(t_inter *inter);
t_inter			*inter_copy(t_inter *inter1, t_inter *inter2);
t_inter			*inter_new_ray(t_ray *ray);
t_vector3		*position(t_inter *inter);
_Bool			intersected(t_inter *inter);

#endif
