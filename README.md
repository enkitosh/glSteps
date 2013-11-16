glSteps
=======

helpers for openGL functionality

How to use
-----------

    #include "glSteps.h"

in your .c file

You need to specify a printing container 
for either vectors or matrixes , ex :

    matrix *GLPmatrix = alloc_mat(4,4, FLOAT) // GL Print Matrix

now you can step through transformations with stepM

    //  stepM - take steps with glMatrix
    // *glMat    => glMatrix provided
    //  *op      => operation being performed
    //  enumStep => step nr in current sequence (silent mode = 0) 
    //  printMat => matrix preserved for printing
    void stepM(float  *glMat, 
               char   *op,
               int    enumStep,
               matrix *printMat
        );


see testSteps.c

Example

    //1 ====Logging====
    stepM(matrixf, "glLoadIdentity", 1, GLPmatrix);
	
    gluPerspective(90.0, 1.25, 3.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	
    // 2 ===Logging===
    glGetFloatv(GL_MODELVIEW_MATRIX, matrixf);
    stepM(matrixf, 
                 "gluPerspective | glMatrixMode | glLoadIdentity"
                 ,2, GLPmatrix);



