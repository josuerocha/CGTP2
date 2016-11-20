#ifndef BOLALAGO_H
#define BOLALAGO_H
#include "GL/glut.h"
#include "soil/SOIL.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

class BolaLago {
	private:
	float posiX;//a coordenada X do seu centro
	float posiY;//a coordenada Y do seu centro
	float posiZ;//a coordenada Z do seu centro
	float dimX;//suas dimens�es em cada um dos eixos
	float dimY;
	float dimZ;
	float posiYMax;//altura m�xima que vai subir
	float posiYMin;//altura m�nima
	float posiYdescanso;
	float velocidade;//de movimento
	bool subindo;//para saber se est� em movimento de subida ou descida
	bool subiu;
	float tempoEspera;//tempo entre ondas
	float tempo;
	float ambiente[4];
	GLint brilho;

	GLuint* waterTex;
	
	public:

	BolaLago(float x, float y, float z, float dx, float dy, float dz,float tempo2, GLuint* waterTex);

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
