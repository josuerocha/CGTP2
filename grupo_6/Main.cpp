#include <GL/glut.h>
//#include "soil/SOIL.h"
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
using namespace std;

//Custom includes
#include "Tela.h"

//Criação do objeto tela
Tela tela = Tela();

//Assinaturas dos métodos
void KeyboardDown(unsigned char key, int x, int y);
void KeyboardUp(unsigned char key, int x, int y);
void KeyboardSpecialDown(int key, int x, int y);
void KeyboardSpecialUp(int key, int x, int y);
void MouseClick(int button, int state, int x, int y);
void MouseMotion(int x, int y);
void Reshape(GLsizei w, GLsizei h);
void Timer(int value);
void DisplayScene();
void Initialize();

int main(int argc, char **argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,600);
	glutCreateWindow("Morgan Falls Lake");

	Initialize();

	glutTimerFunc(1000 / 45, Timer, 0);
	
	//Funções de captura de eventos do teclado
	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(KeyboardDown);
	glutKeyboardUpFunc(KeyboardUp);
	glutSpecialFunc(KeyboardSpecialDown);
	glutSpecialUpFunc(KeyboardSpecialUp);
	glutMouseFunc(MouseClick);
	glutMotionFunc(MouseMotion);

	glutDisplayFunc(DisplayScene);
	glutIdleFunc(DisplayScene);
	glutReshapeFunc(Reshape);

	glutMainLoop();

	return 0;
}

void Initialize(){
	
}

void KeyboardDown(unsigned char key, int x, int y) {
	tela.KeyboardDown(key, x, y);
}

void KeyboardUp(unsigned char key, int x, int y) {
	tela.KeyboardUp(key, x, y);
}

//Mapear Teclas Especiais
void KeyboardSpecialDown(int key, int x, int y) {
	tela.KeyboardSpecialDown(key, x, y);
}

void KeyboardSpecialUp(int key, int x, int y) {
	tela.KeyboardSpecialUp(key, x, y);
}

//Mapear Eventos de Mouse
void MouseClick(int button, int state, int x, int y) {
	tela.MouseClick(button, state, x, y);
}

void MouseMotion(int x, int y) {
	tela.MouseMotion(x, y);
	
}

void Reshape(GLsizei w, GLsizei h)
{
	tela.Reshape(w, h);
}

void Timer(int value) {
	tela.ControleTela();
	
	glutPostRedisplay();

	glutTimerFunc(25, Timer, value);      /* 30 frames per second */
}

void DisplayScene(){
	tela.Display();
}