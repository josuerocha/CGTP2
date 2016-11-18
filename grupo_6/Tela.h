#ifndef Tela_h
#define Tela_h

//Standard includes
#include "GL/glut.h"
#include <iostream>
#include "soil/SOIL.h"

//Custom includes
#include "Estruturas.h"
#include "Camera.h"
#include "EsferaMundo.h"
#include "PlanoChao.h"
#include "Neblina.h"

#define FORWARD 'w'
#define BACKWARD 's'
#define LEFT 'a'
#define RIGHT 'd'
#define FULLSCREEN 'i'
#define SHIFT 'p'
#define UP 'e'
#define DOWN 'g'
#define EXIT_ENVIRONMENT 27
#define CAM_COORDINATES 'c'
#define FOG_INCREASE 'f'
#define FOG_DECREASE 'g'

class Tela
{
private:
	//variaveis de controle
	Camera camera;
	Coord2d mouse;
	bool keyBuffer[10]; //Respectivamente forward, backward, left, right,up,down, click, rightclick, fog up, fog down
    bool fullScreen;
	glutWindow janela;
    
	//Objetos
	PlanoChao planoChao;

	//Objetos com quadricas
	EsferaMundo esferaMundo;

	//Objetos complexos

	//Animacoes
	Neblina neblina;

public:
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
	void KeyboardSpecialDown(int key, int x, int y);
	void KeyboardSpecialUp(int key, int x, int y);

	//Funções de controle de ações
    void ControleTela();
};

#endif