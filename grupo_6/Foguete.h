#ifndef Foguete_h
#define Foguete_h

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

class Foguete
{
private:
	GLuint TextConeFog;
	GLuint TextCilFog;
	
public:
	Foguete();
	Foguete(GLuint* TextConeFog, GLuint* TextCilFog);

	~Foguete();

	void lerArquivo(const char *path);
	void Display();
	void DisplayConeFog();
	void DisplayCilFog();
};
#endif

