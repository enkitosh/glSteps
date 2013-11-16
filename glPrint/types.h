#ifndef TYPES_H_
#define TYPES_H_

#include <stdio.h>

typedef enum {
	VECTOR = 1,
	MATRIX
}ContainerType;

typedef enum {
	FLOAT,
	DOUBLE
}varType;

/*
* Basic structures: vectors, matrices
*/

typedef struct {
/*Vector struct, includes:
	size : Keeps track of vector size
	index : keeps track of indexing vector
	data : stores vector data
*/
	size_t size;
	int index;
	double *data;
}vector;


typedef struct {
	/*Dimension of matrix*/
    int m_x;
    int m_y;
	/* [[Data]] */
	double **data;
	float  **fmatrix;
	varType vType;
}matrix;



#endif
