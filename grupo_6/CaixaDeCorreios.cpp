#include "CaixaDeCorreios.h"

#include <iostream>
#include <string>
#include <vector>

#include "Estruturas.h"

using namespace std;


GLUquadricObj *cilindro3 = gluNewQuadric();
vector<Coord3d> cx_normais;
vector<Coord3d> cx_temp_v1;
vector<Coord3d> cx_temp_v2;
vector<Coord3d> cx_temp_v3;
vector<Coord3d> cx_temp_v4;
vector<Coord3d> cx_temp_v5;
vector<Coord3d> cx_temp_v6;


CaixaDeCorreios::CaixaDeCorreios()
{

}

CaixaDeCorreios::CaixaDeCorreios(GLuint* caixaTextura, GLuint* cilindroTextura)
{

	this->caixaTextura = *caixaTextura;
	this->cilindroTextura = *cilindroTextura;
	lerArquivo("modelos//correio.txt");
}

CaixaDeCorreios::~CaixaDeCorreios()
{
}

void CaixaDeCorreios::lerArquivo(const char *path) {
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
			cx_normais.push_back(normal);
		}
		else if (strcmp(lineHeader, "v1") == 0) {
			Coord3d v1;
			fscanf(file, "%f %f %f", &v1.x, &v1.y, &v1.z);
			cx_temp_v1.push_back(v1);
		}
		else if (strcmp(lineHeader, "v2") == 0) {
			Coord3d v2;
			fscanf(file, "%f %f %f", &v2.x, &v2.y, &v2.z);
			cx_temp_v2.push_back(v2);
		}
		else if (strcmp(lineHeader, "v3") == 0) {
			Coord3d v3;
			fscanf(file, "%f %f %f", &v3.x, &v3.y, &v3.z);
			cx_temp_v3.push_back(v3);
		}
		else if (strcmp(lineHeader, "v4") == 0) {
			Coord3d v4;
			fscanf(file, "%f %f %f", &v4.x, &v4.y, &v4.z);
			cx_temp_v4.push_back(v4);
		}
		else if (strcmp(lineHeader, "v5") == 0) {
			Coord3d v5;
			fscanf(file, "%f %f %f", &v5.x, &v5.y, &v5.z);
			cx_temp_v5.push_back(v5);
		}
		else if (strcmp(lineHeader, "v6") == 0) {
			Coord3d v6;
			fscanf(file, "%f %f %f", &v6.x, &v6.y, &v6.z);
			cx_temp_v6.push_back(v6);
		}
	}
	fclose(file);
}

void CaixaDeCorreios::caixaDisplay() {
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, caixaTextura);
	glRotatef(90, 0, 1, 0);
	glTranslatef(90.0f, 3.0f, 40.0f);
	//glTranslatef(0, 10, 0);
	

	glBegin(GL_QUADS);
	glNormal3f(cx_normais[0].x, cx_normais[0].y, cx_normais[0].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(cx_temp_v1[0].x, cx_temp_v1[0].y, cx_temp_v1[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(cx_temp_v1[1].x, cx_temp_v1[1].y, cx_temp_v1[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(cx_temp_v1[2].x, cx_temp_v1[2].y, cx_temp_v1[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(cx_temp_v1[3].x, cx_temp_v1[3].y, cx_temp_v1[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(cx_normais[1].x, cx_normais[1].y, cx_normais[1].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(cx_temp_v2[0].x, cx_temp_v2[0].y, cx_temp_v2[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(cx_temp_v2[1].x, cx_temp_v2[1].y, cx_temp_v2[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(cx_temp_v2[2].x, cx_temp_v2[2].y, cx_temp_v2[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(cx_temp_v2[3].x, cx_temp_v2[3].y, cx_temp_v2[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(cx_normais[2].x, cx_normais[2].y, cx_normais[2].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(cx_temp_v3[0].x, cx_temp_v3[0].y, cx_temp_v3[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(cx_temp_v3[1].x, cx_temp_v3[1].y, cx_temp_v3[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(cx_temp_v3[2].x, cx_temp_v3[2].y, cx_temp_v3[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(cx_temp_v3[3].x, cx_temp_v3[3].y, cx_temp_v3[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(cx_normais[3].x, cx_normais[3].y, cx_normais[3].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(cx_temp_v4[0].x, cx_temp_v4[0].y, cx_temp_v4[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(cx_temp_v4[1].x, cx_temp_v4[1].y, cx_temp_v4[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(cx_temp_v4[2].x, cx_temp_v4[2].y, cx_temp_v4[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(cx_temp_v4[3].x, cx_temp_v4[3].y, cx_temp_v4[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(cx_normais[4].x, cx_normais[4].y, cx_normais[4].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(cx_temp_v5[0].x, cx_temp_v5[0].y, cx_temp_v5[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(cx_temp_v5[1].x, cx_temp_v5[1].y, cx_temp_v5[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(cx_temp_v5[2].x, cx_temp_v5[2].y, cx_temp_v5[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(cx_temp_v5[3].x, cx_temp_v5[3].y, cx_temp_v5[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(cx_normais[5].x, cx_normais[5].y, cx_normais[5].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(cx_temp_v6[0].x, cx_temp_v6[0].y, cx_temp_v6[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(cx_temp_v6[1].x, cx_temp_v6[1].y, cx_temp_v6[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(cx_temp_v6[2].x, cx_temp_v6[2].y, cx_temp_v6[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(cx_temp_v6[3].x, cx_temp_v6[3].y, cx_temp_v6[3].z);
	glEnd();

	glPopMatrix();

}

//HASTE DA CAIXA DE CORREIO
void CaixaDeCorreios::cilindroDisplay() {
	glPushMatrix();
	gluQuadricNormals(cilindro3, GLU_SMOOTH);
	gluQuadricTexture(cilindro3, GLU_TRUE);
	glRotatef(-90, 1, 0, 0);
	glTranslatef(40.0f, 90.0f, 0.0f);
	gluCylinder(cilindro3, 0.1f, 0.1f, 4.0f, 10, 10);
	glPopMatrix();
}


void CaixaDeCorreios::Display() {
	cilindroDisplay();
	caixaDisplay();
	
}