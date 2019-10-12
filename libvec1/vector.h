/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 19:31:47 by cschoen           #+#    #+#             */
/*   Updated: 2019/10/06 21:51:14 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_vector3
{
	double		x;
	double		y;
	double		z;
}				t_vector3;

typedef struct	s_vector2
{
	double		u;
	double		v;
}				t_vector2;

typedef struct	s_point2
{
	int			x;
	int			y;
}				t_point2;

void			error(char *str);
void			null_error(void);
void			v3_del(t_vector3 **vec);
void			free_temp_v(t_vector3 **ar, int size);
void			v2_del(t_vector2 **vec);


t_point2		p2_set(int x, int y);
t_vector2		v2_set(double u, double v);

t_vector3		*v3_new(void);
t_vector3		*v3_new1(double f);
t_vector3		*v3_new3(double x, double y, double z);
t_vector3		*v3_new_copy(t_vector3 *v);

t_vector3		*v3_copy(t_vector3 *v1, t_vector3 *v2);
t_vector3		*v3_plus(t_vector3 *v1, t_vector3 *v2);
t_vector3		*v3_minus(t_vector3 *v1, t_vector3 *v2);
t_vector3		*v3_mult(t_vector3 *v, double a);
t_vector3		*v3_div(t_vector3 *v, double a);

t_vector3		*v3_new_plus(t_vector3 *v1, t_vector3 *v2);
t_vector3		*v3_new_minus(t_vector3 *v1, t_vector3 *v2);
t_vector3		*v3_new_mult(t_vector3 *v1, t_vector3 *v2);
t_vector3		*v3_new_div(t_vector3 *v1, t_vector3 *v2);
t_vector3		*v3_new_mult_by_num(t_vector3 *v, double a);
t_vector3		*v3_new_div_by_num(t_vector3 *v, double a);
t_vector3		*v3_new_div_on_num(double a, t_vector3 *v);
t_vector3		*new_cross(t_vector3 *v1, t_vector3 *v2);
t_vector3		*new_normalize(t_vector3 *v);

double			length_sq(t_vector3 *v);
double			length(t_vector3 *v);
double			normalize(t_vector3 *v);
double			dot(t_vector3 *v1, t_vector3 *v2);

t_vector2		*v2_new(void);
t_vector2		*v2_new1(double f);
t_vector2		*v2_new2(double u, double v);
t_vector2		*v2_new_copy(t_vector2 *vec);
t_vector2		*v2_copy(t_vector2 *vec1, t_vector2 *vec2);

#endif
