#ifndef LAGO_H
#define LAGO_H

//Standard includes
#include "GL/glut.h"
#include "soil/SOIL.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

//Custom includes
#include "BolaLago.h"
#include "Estruturas.h"

using namespace std;


class Lago {
private:
	GLuint* textura;

	float posiX;//a coordenada X do seu centro
	float posiY;//a coordenada Y do seu centro
	float posiZ;//a coordenada Z do seu centro
	float dimX;// a dimencao em relacao ao eixo X
	float dimY;// a dimencao em relacao ao eixo Y
	float dimZ;// a dimencao em relacao ao eixo Z
	vector <BolaLago*> bolas;
	float tamanhoBolas;
	float qtdBolasZ;
	float qtdBolasX;
	float anguloDaOnda;

public:

	Lago(Coord3d coord, GLuint* textura);
	~Lago();

	void Display();

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
