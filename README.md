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

Example:

    // 2 ===Logging===
    glGetFloatv(GL_MODELVIEW_MATRIX, matrixf);
    stepM(matrixf, 
                 "gluPerspective | glMatrixMode | glLoadIdentity"
                 ,2, GLPmatrix);

    gluLookAt(8.0, 5.0, 7.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    //3 ===Logging====
    glGetFloatv(GL_MODELVIEW_MATRIX, matrixf);
    stepM(matrixf, "gluLookAt", 3, GLPmatrix);


Output:

    2 : gluPerspective | glMatrixMode | glLoadIdentity

    [ 1  0  0  0 ]
    [ 0  1  0  0 ]
    [ 0  0  1  0 ]
    [ 0  0  0  1 ]

    3 : gluLookAt

    [  0.658505    -0.320318  0.681005  0 ]
    [         0     0.904898  0.425628  0 ]
    [ -0.752577    -0.280278   0.59588  0 ]
    [         0  2.38419e-07  -11.7473  1 ]


At the end of the day you free glSteps objects with free_object

	free_object(GLPmatrix, MATRIX);


