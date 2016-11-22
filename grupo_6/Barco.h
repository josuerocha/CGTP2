#ifndef Barco_h
#define Barco_h

//Standard includes
#include "GL/glut.h"
#include <iostream>
#include "soil/SOIL.h"

//Custom includes
#include "Estruturas.h"
#include "FuncoesExtra.h"

class Barco
{
private:
	GLuint barcoTextura;
public:
	Barco();
	Barco(GLuint* barcoTextura);

	~Barco();

	void lerArquivo(const char *path);
	void Display();

};
#endif

