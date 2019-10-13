//
//  color.c
//  RTV2
//
//  Created by Babette Alvyn sharp on 04/10/2019.
//  Copyright © 2019 Babette Alvyn sharp. All rights reserved.
//

#include "rt.h"

void white(t_color* new)
{
	new->r = 255;
	new->g = 255;
	new->b = 255;
}

int get_color(t_color *c, double light)
{
	int newRed = c->r * light;
	int newGreen = c->g * light;
	int newBlue = c->b * light;
	return (newRed << 16 | newGreen << 8 | newBlue);
}

t_color *get_color_from_list(t_list_shape *list)
{
	if (list->shape == SPHERE)
		return &(((t_sphere*)list->content)->color);
	else if (list->shape == PLANE)
		return &(((t_plane*)list->content)->color);
	else if (list->shape == CONE)
		return &(((t_cone*)list->content)->color);
	else if (list->shape == CYLINDER)
		return &(((t_cylinder*)list->content)->color);
	else
		return (NULL);
}
