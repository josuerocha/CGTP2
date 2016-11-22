#include "Casa.h"

#include <iostream>
#include <string>
#include <vector>

#include "Estruturas.h"

using namespace std;

vector<Coord3d> casa_normais;
vector<Coord3d> casa_temp_v1;
vector<Coord3d> casa_temp_v2;
vector<Coord3d> casa_temp_v3;
vector<Coord3d> casa_temp_v4;
vector<Coord3d> casa_temp_v5;
vector<Coord3d> casa_temp_v6;
vector<Coord3d> casa_temp_v7;
vector<Coord3d> casa_temp_v8;
vector<Coord3d> casa_temp_v9;

Casa::Casa()
{
}

Casa::Casa(GLuint* estruturaTextura, GLuint* telhadoTextura)
{

	this->estruturaTextura = *estruturaTextura;
	this->telhadoTextura = *telhadoTextura;
	lerArquivo("modelos//casa.txt");

}

Casa::~Casa()
{
}

void Casa::lerArquivo(const char *path) {
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
			casa_normais.push_back(normal);
		}
		else if (strcmp(lineHeader, "v1") == 0) {
			Coord3d v1;
			fscanf(file, "%f %f %f", &v1.x, &v1.y, &v1.z);
			casa_temp_v1.push_back(v1);
		}
		else if (strcmp(lineHeader, "v2") == 0) {
			Coord3d v2;
			fscanf(file, "%f %f %f", &v2.x, &v2.y, &v2.z);
			casa_temp_v2.push_back(v2);
		}
		else if (strcmp(lineHeader, "v3") == 0) {
			Coord3d v3;
			fscanf(file, "%f %f %f", &v3.x, &v3.y, &v3.z);
			casa_temp_v3.push_back(v3);
		}
		else if (strcmp(lineHeader, "v4") == 0) {
			Coord3d v4;
			fscanf(file, "%f %f %f", &v4.x, &v4.y, &v4.z);
			casa_temp_v4.push_back(v4);
		}
		else if (strcmp(lineHeader, "v5") == 0) {
			Coord3d v5;
			fscanf(file, "%f %f %f", &v5.x, &v5.y, &v5.z);
			casa_temp_v5.push_back(v5);
		}
		else if (strcmp(lineHeader, "v6") == 0) {
			Coord3d v6;
			fscanf(file, "%f %f %f", &v6.x, &v6.y, &v6.z);
			casa_temp_v6.push_back(v6);
		}
		else if (strcmp(lineHeader, "v7") == 0) {
			Coord3d v7;
			fscanf(file, "%f %f %f", &v7.x, &v7.y, &v7.z);
			casa_temp_v7.push_back(v7);
		}
		else if (strcmp(lineHeader, "v8") == 0) {
			Coord3d v8;
			fscanf(file, "%f %f %f", &v8.x, &v8.y, &v8.z);
			casa_temp_v8.push_back(v8);
		}
		else if (strcmp(lineHeader, "v9") == 0) {
			Coord3d v9;
			fscanf(file, "%f %f %f", &v9.x, &v9.y, &v9.z);
			casa_temp_v9.push_back(v9);
		}
	}
	fclose(file);
}
void Casa::DisplayTelhado() {
	glPushMatrix();

	glBindTexture(GL_TEXTURE_2D, telhadoTextura);
	glRotatef(-15, 0, 1, 0);
	glTranslatef(20, 0, -110);
	glScalef(4.5f, 2.5f, 2.5f);
	
	glBegin(GL_QUADS);
	glNormal3f(casa_normais[5].x, casa_normais[5].y, casa_normais[5].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(casa_temp_v6[0].x, casa_temp_v6[0].y, casa_temp_v6[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(casa_temp_v6[1].x, casa_temp_v6[1].y, casa_temp_v6[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(casa_temp_v6[2].x, casa_temp_v6[2].y, casa_temp_v6[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(casa_temp_v6[3].x, casa_temp_v6[3].y, casa_temp_v6[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(casa_normais[6].x, casa_normais[6].y, casa_normais[6].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(casa_temp_v7[0].x, casa_temp_v7[0].y, casa_temp_v7[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(casa_temp_v7[1].x, casa_temp_v7[1].y, casa_temp_v7[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(casa_temp_v7[2].x, casa_temp_v7[2].y, casa_temp_v7[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(casa_temp_v7[3].x, casa_temp_v7[3].y, casa_temp_v7[3].z);
	glEnd();

	glPopMatrix();
}

void Casa::DisplayEstrutura() {
	glPushMatrix();

	glBindTexture(GL_TEXTURE_2D, estruturaTextura);
	//glRotatef(90, 0, 1, 0);
	glRotatef(-15, 0, 1, 0);
	glTranslatef(20, 0, -110);
	glScalef(4.5f, 2.5f, 2.5f);
	//estrutura
	glBegin(GL_QUADS);
	glNormal3f(casa_normais[0].x, casa_normais[0].y, casa_normais[0].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(casa_temp_v1[0].x, casa_temp_v1[0].y, casa_temp_v1[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(casa_temp_v1[1].x, casa_temp_v1[1].y, casa_temp_v1[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(casa_temp_v1[2].x, casa_temp_v1[2].y, casa_temp_v1[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(casa_temp_v1[3].x, casa_temp_v1[3].y, casa_temp_v1[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(casa_normais[1].x, casa_normais[1].y, casa_normais[1].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(casa_temp_v2[0].x, casa_temp_v2[0].y, casa_temp_v2[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(casa_temp_v2[1].x, casa_temp_v2[1].y, casa_temp_v2[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(casa_temp_v2[2].x, casa_temp_v2[2].y, casa_temp_v2[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(casa_temp_v2[3].x, casa_temp_v2[3].y, casa_temp_v2[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(casa_normais[2].x, casa_normais[2].y, casa_normais[2].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(casa_temp_v3[0].x, casa_temp_v3[0].y, casa_temp_v3[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(casa_temp_v3[1].x, casa_temp_v3[1].y, casa_temp_v3[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(casa_temp_v3[2].x, casa_temp_v3[2].y, casa_temp_v3[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(casa_temp_v3[3].x, casa_temp_v3[3].y, casa_temp_v3[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(casa_normais[3].x, casa_normais[3].y, casa_normais[3].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(casa_temp_v4[0].x, casa_temp_v4[0].y, casa_temp_v4[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(casa_temp_v4[1].x, casa_temp_v4[1].y, casa_temp_v4[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(casa_temp_v4[2].x, casa_temp_v4[2].y, casa_temp_v4[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(casa_temp_v4[3].x, casa_temp_v4[3].y, casa_temp_v4[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(casa_normais[4].x, casa_normais[4].y, casa_normais[4].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(casa_temp_v5[0].x, casa_temp_v5[0].y, casa_temp_v5[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(casa_temp_v5[1].x, casa_temp_v5[1].y, casa_temp_v5[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(casa_temp_v5[2].x, casa_temp_v5[2].y, casa_temp_v5[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(casa_temp_v5[3].x, casa_temp_v5[3].y, casa_temp_v5[3].z);
	glEnd();
	glPopMatrix();
}

void Casa::Display() {
	DisplayEstrutura();
	DisplayTelhado();
}