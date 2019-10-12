//
//  some_vector.c
//  RTV2
//
//  Created by Babette Alvyn sharp on 12/10/2019.
//  Copyright © 2019 Babette Alvyn sharp. All rights reserved.
//

#include "libvec.h"

t_point2	p2_set(int x, int y)
{
	t_point2	new_p2;
	
	new_p2.x = x;
	new_p2.y = y;
	return (new_p2);
}

t_vec2	v2_set(double u, double v)
{
	t_vec2	new_v2;
	
	new_v2.u = u;
	new_v2.v = v;
	return (new_v2);
}

double			length_sq(t_vec3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}
