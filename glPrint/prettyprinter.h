#ifndef PRETTYPRINTER_H_
#define PRETTYPRINTER_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "types.h"

/*Returns n * m array as string array*/
char **cnvrt_double_Array(double **x_i, int n, int m); 
char **cnvrt_float_Array(float **f_i, int n, int m);
char **cnvrt_sFloat_Array(float *f_s, int n, int m);

/*Makes space with 'symbol', that's all*/
void ms(int space, char symbol);

/*Return biggest element of vector*/
int return_biggest(int *list, size_t size);

/*Collect with of elements in Vector*/
int *getWidthV(vector *vec);

/*Return biggest element in each column of Matrix*/
int *return_biggestM(int *list, int n, int m);

/*Collect width of space per cell in Matrix*/
int **getWidthM(matrix *m);

/*One print function, detect types*/
void print_p(void *ptr, ContainerType type);

/*Extended print function for openGL types*/
void glpPrint(void *ptr, ContainerType type);

#endif
