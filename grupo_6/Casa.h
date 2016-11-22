#ifndef Casa_h
#define Casa_h

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

class Casa
{
private:
	GLuint estruturaTextura;
	GLuint telhadoTextura;
public:
	void Display();
	void DisplayEstrutura();
	void DisplayTelhado();
	void lerArquivo(const char *path);
	Casa();
	Casa(GLuint* estruturaTextura, GLuint* telhadoTextura);

	~Casa();
};
#endif
