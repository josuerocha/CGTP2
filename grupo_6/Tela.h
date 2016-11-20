#ifndef Tela_h
#define Tela_h

//Standard includes
#include "GL/glut.h"
#include <iostream>
#include "soil/SOIL.h"
#include <vector>

//Custom includes
#include "Estruturas.h"
#include "Camera.h"
#include "EsferaMundo.h"
#include "PlanoChao.h"
#include "Neblina.h"
#include "Passaro.h"
#include "CarregadorTexturas.h"
#include "Moinho.h"
#include "Arvore.h"
#include "Lago.h"

//Definicoes de teclas
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
#define DIFFUSE_LIGHT 'o'
#define INCREMENT_LIGHT '+'
#define DECREMENT_LIGHT '-'
#define FIXED_LIGHT_SWITCH 'l'
//----------------------

class Tela
{
private:
	//variaveis de controle
	Coord2d mouse;
	bool keyBuffer[10]; //Respectivamente forward, backward, left, right,up,down, click, rightclick, fog up, fog down
    bool fullScreen;
	glutWindow janela;
	bool diffuseLightFlag;
	bool fixedLightFlag;
	//Classes de controle
	Camera camera;
	CarregadorTexturas carregadorTexturas;
    
	//Objetos
	PlanoChao* planoChao;
	EsferaMundo* esferaMundo;
	Moinho* moinho;
	Lago* lago;

	float rgbComponents;
	//Vetores de objetos
	std::vector <Passaro*> vetorPassaros;
	std::vector <Arvore*> vetorArvores;

	//Objetos com quadricas
	

	//Objetos complexos

	//Animacoes
	Neblina neblina;

	//Luzes


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

	//Funções de controle de acoes
    void ControleTela();

	//Funcoes de exibicao de objetos
	void DisplayBirds();
	void DisplayTrees();
};

#endif