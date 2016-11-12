#include <GL/glut.h>
#include "soil/SOIL.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FORWARD 'w'
#define BACKWARD 's'
#define LEFT 'a'
#define RIGHT 'd'

void Initialize(){
	
}

void keyboardDown(unsigned char key, int x, int y) {
	tela.keyboardDown(key, x, y);
}

void keyboardUp(unsigned char key, int x, int y) {
	tela.keyboardUp(key, x, y);
}

//Mapear Teclas Especiais
void keyboardSpecialDown(int key, int x, int y) {
	cout << "Tecla especial pressionada: " << char(key) << ". Mouse (" << x << ',' << y << ')' << endl;
}

void keyboardSpecialUp(int key, int x, int y) {
	cout << "Tecla especial solta: " << char(key) << ". Mouse (" << x << ',' << y << ')' << endl;
}

//Mapear Eventos de Mouse
void mouseClick(int button, int state, int x, int y) {
	tela.mouseClick(button, state, x, y);
}

void mouseMotion(int x, int y) {
	tela.mouseMotion(x, y);
	
}

void Timer(int value) {
	glutPostRedisplay();
	glutTimerFunc(25, Timer, value);      /* 30 frames per second */
}

void main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,600);
	glutCreateWindow("NOME");

	Initialize();
	
	//Funções de captura de eventos do teclado
	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(keyboardDown);
	glutKeyboardUpFunc(keyboardUp);
	glutSpecialFunc(keyboardSpecialDown);
	glutSpecialUpFunc(keyboardSpecialUp);
	glutMouseFunc(mouseClick);
	glutMotionFunc(mouseMotion);

	glutDisplayFunc(Display);
	glutIdleFunc(Display);
	glutFullScreen();
	glutReshapeFunc(Reshape);

	glutMainLoop();

}


















