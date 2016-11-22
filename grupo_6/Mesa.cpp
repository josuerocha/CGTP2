#include "Mesa.h"

#include <iostream>
#include <string>
#include <vector>

#include "Estruturas.h"



using namespace std;

GLUquadricObj *cilindro_ = gluNewQuadric();
vector<Coord3d> normais;
vector<Cilindro> cilindro;

vector<Coord3d> temp_v1;
vector<Coord3d> temp_v2;
vector<Coord3d> temp_v3;
vector<Coord3d> temp_v4;
vector<Coord3d> temp_v5;
vector<Coord3d> temp_v6;
vector<Coord3d> temp_v7;
vector<Coord3d> temp_v8;
vector<Coord3d> temp_v9;
vector<Coord3d> temp_v10;
vector<Coord3d> temp_v11;
vector<Coord3d> temp_v12;
vector<Coord3d> temp_v13;




Mesa::Mesa()
{
}

Mesa::Mesa(GLuint* mesaTextura)
{
	
	this->mesaTextura = *mesaTextura;

}

Mesa::~Mesa()
{
}

void Mesa::lerArquivo(const char *path) {
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
			normais.push_back(normal);
		}
		else if (strcmp(lineHeader, "c") == 0) {
			Cilindro c;
			fscanf(file, "%f %f %f %f %f", &c.baseRadius, &c.topRadius, &c.height,&c.slices,&c.stacks);
			cilindro.push_back(c);
		}
		else if (strcmp(lineHeader, "v1") == 0) {
			Coord3d v1;
			fscanf(file, "%f %f %f", &v1.x, &v1.y, &v1.z);
			temp_v1.push_back(v1);
		}
		else if (strcmp(lineHeader, "v2") == 0) {
			Coord3d v2;
			fscanf(file, "%f %f %f", &v2.x, &v2.y, &v2.z);
			temp_v2.push_back(v2);
		}
		else if (strcmp(lineHeader, "v3") == 0) {
			Coord3d v3;
			fscanf(file, "%f %f %f", &v3.x, &v3.y, &v3.z);
			temp_v3.push_back(v3);
		}
		else if (strcmp(lineHeader, "v4") == 0) {
			Coord3d v4;
			fscanf(file, "%f %f %f", &v4.x, &v4.y, &v4.z);
			temp_v4.push_back(v4);
		}
		else if (strcmp(lineHeader, "v5") == 0) {
			Coord3d v5;
			fscanf(file, "%f %f %f", &v5.x, &v5.y, &v5.z);
			temp_v5.push_back(v5);
		}
		else if (strcmp(lineHeader, "v6") == 0) {
			Coord3d v6;
			fscanf(file, "%f %f %f", &v6.x, &v6.y, &v6.z);
			temp_v6.push_back(v6);
		}
		else if (strcmp(lineHeader, "v7") == 0) {
			Coord3d v7;
			fscanf(file, "%f %f %f", &v7.x, &v7.y, &v7.z);
			temp_v7.push_back(v7);
		}
		else if (strcmp(lineHeader, "v8") == 0) {
			Coord3d v8;
			fscanf(file, "%f %f %f", &v8.x, &v8.y, &v8.z);
			temp_v8.push_back(v8);
		}
		else if (strcmp(lineHeader, "v9") == 0) {
			Coord3d v9;
			fscanf(file, "%f %f %f", &v9.x, &v9.y, &v9.z);
			temp_v9.push_back(v9);
		}
		else if (strcmp(lineHeader, "v10") == 0) {
			Coord3d v10;
			fscanf(file, "%f %f %f", &v10.x, &v10.y, &v10.z);
			temp_v10.push_back(v10);
		}
		else if (strcmp(lineHeader, "v11") == 0) {
			Coord3d v11;
			fscanf(file, "%f %f %f", &v11.x, &v11.y, &v11.z);
			temp_v11.push_back(v11);
		}
		else if (strcmp(lineHeader, "v12") == 0) {
			Coord3d v12;
			fscanf(file, "%f %f %f", &v12.x, &v12.y, &v12.z);
			temp_v12.push_back(v12);
		}
		else if (strcmp(lineHeader, "v13") == 0) {
			Coord3d v13;
			fscanf(file, "%f %f %f", &v13.x, &v13.y, &v13.z);
			temp_v13.push_back(v13);
		}

		
	}
	fclose(file);
}
void Mesa::Display() {
	lerArquivo("modelos//mesa.txt");
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, mesaTextura);
	glRotatef(-90, 1, 0, 0);
	gluCylinder(cilindro_, cilindro[0].baseRadius, cilindro[0].topRadius, cilindro[0].height, cilindro[0].slices, cilindro[0].stacks);
	glPopMatrix();

	glPushMatrix();

	glBegin(GL_QUADS);
	glNormal3f(normais[0].x, normais[0].y, normais[0].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(temp_v1[0].x, temp_v1[0].y, temp_v1[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(temp_v1[1].x, temp_v1[1].y, temp_v1[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(temp_v1[2].x, temp_v1[2].y, temp_v1[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(temp_v1[3].x, temp_v1[3].y, temp_v1[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(normais[1].x, normais[1].y, normais[1].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(temp_v2[0].x, temp_v2[0].y, temp_v2[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(temp_v2[1].x, temp_v2[1].y, temp_v2[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(temp_v2[2].x, temp_v2[2].y, temp_v2[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(temp_v2[3].x, temp_v2[3].y, temp_v2[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(normais[2].x, normais[2].y, normais[2].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(temp_v3[0].x, temp_v3[0].y, temp_v3[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(temp_v3[1].x, temp_v3[1].y, temp_v3[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(temp_v3[2].x, temp_v3[2].y, temp_v3[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(temp_v3[3].x, temp_v3[3].y, temp_v3[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(normais[3].x, normais[3].y, normais[3].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(temp_v4[0].x, temp_v4[0].y, temp_v4[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(temp_v4[1].x, temp_v4[1].y, temp_v4[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(temp_v4[2].x, temp_v4[2].y, temp_v4[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(temp_v4[3].x, temp_v4[3].y, temp_v4[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(normais[4].x, normais[4].y, normais[4].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(temp_v5[0].x, temp_v5[0].y, temp_v5[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(temp_v5[1].x, temp_v5[1].y, temp_v5[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(temp_v5[2].x, temp_v5[2].y, temp_v5[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(temp_v5[3].x, temp_v5[3].y, temp_v5[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(normais[5].x, normais[5].y, normais[5].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(temp_v6[0].x, temp_v6[0].y, temp_v6[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(temp_v6[1].x, temp_v6[1].y, temp_v6[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(temp_v6[2].x, temp_v6[2].y, temp_v6[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(temp_v6[3].x, temp_v6[3].y, temp_v6[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(normais[6].x, normais[6].y, normais[6].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(temp_v7[0].x, temp_v7[0].y, temp_v7[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(temp_v7[1].x, temp_v7[1].y, temp_v7[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(temp_v7[2].x, temp_v7[2].y, temp_v7[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(temp_v7[3].x, temp_v7[3].y, temp_v7[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(normais[7].x, normais[7].y, normais[7].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(temp_v8[0].x, temp_v8[0].y, temp_v8[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(temp_v8[1].x, temp_v8[1].y, temp_v8[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(temp_v8[2].x, temp_v8[2].y, temp_v8[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(temp_v8[3].x, temp_v8[3].y, temp_v8[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(normais[8].x, normais[8].y, normais[8].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(temp_v9[0].x, temp_v9[0].y, temp_v9[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(temp_v9[1].x, temp_v9[1].y, temp_v9[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(temp_v9[2].x, temp_v9[2].y, temp_v9[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(temp_v9[3].x, temp_v9[3].y, temp_v9[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(normais[9].x, normais[9].y, normais[9].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(temp_v10[0].x, temp_v10[0].y, temp_v10[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(temp_v10[1].x, temp_v10[1].y, temp_v10[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(temp_v10[2].x, temp_v10[2].y , temp_v10[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(temp_v10[3].x, temp_v10[3].y, temp_v10[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(normais[10].x, normais[10].y, normais[10].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(temp_v11[0].x, temp_v11[0].y, temp_v11[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(temp_v11[1].x, temp_v11[1].y, temp_v11[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(temp_v11[2].x, temp_v11[2].y, temp_v11[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(temp_v11[3].x, temp_v11[3].y, temp_v11[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(normais[11].x, normais[11].y, normais[11].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(temp_v12[0].x, temp_v12[0].y, temp_v12[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(temp_v12[1].x, temp_v12[1].y, temp_v12[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(temp_v12[2].x, temp_v12[2].y, temp_v12[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(temp_v12[3].x, temp_v12[3].y, temp_v12[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(normais[12].x, normais[12].y, normais[12].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(temp_v13[0].x, temp_v13[0].y, temp_v13[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(temp_v13[1].x, temp_v13[1].y, temp_v13[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(temp_v13[2].x, temp_v13[2].y, temp_v13[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(temp_v13[3].x, temp_v13[3].y, temp_v13[3].z);
	glEnd();

	glPopMatrix();
	
}
