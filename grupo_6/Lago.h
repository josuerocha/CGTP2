#ifndef LAGO_H
#define LAGO_H
//standard includes
#include "GL/glut.h"
#include "soil/SOIL.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

//custom includes
#include "BolaLago.h"
#include "Estruturas.h"


class Lago {
private:

	float posiX;
	float posiY;
	float posiZ;
	float dimX;
	float dimY;
	float dimZ;
	std::vector <BolaLago*> bolas;
	float tamanhoBolas;
	float qtdBolasZ;
	float qtdBolasX;

public:

	Lago(Coord3d coord);


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
