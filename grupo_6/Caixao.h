#ifndef Caixao_h
#define Caixao_h

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

class Caixao
{
private:
	GLuint caixaoTextura;
	
public:
	Caixao();
	Caixao(GLuint* caixaoTextura);

	~Caixao();

	void lerArquivo(const char *path);
	void Display();
};
#endif

