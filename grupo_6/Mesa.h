#ifndef Mesa_h
#define Mesa_h

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

class Mesa
{
private:
	GLuint mesaTextura;
public:
	Mesa();
	Mesa(GLuint* chaoTextura);

	~Mesa();

	void lerArquivo(const char *path);
	void Display();

};
#endif

