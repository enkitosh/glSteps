#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "glSteps.h"

void display(void)
{
    GLfloat matrixf[16];
    //Print matrix
    matrix *GLPmatrix = alloc_mat(4,4, FLOAT);
	
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glGetFloatv(GL_PROJECTION_MATRIX, matrixf);
	

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

    gluLookAt(8.0, 5.0, 7.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    //3 ===Logging====
    glGetFloatv(GL_MODELVIEW_MATRIX, matrixf);
    stepM(matrixf, "gluLookAt", 3, GLPmatrix);

    glTranslatef(5.0, 7.0, 12.0);

    //4 ===Logging=====
    glGetFloatv(GL_MODELVIEW_MATRIX, matrixf);
    stepM(matrixf, "glTranslatef", 4, GLPmatrix);
	
    glRotatef(60.0, 1.0, 0.0, 0.0);

    //5 ===Logging=====
    glGetFloatv(GL_MODELVIEW_MATRIX, matrixf);
    stepM(matrixf, "glRotatef", 5, GLPmatrix);

    glBegin(GL_POINTS);
    glVertex3f(1.0,1.0,1.0);
    glEnd();

    free_object(GLPmatrix, MATRIX);

}


int main(int argc, char **argv) {

    int scrWidth = 600;
    int scrHeight = 600;	

    //Glut Window initialization:
    glutInit(&argc, argv);
    glutInitWindowSize(scrWidth, scrHeight);
    glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("OpenGL main Window");
	
    glutDisplayFunc (display);

    glutMainLoop();

    return (0);
}


