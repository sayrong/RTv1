//
//  math_vectors.c
//  rayTracer
//
//  Created by Dmitriy on 26/09/2019.
//  Copyright © 2019 Dmitriy. All rights reserved.
//

#include "vector.h"

double sqr(double num)
{
    return (pow(num, 2));
}

double length2(t_vector *vect)
{
    double res;
    
    res = sqr(vect->x) + sqr(vect->y) + sqr(vect->z);
    return (res);
}

double length(t_vector *vect)
{
    return (sqrt(length2(vect)));
}

double normalize(t_vector **vect)
{
    double l = length(*vect);
    (*vect)->x /= l;
    (*vect)->y /= l;
    (*vect)->z /= l;
    return (l);
}

t_vector *normalize_copy(t_vector *vect)
{
    t_vector *new;
    
    new = copy_vector(vect);
    normalize(&new);
    return (new);
}

t_vector *plus_vectors(t_vector *vect1, t_vector *vect2)
{
    t_vector *new;
    
    if (!(new = vector()))
        return (NULL);
    new->x = vect1->x + vect2->x;
    new->y = vect1->y + vect2->y;
    new->z = vect1->z + vect2->z;
    return (new);
}

void plus_vector(t_vector **vect1, t_vector *vect2)
{
    (*vect1)->x += vect2->x;
    (*vect1)->y += vect2->y;
    (*vect1)->z += vect2->z;
}

t_vector * minus_vectors(t_vector *vect1, t_vector *vect2)
{
    t_vector *new;
    
    if (!(new = vector()))
        return (NULL);
    new->x = vect1->x - vect2->x;
    new->y = vect1->y - vect2->y;
    new->z = vect1->z - vect2->z;
    return (new);
}

void minus_vector(t_vector **vect1, t_vector *vect2)
{
    (*vect1)->x -= vect2->x;
    (*vect1)->y -= vect2->y;
    (*vect1)->z -= vect2->z;
}

t_vector *multiplu_vectors(t_vector *vect1, t_vector *vect2)
{
    t_vector *new;
    
    if (!(new = vector()))
        return (NULL);
    new->x = vect1->x * vect2->x;
    new->y = vect1->y * vect2->y;
    new->z = vect1->z * vect2->z;
    return (new);
}

t_vector *devide_vectors(t_vector *vect1, t_vector *vect2)
{
    t_vector *new;
    
    if (!(new = vector()))
        return (NULL);
    new->x = vect1->x / vect2->x;
    new->y = vect1->y / vect2->y;
    new->z = vect1->z / vect2->z;
    return (new);
}

t_vector *multiply_vectors_const(t_vector *vect1, double a)
{
    t_vector *new;
    
    if (!(new = vector()))
        return (NULL);
    new->x = vect1->x * a;
    new->y = vect1->y * a;
    new->z = vect1->z * a;
    return (new);
}

void multiply_vector_const(t_vector **vect1, double a)
{
    (*vect1)->x *= a;
    (*vect1)->y *= a;
    (*vect1)->z *= a;
}

t_vector *devide_vectors_const(t_vector *vect1, double a)
{
    t_vector *new;
    
    if (!(new = vector()))
        return (NULL);
    new->x = vect1->x / a;
    new->y = vect1->y / a;
    new->z = vect1->z / a;
    return (new);
}

void devide_vector_const(t_vector **vect1, double a)
{
    (*vect1)->x /= a;
    (*vect1)->y /= a;
    (*vect1)->z /= a;
}


double dot(t_vector *vect1, t_vector *vect2)
{
    double res;
    
    res = vect1->x * vect2->x + vect1->y * vect2->y + vect1->z * vect2->z;
    return (res);
}

t_vector *cross(t_vector *vect1, t_vector *vect2)
{
    t_vector *new;
    
    if (!(new = vector()))
        return (NULL);
    new->x = vect1->y * vect2->z - vect1->z * vect2->y;
    new->y = vect1->z * vect2->x - vect1->x * vect2->z;
    new->z = vect1->x * vect2->y - vect1->y * vect2->x;
    return (new);
}
