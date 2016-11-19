#ifndef MOINHO_H
#define MOINHO_H

//Standard includes
#include "GL/glut.h"
#include "soil/SOIL.h"
#include <math.h>
#include <iostream>

//Custom includes
#include "Estruturas.h"

class Moinho {
private:
	float posiX;//a coordenada X do seu centro
	float posiY;//a coordenada Y do seu centro
	float posiZ;//a coordenada Z do seu centro
	float dimX;// a dimencao em relacao ao eixo X
	float dimY;// a dimencao em relacao ao eixo Y
	float dimZ;// a dimencao em relacao ao eixo Z
	float angX;// angulo a ser rotacionado em relacao ao eixo X
	float angY;// angulo a ser rotacionado em relacao ao eixo Y
	float angZ;// angulo a ser rotacionado em relacao ao eixo Z
	float velocidade;//velocidade que o Objeto anda pela tela
	float velocAngParabola;//velocidade de mudanca do angulo da parabola(para outro tipo de obj.)
	float angHelice;
	GLuint* cima1;// Ponteiros para as posicoes com texturas do vetor do programa principal
	GLuint* lado1;
	GLuint* frente1;
	GLuint* tras1;
	GLuint* corpo;
	GLuint* eixo;

public:

	Moinho(GLuint* c1,
		GLuint* l1,
		GLuint* f1,
		GLuint* t1,
		GLuint* co,
		GLuint* ei,
		Coord3d coord);//contrutor, inicializa variaveis gerais

	
	void Display();

	void desenhaHelice();
	void desenhaHeliceParte();
	
	float getPosiX();
	float getPosiY();
	float getPosiZ();
	float getAnguloX();
	float getAnguloY();
	float getAnguloZ();
	float getDimX();
	float getDimY();
	float getDimZ();
	void setPosiX(float a);
	void setPosiY(float a);
	void setPosiZ(float a);
	void setAngX(float a);
	void setAngY(float a);
	void setAngZ(float a);
};
#endif
