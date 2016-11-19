#ifndef FOLHA_H
#define FOLHA_H
#include "GL/glut.h"
#include "soil/SOIL.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

class Folha {
private:
	float posiX;//a coordenada X do seu centro
	float posiY;//a coordenada Y do seu centro
	float posiZ;//a coordenada Z do seu centro
	float grossura;
	float comprimento;
	float angX;// angulo a ser rotacionado em relacao ao eixo X
	float angY;// angulo a ser rotacionado em relacao ao eixo Y
	float angZ;// angulo a ser rotacionado em relacao ao eixo Z
	float angZMax;
	float velocidade;
	bool subindo;
			   //GLuint* cima1;// Ponteiros para as posicoes com texturas do vetor do programa principal
			   //GLuint* lado1;
			   //GLuint* frente1;
			   //GLuint* tras1;
			   //GLuint* corpo;
			   //GLuint* eixo;

public:

	Folha(float x, float y, float z, float g, float c, float angy2);//contrutor, inicializa variaveis gerais


	void desenha();//e' chamada pelo programa principal para desenhar o Obj.

	float getPosiX();
	float getPosiY();
	float getPosiZ();
	float getAnguloX();
	float getAnguloY();
	float getAnguloZ();
	void setPosiX(float a);
	void setPosiY(float a);
	void setPosiZ(float a);
	void setAngX(float a);
	void setAngY(float a);
	void setAngZ(float a);
};
#endif
