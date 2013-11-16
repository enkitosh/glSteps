#ifndef GLSTEPS_H_
#define GLSTEPS_H_

#include "glPrint/linear.h"


//--------MATRIX----------\\

// Instead of defining multiple functions with
// different dimension, or passing it around
// the user has to allocate the matrix himself
// ex.
// matrix *GLPmatrix = alloc_mat(4,4, FLOAT);


// Plain print of GLMatrix
void glPrintM(float  *glMat, 
              matrix *printMat);

// Steps -----------------

//  stepM - take steps with glMatrix
// *glMat    => glMatrix provided
// *op       => operation being performed
//  enumStep => step nr in current sequence (silent mode = 0) 
// *printMat => matrix preserved for printing
void stepM(float  *glMat, 
           char   *op,
           int    enumStep,
           matrix *printMat
    );

#endif


