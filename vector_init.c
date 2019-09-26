//
//  vector_init.c
//  rayTracer
//
//  Created by Dmitriy on 26/09/2019.
//  Copyright © 2019 Dmitriy. All rights reserved.
//

#include "vector.h"


t_vector *copy_vector(t_vector *vect)
{
    t_vector *new;
    if (!(new = (t_vector*)malloc(sizeof(t_vector))))
        return (NULL);
    new->x = vect->x;
    new->y = vect->y;
    new->z = vect->z;
    return (new);
}

t_vector *vector(void)
{
    t_vector *new;
    if (!(new = (t_vector*)malloc(sizeof(t_vector))))
        return (NULL);
    new->x = 0;
    new->y = 1;
    new->z = 0;
    return (new);
}

t_vector *new_vector(double x, double y, double z)
{
    t_vector *new;
    if (!(new = (t_vector*)malloc(sizeof(t_vector))))
        return (NULL);
    new->x = x;
    new->y = y;
    new->z = z;
    return (new);
}

t_vector *new_vector_one(double f)
{
    t_vector *new;
    if (!(new = (t_vector*)malloc(sizeof(t_vector))))
        return (NULL);
    new->x = f;
    new->y = f;
    new->z = f;
    return (new);
}
