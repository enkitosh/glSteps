#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printGLmatrix(GLfloat *matrix, int size) {

    int i;
    int j;
    int show = 0;

    printf("\n");

    for(i = 0; i < sqrt(size); i++) {
    printf("[ ");
       for(j = 0; j < sqrt(size); j++) {

		    printf(" %g ", matrix[show]);

            show++;
        }
	    printf("]\n");
	}
    
    printf("\n");


}

void display(void)
{
	GLfloat matrixf[16];
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glGetFloatv(GL_PROJECTION_MATRIX, matrixf);
	
    printGLmatrix(matrixf, 16);
	
	gluPerspective(90.0, 1.25, 3.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glGetFloatv(GL_MODELVIEW_MATRIX, matrixf);
    printGLmatrix(matrixf,16);

	gluLookAt(8.0, 5.0, 7.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	//3 ===Logging====
	glGetFloatv(GL_MODELVIEW_MATRIX, matrixf);
    printGLmatrix(matrixf,16);

	glTranslatef(5.0, 7.0, 12.0);

	//7 ===Logging=====
	glGetFloatv(GL_MODELVIEW_MATRIX, matrixf);
    printGLmatrix(matrixf,16);
	
	glRotatef(60.0, 1.0, 0.0, 0.0);

	//8 ===Logging=====
	glGetFloatv(GL_MODELVIEW_MATRIX, matrixf);
    printGLmatrix(matrixf,16);

	glBegin(GL_POINTS);
	glVertex3f(1.0,1.0,1.0);
	glEnd();


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

