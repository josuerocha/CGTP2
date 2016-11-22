#ifndef caixadeareia_h
#define caixadeareia_h

//Standard includes
#include "GL/glut.h"
#include <iostream>
#include "soil/SOIL.h"

//Custom includes
#include "Estruturas.h"
#include "FuncoesExtra.h"

class caixadeareia
{
private:
	GLuint topoTextura;
	GLuint baseTextura;
public:
	caixadeareia();
	caixadeareia(GLuint* topoTextura, GLuint* baseTextura);

	~caixadeareia();

	void lerArquivo(const char *path);
	void Display();
	void DisplayTopo();
	void DisplayBase();

};
#endif

