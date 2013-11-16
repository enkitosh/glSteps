#ifndef LINEAR_H_
#define LINEAR_H_

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "prettyprinter.h"
#include "types.h"
	    

/********************************
*                               *
*       Vector Operations       *
*                               *
*********************************/

/*Basics*/
vector *alloc_vec(size_t n);
void push_back(vector *vec, double x);
void vector_clear(vector *vec);

/*Sicne these operations are very common I will include*/
vector *init2Dv(double x, double y);

vector *zeroVector(size_t size);
vector *baseVector(vector *vec_1, vector *vec_2);


/*********************************
*                                *
*       Matrix Operations        *
*                                *
**********************************/

/*Setup*/

matrix *alloc_mat(size_t n, size_t m, varType v);
int initialize(matrix *mat, double element);
void setValueCoord(matrix *mat, int x, int y, double v);
void setValueCoordF(matrix *mat, int x, int y, float v);
void setMatrixF(matrix *mat, float *arr);
double getValueCoord(matrix *mat, int x, int y);



/*Free object*/
void free_object(void *ptr, ContainerType type);

#endif
