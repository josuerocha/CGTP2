#include <GL/glut.h>
#include "soil/SOIL.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,600);
	glutCreateWindow("NOME DA TELA");

	Initialize();
	glutKeyboardFunc();
	glutSpecialFunc();

	glutDisplayFunc(Display);
	glutIdleFunc(Display);
	glutFullScreen();
	glutReshapeFunc(Reshape);

	glutMainLoop();


	return(0);
}