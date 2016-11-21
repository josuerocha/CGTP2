#ifndef Banco_h
#define Banco_h

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

class Banco
{
private:
	GLuint bancoTextura;
public:
	Banco();
	Banco(GLuint* bancoTextura);

	~Banco();

	void lerArquivo(const char *path);
	void Display();

};
#endif

