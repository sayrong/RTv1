/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:15:02 by cschoen           #+#    #+#             */
/*   Updated: 2019/10/12 16:28:31 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# define RAY_T_MIN 1e-4
# define RAY_T_MAX 1e30

# define TRUE 1
# define FALSE 0
# define WIDTH 400
# define HEIGHT 400
# define PI 3.14159265359

# include <mlx.h>
# include "../libvec/vector.h"
# include "../libft/libft.h"

# include "macoskeys.h"
/*
# include "linuxkeys.h"
*/

typedef struct			s_color
{
	int					r;
	int					g;
	int					b;
}						t_color;

typedef enum			e_light_type
{
	ambient,
	point,
	directional
}						t_light_type;

typedef struct			s_light
{
	t_light_type		type;
	double				intensity;
	t_vector3			*position;
}						t_light;

typedef enum			e_shape_type
{
	PLANE,
	SPHERE,
	CONE,
	CYLINDER,
	CNT_OF_TYPES
}						t_shape_type;

typedef struct			s_list_shape
{
	void				*content;
	t_shape_type		shape;
	struct s_list_shape	*next;
}						t_list_shape;

typedef struct			s_list_light
{
	t_light				*light;
	t_light_type		type;
	struct s_list_light	*next;
}						t_list_light;

typedef struct			s_ray
{
	t_vector3			*origin;
	t_vector3			*direction;
	double				t_max;
}						t_ray;

typedef struct			s_plane
{
	t_vector3			*position;
	t_vector3			*normal;
	t_shape_type		shape;
	t_color				*color;
	int					specular;

}						t_plane;

typedef struct			s_sphere
{
	t_vector3			*center;
	double				radius;
	t_shape_type		shape;
	t_color				*color;
	int					specular;
}						t_sphere;

typedef struct			s_cone
{
	t_vector3			*position;
	t_vector3			*dir;
	double				angle;
	t_color				*color;
	t_shape_type		shape;
	int 				specular;
}						t_cone;

typedef struct			s_cylinder
{
	t_vector3			*position;
	t_vector3			*dir;
	double				radius;
	t_color				*color;
	t_shape_type		shape;
	int					specular;
}						t_cylinder;

typedef struct			s_intersection
{
	t_ray				*ray;
	double				t;
	t_list_shape		*shape;
}						t_inter;

typedef struct			s_camera
{
	double				h;
	double				w;
	t_vector3			*origin;
	t_vector3			*forward;
	t_vector3			*up;
	t_vector3			*right;
}						t_cam;

typedef struct			s_win
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					width;
	int					height;
}						t_win;

typedef struct			s_img
{
	void				*img_ptr;
	char				*data;
	int					bpp;
	int					size_line;
	int					endian;
	int					width;
	int					height;
}						t_img;

typedef struct			s_rt
{
	t_point2			size;
	t_win				*win;
	t_img				*img;
	t_cam				*cam;
	t_list_shape		*shapes;
	t_list_light		*lights;

}						t_rt;


double					compute_light(t_inter *inter, t_list_shape *scene,
										t_list_light *lights);

t_vector3				*get_normal(t_inter *inter);
int						get_specular(t_inter *inter);
t_vector3				*get_sphere_normal(t_sphere *sphere,
										t_vector3 *hit_point);
t_vector3				*get_plane_normal(t_plane *plane, t_ray *ray);
t_vector3				*get_cone_normal(t_cone *cone, t_ray *ray,
										t_vector3 *hit_point, double t);
t_vector3				*get_cyl_normal(t_cylinder *cyl, t_ray *ray,
										t_vector3 *hit_point, double t);

_Bool					cone_intersect(t_inter *inter,
										t_list_shape *shape_in_list);

_Bool					cylinder_intersect(t_inter *inter,
										t_list_shape *shape_in_list);

double					degrees_to_rad(double angleInDegrees);
int						define_t(double t1, double t2, t_inter *inter,
										t_list_shape *shape_in_list);

t_list_shape			*new_shape_list(void *content, t_shape_type type);
void					add_new_shape(t_list_shape *list, void *content,
										t_shape_type type);

t_list_light			*new_light_list(t_light *light, t_light_type type);
void					add_new_light(t_list_light *list, t_light *light,
										t_light_type type);

t_color					*white(void);
int						get_color(t_color *c, double light);
t_color					*get_color_from_list(t_list_shape *list);

double					sqr(double num);

void					put_error(char *str);

void					ray_del(t_ray **ray);
void					plane_del(t_plane **plane);
void					sphere_del(t_sphere **sphere);
void					cone_del(t_cone **cone);
void					cylinder_del(t_cylinder **cylinder);
void					inter_del(t_inter **inter);

t_ray					*ray_new(void);
t_ray					*ray_new3(t_vector3 *origin, t_vector3 *dir,
								double t_max);
t_ray					*ray_new_copy(t_ray *ray);
t_ray					*ray_copy(t_ray *ray1, t_ray *ray2);
t_vector3				*calculate(t_ray *ray, double t);

t_plane					*plane_new(t_vector3 *position, t_vector3 *normal);
t_plane					*plane_new_dp(t_vector3 *position, t_vector3 *normal);
t_plane					*plane_new_copy(t_plane *plane);
t_plane					*plane_copy(t_plane *plane1, t_plane *plane2);
_Bool					plane_intersect(t_inter *inter,
										t_list_shape *shape_in_list);

t_sphere				*sphere_new(t_vector3 *center, double radius);
t_sphere				*sphere_new_dp(t_vector3 *center, double radius);
t_sphere				*sphere_new_copy(t_sphere *sphere);
t_sphere				*sphere_copy(t_sphere *sphere1, t_sphere *sphere2);
_Bool					sphere_intersect(t_inter *inter,
										t_list_shape *shape_in_list);

_Bool					shape_intersect(t_inter *inter, t_list_shape *shape);
_Bool					shapeset_intersect(t_inter *inter,
										t_list_shape *shape_list);

t_inter					*inter_new(void);
t_inter					*inter_new_copy(t_inter *inter);
t_inter					*inter_new_ray(t_ray *ray);
t_vector3				*position(t_inter *inter);
_Bool					intersected(t_inter *inter);

t_cam					*cam_init_null(t_cam *cam);
t_cam					*camera_new(t_vector3 *origin, t_vector3 *target,
									t_vector3 *upguide, t_vector2 *fov_ratio);
t_cam					*camera_new_dp(t_vector3 *origin, t_vector3 *target,
									t_rt *rt);
t_cam					*recalc_cam_dp(t_cam *cam, int key, t_vector3 *upguide,
									t_vector2 *fov_ratio);
t_ray					*make_ray(t_vector2 *point, t_cam *cam);

t_win					*win_new(int width, int height);
t_img					*img_new(int width, int height, t_win *win);
int						*get_pixel(int x, int y, t_img *img);

void					ray_trace(t_rt *rt, t_point2 size);

void					initial_setup(t_rt *rt);
void					scene1(t_rt *rt);
void					scene2(t_rt *rt);
void					scene3(t_rt *rt);
void					scene4(t_rt *rt);

int						red_x_button(void *param);
int						deal_key(int key, void *param);

#endif
