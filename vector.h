//
//  vector.h
//  rayTracer
//
//  Created by Dmitriy on 26/09/2019.
//  Copyright © 2019 Dmitriy. All rights reserved.
//

#ifndef vector_h
#define vector_h

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct  s_vector
{
    double x;
    double y;
    double z;
}               t_vector;


t_vector *copy_vector(t_vector *vect);
t_vector *vector(void);
t_vector *new_vector(double x, double y, double z);
t_vector *new_vector_one(double f);

double sqr(double num);
double length(t_vector *vect);
double normalize(t_vector **vect);
t_vector *normalize_copy(t_vector *vect);
t_vector *plus_vectors(t_vector *vect1, t_vector *vect2);
t_vector *minus_vectors(t_vector *vect1, t_vector *vect2);
t_vector *multiplu_vectors(t_vector *vect1, t_vector *vect2);
t_vector *devide_vectors(t_vector *vect1, t_vector *vect2);
t_vector *multiply_vectors_const(t_vector *vect1, double a);
t_vector *devide_vectors_const(t_vector *vect1, double a);

void plus_vector(t_vector **vect1, t_vector *vect2);
void minus_vector(t_vector **vect1, t_vector *vect2);
void multiply_vector_const(t_vector **vect1, double a);
void devide_vector_const(t_vector **vect1, double a);


double dot(t_vector *vect1, t_vector *vect2);


#endif /* vector_h */
