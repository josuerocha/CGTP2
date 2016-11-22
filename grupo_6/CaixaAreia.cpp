#include "CaixaAreia.h"

#include <iostream>
#include <string>
#include <vector>

#include "Estruturas.h"

using namespace std;

GLUquadricObj *bola = gluNewQuadric();
GLUquadricObj *balde = gluNewQuadric();

vector<Cilindro> ca_temp_ba;
vector<Coord3d> ca_normais;
vector<Coord3d> ca_temp_v1;
vector<Coord3d> ca_temp_v2;
vector<Coord3d> ca_temp_v3;
vector<Coord3d> ca_temp_v4;
vector<Coord3d> ca_temp_v5;
vector<Coord3d> ca_temp_v6;
vector<Coord3d> ca_temp_v7;
vector<Coord3d> ca_temp_bola;


CaixaAreia::CaixaAreia()
{
}

CaixaAreia::CaixaAreia(GLuint* topoTextura, GLuint* baseTextura, GLuint* baldeTextura, GLuint* bolaTextura)
{
	this->topoTextura = *topoTextura;
	this->baseTextura = *baseTextura;
	this->baldeTextura = *baldeTextura;
	this->bolaTextura = *bolaTextura;

	lerArquivo("modelos//caixadeareia.txt");
}

CaixaAreia::~CaixaAreia()
{
}

void CaixaAreia::lerArquivo(const char *path) {
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
			ca_normais.push_back(normal);
		}
		else if (strcmp(lineHeader, "b") == 0) {
			Coord3d c;
			fscanf(file, "%f %f %f", &c.x, &c.y, &c.z);
			ca_temp_bola.push_back(c);
		}
		else if (strcmp(lineHeader, "c") == 0) {
			Cilindro b;
			fscanf(file, "%f %f %f %f %f", &b.baseRadius, &b.topRadius, &b.height,&b.slices,&b.stacks);
			ca_temp_ba.push_back(b);
		}
		else if (strcmp(lineHeader, "v1") == 0) {
			Coord3d v1;
			fscanf(file, "%f %f %f", &v1.x, &v1.y, &v1.z);
			ca_temp_v1.push_back(v1);
		}
		else if (strcmp(lineHeader, "v2") == 0) {
			Coord3d v2;
			fscanf(file, "%f %f %f", &v2.x, &v2.y, &v2.z);
			ca_temp_v2.push_back(v2);
		}
		else if (strcmp(lineHeader, "v3") == 0) {
			Coord3d v3;
			fscanf(file, "%f %f %f", &v3.x, &v3.y, &v3.z);
			ca_temp_v3.push_back(v3);
		}
		else if (strcmp(lineHeader, "v4") == 0) {
			Coord3d v4;
			fscanf(file, "%f %f %f", &v4.x, &v4.y, &v4.z);
			ca_temp_v4.push_back(v4);
		}
		else if (strcmp(lineHeader, "v5") == 0) {
			Coord3d v5;
			fscanf(file, "%f %f %f", &v5.x, &v5.y, &v5.z);
			ca_temp_v5.push_back(v5);
		}
		else if (strcmp(lineHeader, "v6") == 0) {
			Coord3d v6;
			fscanf(file, "%f %f %f", &v6.x, &v6.y, &v6.z);
			ca_temp_v6.push_back(v6);
		}
		else if (strcmp(lineHeader, "v7") == 0) {
			Coord3d v7;
			fscanf(file, "%f %f %f", &v7.x, &v7.y, &v7.z);
			ca_temp_v7.push_back(v7);
		}

	}
	fclose(file);
}
void CaixaAreia::DisplayTopo() {
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, topoTextura);
	glTranslatef(70,1,0);

	glBegin(GL_QUADS);
	glNormal3f(ca_normais[6].x, ca_normais[6].y, ca_normais[6].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(ca_temp_v7[0].x, ca_temp_v7[0].y, ca_temp_v7[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(ca_temp_v7[1].x, ca_temp_v7[1].y, ca_temp_v7[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(ca_temp_v7[2].x, ca_temp_v7[2].y, ca_temp_v7[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(ca_temp_v7[3].x, ca_temp_v7[3].y, ca_temp_v7[3].z);
	glEnd();
	glPopMatrix();
}
void CaixaAreia::DisplayBase() {
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, baseTextura);
	glTranslatef(70, 1, 0);

	glBegin(GL_QUADS);
	glNormal3f(ca_normais[0].x, ca_normais[0].y, ca_normais[0].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(ca_temp_v1[0].x, ca_temp_v1[0].y, ca_temp_v1[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(ca_temp_v1[1].x, ca_temp_v1[1].y, ca_temp_v1[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(ca_temp_v1[2].x, ca_temp_v1[2].y, ca_temp_v1[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(ca_temp_v1[3].x, ca_temp_v1[3].y, ca_temp_v1[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(ca_normais[1].x, ca_normais[1].y, ca_normais[1].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(ca_temp_v2[0].x, ca_temp_v2[0].y, ca_temp_v2[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(ca_temp_v2[1].x, ca_temp_v2[1].y, ca_temp_v2[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(ca_temp_v2[2].x, ca_temp_v2[2].y, ca_temp_v2[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(ca_temp_v2[3].x, ca_temp_v2[3].y, ca_temp_v2[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(ca_normais[2].x, ca_normais[2].y, ca_normais[2].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(ca_temp_v3[0].x, ca_temp_v3[0].y, ca_temp_v3[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(ca_temp_v3[1].x, ca_temp_v3[1].y, ca_temp_v3[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(ca_temp_v3[2].x, ca_temp_v3[2].y, ca_temp_v3[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(ca_temp_v3[3].x, ca_temp_v3[3].y, ca_temp_v3[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(ca_normais[3].x, ca_normais[3].y, ca_normais[3].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(ca_temp_v4[0].x, ca_temp_v4[0].y, ca_temp_v4[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(ca_temp_v4[1].x, ca_temp_v4[1].y, ca_temp_v4[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(ca_temp_v4[2].x, ca_temp_v4[2].y, ca_temp_v4[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(ca_temp_v4[3].x, ca_temp_v4[3].y, ca_temp_v4[3].z);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(ca_normais[4].x, ca_normais[4].y, ca_normais[4].z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(ca_temp_v5[0].x, ca_temp_v5[0].y, ca_temp_v5[0].z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(ca_temp_v5[1].x, ca_temp_v5[1].y, ca_temp_v5[1].z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(ca_temp_v5[2].x, ca_temp_v5[2].y, ca_temp_v5[2].z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(ca_temp_v5[3].x, ca_temp_v5[3].y, ca_temp_v5[3].z);
	glEnd();

	glPopMatrix();

}
void CaixaAreia::DisplayBola() {
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, bolaTextura);
	glTranslatef(71.0f, 3.0f, 3.0f);
	gluSphere(bola, ca_temp_bola[0].x, ca_temp_bola[0].y, ca_temp_bola[0].z);
	glPopMatrix();
}

void CaixaAreia::DisplayBalde() {
	glPushMatrix();

	glBindTexture(GL_TEXTURE_2D, baldeTextura);
	glRotatef(-90, 1, 0, 0);
	glTranslatef(70.0f, 0.0f, 2.1f);
	gluCylinder(balde, ca_temp_ba[0].baseRadius, ca_temp_ba[0].topRadius, ca_temp_ba[0].height, ca_temp_ba[0].slices, ca_temp_ba[0].stacks);
	glPopMatrix();
	/*();
	
	glPopMatrix();*/
	
	//glTranslatef(71.8f, 3.0f, 0.4f);
	
	glPopMatrix();
}

void CaixaAreia::Display() {
	gluQuadricNormals(bola, GLU_SMOOTH);
	gluQuadricTexture(bola, GLU_TRUE);
	gluQuadricNormals(balde, GLU_SMOOTH);
	gluQuadricTexture(balde, GLU_TRUE);
	DisplayBase();
	DisplayTopo();
	DisplayBalde();
	DisplayBola();
}