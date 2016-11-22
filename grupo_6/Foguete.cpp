#include "Foguete.h"

#include <iostream>
#include <string>
#include <vector>

#include "Estruturas.h"
#include "Foguete.h"

using namespace std;

vector<Coord3d> f_normais;

GLUquadricObj *cilindroFog_ = gluNewQuadric();
vector<Coord3d> normaisFog;
vector<Cilindro> cilindroFog;
vector<Cilindro> cilindroFog2;


Foguete::Foguete()
{
	lerArquivo("modelos//foguete.txt");
}

Foguete::Foguete(GLuint* TextConeFog, GLuint* TextCilFog)
{
	this->TextConeFog = *TextConeFog;
	this->TextCilFog = *TextCilFog;

	lerArquivo("modelos//foguete.txt");
}

Foguete::~Foguete()
{
}

void Foguete::lerArquivo(const char *path) {
	FILE * file = fopen(path, "r");
	if (file == NULL) {
		printf("Impossible to open the file !\n");
		//return false;
	}
	while (1) {
		char lineHeader[128];
		// read the first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break; // EOF = End Of File. Quit the loop.

				   // else : parse lineHeader
		if (strcmp(lineHeader, "vn") == 0) {
			Coord3d normal;
			fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
			f_normais.push_back(normal);
		}
		else if (strcmp(lineHeader, "c") == 0) {
			Cilindro c;
			fscanf(file, "%f %f %f %f %f", &c.baseRadius, &c.topRadius, &c.height, &c.slices, &c.stacks);
			cilindroFog.push_back(c);
		}
	}
	fclose(file);
}

void Foguete::Display() {

	DisplayCilFog();
	DisplayConeFog();

}


/*Cilindro Vertical*/

void Foguete::DisplayCilFog() {
	glPushMatrix();

	glBindTexture(GL_TEXTURE_2D, TextConeFog);// passsar Textura

	glRotatef(-90, 1, 0, 0);

	glTranslatef(-80, -50, 10);
	
	gluCylinder(cilindroFog_, cilindroFog[0].baseRadius, cilindroFog[0].topRadius, cilindroFog[0].height, cilindroFog[0].slices, cilindroFog[0].stacks);

	glPopMatrix();
}

void Foguete::DisplayConeFog() {
	
	//parte de cima
	glPushMatrix();


	glTranslatef(-80, 26, 50);

	glBindTexture(GL_TEXTURE_2D, TextCilFog);// passsar Textura
	glRotatef(-90,1, 0, 0);


	gluCylinder(cilindroFog_, cilindroFog[1].baseRadius, cilindroFog[1].topRadius, cilindroFog[1].height, cilindroFog[1].slices, cilindroFog[1].stacks);

	glPopMatrix();
}