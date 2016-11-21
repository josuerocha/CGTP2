#include "Banco.h"

#include <iostream>
#include <string>
#include <vector>

#include "Estruturas.h"

using namespace std;

vector<Coord3d> ba_normais;
vector<Coord3d> ba_temp_v1;
vector<Coord3d> ba_temp_v2;
vector<Coord3d> ba_temp_v3;
vector<Coord3d> ba_temp_v4;
vector<Coord3d> ba_temp_v5;
vector<Coord3d> ba_temp_v6;
vector<Coord3d> ba_temp_v7;
vector<Coord3d> ba_temp_v8;
vector<Coord3d> ba_temp_v9;
vector<Coord3d> ba_temp_v10;
vector<Coord3d> ba_temp_v11;


Banco::Banco()
{
}

Banco::Banco(GLuint* bancoTextura)
{

	this->bancoTextura = *bancoTextura;

}

Banco::~Banco()
{
}

void Banco::lerArquivo(const char *path) {
	FILE * file = fopen(path, "r");
	if (file == NULL) {
		printf("Impossible to open the file Banco!\n");
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
			ba_normais.push_back(normal);
		}
		else if (strcmp(lineHeader, "v1") == 0) {
			Coord3d v1;
			fscanf(file, "%f %f %f", &v1.x, &v1.y, &v1.z);
			ba_temp_v1.push_back(v1);
		}
		else if (strcmp(lineHeader, "v2") == 0) {
			Coord3d v2;
			fscanf(file, "%f %f %f", &v2.x, &v2.y, &v2.z);
			ba_temp_v2.push_back(v2);
		}
		else if (strcmp(lineHeader, "v3") == 0) {
			Coord3d v3;
			fscanf(file, "%f %f %f", &v3.x, &v3.y, &v3.z);
			ba_temp_v3.push_back(v3);
		}
		else if (strcmp(lineHeader, "v4") == 0) {
			Coord3d v4;
			fscanf(file, "%f %f %f", &v4.x, &v4.y, &v4.z);
			ba_temp_v4.push_back(v4);
		}
		else if (strcmp(lineHeader, "v5") == 0) {
			Coord3d v5;
			fscanf(file, "%f %f %f", &v5.x, &v5.y, &v5.z);
			ba_temp_v5.push_back(v5);
		}
		else if (strcmp(lineHeader, "v6") == 0) {
			Coord3d v6;
			fscanf(file, "%f %f %f", &v6.x, &v6.y, &v6.z);
			ba_temp_v6.push_back(v6);
		}
		else if (strcmp(lineHeader, "v7") == 0) {
			Coord3d v7;
			fscanf(file, "%f %f %f", &v7.x, &v7.y, &v7.z);
			ba_temp_v7.push_back(v7);
		}
		else if (strcmp(lineHeader, "v8") == 0) {
			Coord3d v8;
			fscanf(file, "%f %f %f", &v8.x, &v8.y, &v8.z);
			ba_temp_v8.push_back(v8);
		}
		else if (strcmp(lineHeader, "v9") == 0) {
			Coord3d v9;
			fscanf(file, "%f %f %f", &v9.x, &v9.y, &v9.z);
			ba_temp_v9.push_back(v9);
		}
		else if (strcmp(lineHeader, "v10") == 0) {
			Coord3d v10;
			fscanf(file, "%f %f %f", &v10.x, &v10.y, &v10.z);
			ba_temp_v10.push_back(v10);
		}
		else if (strcmp(lineHeader, "v11") == 0) {
			Coord3d v11;
			fscanf(file, "%f %f %f", &v11.x, &v11.y, &v11.z);
			ba_temp_v11.push_back(v11);
		}

	}
	fclose(file);
}
void Banco::Display() {
	lerArquivo("modelos//banco.txt");

	glPushMatrix();
	//	glBindTexture(GL_TEXTURE_2D, casaTextura);
	
	glRotatef(90, 0, 1, 0);
	glTranslatef(-7.0f, 0.0f, 3.7f);
	glScalef(1.5f,2.5f,1.5f);
	//glTranslatef(70, 0, 65);
	glBegin(GL_QUADS);
	glNormal3f(ba_normais[0].x, ba_normais[0].y, ba_normais[0].z);
	glVertex3f(ba_temp_v1[0].x, ba_temp_v1[0].y, ba_temp_v1[0].z);
	glVertex3f(ba_temp_v1[1].x, ba_temp_v1[1].y, ba_temp_v1[1].z);
	glVertex3f(ba_temp_v1[2].x, ba_temp_v1[2].y, ba_temp_v1[2].z);
	glEnd();
	
	glBegin(GL_QUADS);
	glNormal3f(ba_normais[1].x, ba_normais[1].y, ba_normais[1].z);
	glVertex3f(ba_temp_v2[0].x, ba_temp_v2[0].y, ba_temp_v2[0].z);
	glVertex3f(ba_temp_v2[1].x, ba_temp_v2[1].y, ba_temp_v2[1].z);
	glVertex3f(ba_temp_v2[2].x, ba_temp_v2[2].y, ba_temp_v2[2].z);
	glVertex3f(ba_temp_v2[3].x, ba_temp_v2[3].y, ba_temp_v2[3].z);
	glVertex3f(ba_temp_v2[4].x, ba_temp_v2[4].y, ba_temp_v2[4].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(ba_normais[2].x, ba_normais[2].y, ba_normais[2].z);
	glVertex3f(ba_temp_v3[0].x, ba_temp_v3[0].y, ba_temp_v3[0].z);
	glVertex3f(ba_temp_v3[1].x, ba_temp_v3[1].y, ba_temp_v3[1].z);
	glVertex3f(ba_temp_v3[2].x, ba_temp_v3[2].y, ba_temp_v3[2].z);
	glVertex3f(ba_temp_v3[3].x, ba_temp_v3[3].y, ba_temp_v3[3].z);
	glEnd();
	
	glBegin(GL_QUADS);
	glNormal3f(ba_normais[3].x, ba_normais[3].y, ba_normais[3].z);
	glVertex3f(ba_temp_v4[0].x, ba_temp_v4[0].y, ba_temp_v4[0].z);
	glVertex3f(ba_temp_v4[1].x, ba_temp_v4[1].y, ba_temp_v4[1].z);
	glVertex3f(ba_temp_v4[2].x, ba_temp_v4[2].y, ba_temp_v4[2].z);
	glVertex3f(ba_temp_v4[3].x, ba_temp_v4[3].y, ba_temp_v4[3].z);
	glVertex3f(ba_temp_v4[4].x, ba_temp_v4[4].y, ba_temp_v4[4].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(ba_normais[4].x, ba_normais[4].y, ba_normais[4].z);
	glVertex3f(ba_temp_v5[0].x, ba_temp_v5[0].y, ba_temp_v5[0].z);
	glVertex3f(ba_temp_v5[1].x, ba_temp_v5[1].y, ba_temp_v5[1].z);
	glVertex3f(ba_temp_v5[2].x, ba_temp_v5[2].y, ba_temp_v5[2].z);
	glVertex3f(ba_temp_v5[3].x, ba_temp_v5[3].y, ba_temp_v5[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(ba_normais[5].x, ba_normais[5].y, ba_normais[5].z);
	glVertex3f(ba_temp_v6[0].x, ba_temp_v6[0].y, ba_temp_v6[0].z);
	glVertex3f(ba_temp_v6[1].x, ba_temp_v6[1].y, ba_temp_v6[1].z);
	glVertex3f(ba_temp_v6[2].x, ba_temp_v6[2].y, ba_temp_v6[2].z);
	glVertex3f(ba_temp_v6[3].x, ba_temp_v6[3].y, ba_temp_v6[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(ba_normais[6].x, ba_normais[6].y, ba_normais[6].z);
	glVertex3f(ba_temp_v7[0].x, ba_temp_v7[0].y, ba_temp_v7[0].z);
	glVertex3f(ba_temp_v7[1].x, ba_temp_v7[1].y, ba_temp_v7[1].z);
	glVertex3f(ba_temp_v7[2].x, ba_temp_v7[2].y, ba_temp_v7[2].z);
	glVertex3f(ba_temp_v7[3].x, ba_temp_v7[3].y, ba_temp_v7[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(ba_normais[7].x, ba_normais[7].y, ba_normais[7].z);
	glVertex3f(ba_temp_v8[0].x, ba_temp_v8[0].y, ba_temp_v8[0].z);
	glVertex3f(ba_temp_v8[1].x, ba_temp_v8[1].y, ba_temp_v8[1].z);
	glVertex3f(ba_temp_v8[2].x, ba_temp_v8[2].y, ba_temp_v8[2].z);
	glVertex3f(ba_temp_v8[3].x, ba_temp_v8[3].y, ba_temp_v8[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(ba_normais[8].x, ba_normais[8].y, ba_normais[8].z);
	glVertex3f(ba_temp_v9[0].x, ba_temp_v9[0].y, ba_temp_v9[0].z);
	glVertex3f(ba_temp_v9[1].x, ba_temp_v9[1].y, ba_temp_v9[1].z);
	glVertex3f(ba_temp_v9[2].x, ba_temp_v9[2].y, ba_temp_v9[2].z);
	glVertex3f(ba_temp_v9[3].x, ba_temp_v9[3].y, ba_temp_v9[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(ba_normais[9].x, ba_normais[9].y, ba_normais[9].z);
	glVertex3f(ba_temp_v10[0].x, ba_temp_v10[0].y, ba_temp_v10[0].z);
	glVertex3f(ba_temp_v10[1].x, ba_temp_v10[1].y, ba_temp_v10[1].z);
	glVertex3f(ba_temp_v10[2].x, ba_temp_v10[2].y, ba_temp_v10[2].z);
	glVertex3f(ba_temp_v10[3].x, ba_temp_v10[3].y, ba_temp_v10[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(ba_normais[10].x, ba_normais[10].y, ba_normais[10].z);
	glVertex3f(ba_temp_v11[0].x, ba_temp_v11[0].y, ba_temp_v11[0].z);
	glVertex3f(ba_temp_v11[1].x, ba_temp_v11[1].y, ba_temp_v11[1].z);
	glVertex3f(ba_temp_v11[2].x, ba_temp_v11[2].y, ba_temp_v11[2].z);
	glVertex3f(ba_temp_v11[3].x, ba_temp_v11[3].y, ba_temp_v11[3].z);
	glEnd();

	glPopMatrix();

}

