#include "glSteps.h"

void glPrint(float *glMat, matrix *printMat) {

    //Copy glmatrix to printable matrix
    setMatrixF(printMat, glMat);

    //Print matrix
    print_p(printMat, MATRIX);
}

void stepM(float *glMat, char *op, int enumStep, matrix *printMat) {

    setMatrixF(printMat, glMat);

    // Check if steps should be enumerated
    if(enumStep > 0)
        printf("%i : ", enumStep);

    // Log operation
    printf("%s\n", op);

   // Finally print matrix
    print_p(printMat, MATRIX);
}
