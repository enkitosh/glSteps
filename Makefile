all:
	gcc -o testSteps testSteps.c glSteps.h glSteps.c glPrint/*.c glPrint/*.h -framework OpenGL -framework GLUT

compare:
	gcc -o compareSteps compareSteps.c -framework OpenGL -framework GLUT

clean:
	rm testSteps
