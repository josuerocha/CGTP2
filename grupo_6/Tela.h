#ifndef Tela_h
#define Tela_h

#include <iostream>
#include <GL/glut.h>

//Custom includes
#include "Estruturas.h"
#include "Camera.h"

#define FORWARD 'w'
#define BACKWARD 's'
#define LEFT 'a'
#define RIGHT 'd'
#define FULLSCREEN 'f'
#define SHIFT 'p'
#define EXIT_ENVIRONMENT 27

class Tela
{
private:
	//variaveis de controle
	Camera camera;
	Coord2d mouse;
	bool keyBuffer[6]; //Respectivamente forward, backward, left, right, click, rightclick
    bool fullScreen;
	GLfloat xRotated, yRotated, zRotated;
	GLdouble radius=1;
	float speed; 
    //Objetos
	//Animacoes
	glutWindow janela;

public:
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
	void KeyboardSpecialDown(int key, int x, int y);
	void KeyboardSpecialUp(int key, int x, int y);
    void ControleTela();
};

#endif