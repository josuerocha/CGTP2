#ifndef CaixaAreia_h
#define CaixaAreia_h

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

class CaixaAreia
{
private:
	GLuint topoTextura;
	GLuint baseTextura;
public:
	CaixaAreia();
	CaixaAreia(GLuint* topoTextura, GLuint* baseTextura);

	~CaixaAreia();

	void lerArquivo(const char *path);
	void Display();
	void DisplayTopo();
	void DisplayBase();

};
#endif

