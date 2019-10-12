/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:56:31 by cschoen           #+#    #+#             */
/*   Updated: 2019/10/12 22:11:46 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	parse_plane(t_rt *rt, char **split, int line_num)
{
	t_plane	*plane;

	if (!(plane = (t_plane*)malloc(sizeof(t_plane))))
		p_error("malloc t_plane");
	if (!str_to_v3(&plane->position, split[1]))
		parse_error("Invalid param: position vector of the plane", line_num);
	if (!str_to_v3(&plane->normal, split[2]))
		parse_error("Invalid param: normal vector of the plane", line_num);
	if (!str_to_rgb(&plane->color, split[3]))
		parse_error("Invalid param: color value of the plane", line_num);
	if (!str_to_integer(&plane->specular, split[4]))
		parse_error("Invalid param: specular value of the plane", line_num);
		//TODO RANGE FOR SPECULAR
}

static void	parse_sphere(t_rt *rt, char **split, int line_num)
{

}

static void	parse_cylinder(t_rt *rt, char **split, int line_num)
{

}

static void	parse_cone(t_rt *rt, char **split, int line_num)
{

}

void		parse_shape(t_rt *rt, char **split, int line_num)
{
	if (!split[1] || !split[2] || !split[3] || !split[4])
		parse_error("Incorrect count of the params for shape", line_num);
	if (ft_strequ(split[0], "plane") || ft_strequ(split[0], "sphere"))
		if (split[5])
			parse_error("Incorrect count of the params for shape", line_num);
	if (ft_strequ(split[0], "cylinder") || ft_strequ(split[0], "cone"))
		if (!split[5] || split[6])
			parse_error("Incorrect count of the params for shape", line_num);
	if (ft_strequ(split[0], "plane"))
		parse_plane(rt, split, line_num);
	else if (ft_strequ(split[0], "sphere"))
		parse_sphere(rt, split, line_num);
	else if (ft_strequ(split[0], "cylinder"))
		parse_cylinder(rt, split, line_num);
	else if (ft_strequ(split[0], "cone"))
		parse_cone(rt, split, line_num);
}
