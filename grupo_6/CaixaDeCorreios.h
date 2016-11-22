#ifndef CaixaDeCorreios_h
#define CaixaDeCorreios_h

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

class CaixaDeCorreios
{
private:
	GLuint cilindroTextura;
	GLuint caixaTextura;
public:
	CaixaDeCorreios();
	CaixaDeCorreios(GLuint* caixaoTextura, GLuint* cilindroTextura);

	~CaixaDeCorreios();

	void lerArquivo(const char *path);
	void caixaDisplay();
	void cilindroDisplay();
	void Display();
};
#endif

