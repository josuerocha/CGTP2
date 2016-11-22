#ifndef Barco_h
#define Barco_h

//Standard includes
#include "GL/glut.h"
#include <iostream>
#include "soil/SOIL.h"
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>

//Custom includes
#include "Estruturas.h"
#include "FuncoesExtra.h"

class Barco
{
private:
	GLuint baseTextura;
	GLuint cilindroTextura;
	GLuint trianguloTextura;
public:
	Barco();
	Barco(GLuint* barcoTextura, GLuint* cilindroTextura, GLuint* trianguloTextura);

	~Barco();

	void lerArquivo(const char *path);
	void DisplayBase();
	void DisplayCilindro();
	void DisplayTriangulo();
	void Display();

};
#endif

