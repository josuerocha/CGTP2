#ifndef Tela_h
#define Tela_h

#include <iostream>
#include <GL/glut.h>

//Custom includes
#include "Estruturas.h"

#define FORWARD 'w'
#define BACKWARD 's'
#define LEFT 'a'
#define RIGHT 'd'
#define FULLSCREEN 'f'
#define EXIT_ENVIRONMENT 27

class Tela
{
public:
	//variaveis de controle
	Coord2d mouse;
	Coord3d camera;
	Coord3d lookAt;
	bool keyBuffer[6]; //Respectivamente forward, backward, left, right, click, rightclick
    bool fullScreen;
	GLfloat xRotated, yRotated, zRotated;
	GLdouble radius=1; 
    //Objetos
	//Animacoes


	glutWindow janela;

	Tela();
	~Tela();


    //Funções de manipulação de tela
	void Initialize();
	void Reshape(GLsizei w, GLsizei h);
	void Display();
	void DrawSphere();

    //FUnções de captura de eventos do teclado
	void KeyboardDown(unsigned char key, int x, int y);
	void MouseMotion(int x, int y);
	void KeyboardUp(unsigned char key, int x, int y);
	void MouseClick(int button, int state, int x, int y);
    void ControleTela();
};

#endif