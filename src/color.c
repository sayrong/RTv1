//
//  color.c
//  RTv1
//
//  Created by Babette Alvyn sharp on 02/10/2019.
//  Copyright © 2019 Babette Alvyn sharp. All rights reserved.
//

#include "rt.h"

t_color *white(void)
{
    t_color *new;
    
    if (!(new = (t_color*)malloc(sizeof(t_color))))
        error("Create white: ");
    new->r = 255;
    new->g = 255;
    new->b = 255;
    return (new);
}

int get_color(t_color *c, double light)
{
    int newRed = c->r * light;
    int newGreen = c->g * light;
    int newBlue = c->b * light;
    return (newRed << 16 | newGreen << 8 | newBlue);
}
