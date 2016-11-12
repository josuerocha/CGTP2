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

class Tela
{
public:
	//variaveis de controle
	Coord2d mouse;
	bool keyBuffer[6]; //Respectivamente forward, backward, left, right, click, rightclick
    bool fullScreen;
    //Objetos


	//Animacoes


	glutWindow janela;

	Tela();
	~Tela();


    //Funções de manipulação de tela
	void Initialize();
	void Reshape(GLsizei w, GLsizei h);
	void Display();

    //FUnções de captura de eventos do teclado
	void KeyboardDown(unsigned char key, int x, int y);
	void MouseMotion(int x, int y);
	void KeyboardUp(unsigned char key, int x, int y);
	void MouseClick(int button, int state, int x, int y);
};

#endif