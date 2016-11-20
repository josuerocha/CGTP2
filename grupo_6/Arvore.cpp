
#include "Arvore.h"
#include <iostream>
#include <ctime>
#include <vector>


#define PI 3.14159265
using namespace std;
Arvore::Arvore(Coord3d coord,GLuint* folhasTex, GLuint* troncoTex) {

	this->folhasTex = folhasTex;
	this->troncoTex = troncoTex;

	posiX = coord.x;
	posiY = coord.y;
	posiZ = coord.z;
	dimX = 50;
	dimY = 500;
	dimZ = 50;
	angX = 0;
	angY = 0;
	angZ = 0;

	for (int a = 1;a < 4;a++) {
		for (int c = a;c < 180;c+=35) {
			galhos.push_back(new Galho(posiX , posiY + (0.5+a*0.15)*dimY, posiZ, 20, 200, c,folhasTex,troncoTex));
			galhos.push_back(new Galho(posiX , posiY + (0.5+a*0.15)*dimY, posiZ, 20, 200, -c,folhasTex,troncoTex));
		}
	}
}

void Arvore::Display() {

	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, ambiente);
	glMateriali(GL_FRONT, GL_SHININESS, brilho);

	ambiente[0] = 0.0;
	ambiente[1] = 0.5;
	ambiente[2] = 0.5;
	ambiente[3] = 1;

	glPushMatrix();
	glTranslatef(posiX, posiY, posiZ);
	glRotatef(angX, 1, 0, 0);
	glRotatef(angY, 0, 1, 0);
	glRotatef(angZ, 0, 0, 1);

	brilho = 100;

	glPushMatrix();
	glScalef(0.05, 0.05, 0.05);
	
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glScalef(dimX, 0.5*dimY, dimZ);
	
	glBindTexture(GL_TEXTURE_2D, *troncoTex);

	GLUquadricObj *obj2 = gluNewQuadric();

	gluQuadricNormals(obj2, GLU_SMOOTH);
	gluQuadricTexture(obj2, GL_TRUE);
	glRotatef(-90, 1, 0, 0);
	gluCylinder(obj2, 0.5, 0.5, 2, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.5*dimY, 0);
	glScalef(dimX, dimY, dimZ);//glScalef(0.5*dimX, dimY, 1);
											  //desenhar um circulo raio 0.5, centro(0,0,0)
	GLUquadricObj *obj1 = gluNewQuadric();

	GLUquadricObj *quad;
	quad = gluNewQuadric();
	gluQuadricNormals(quad, GLU_SMOOTH);
	gluQuadricTexture(quad, GL_TRUE);
	gluCylinder( quad, 0.05, 0.05, 4.0, 10.0, 10.0);

	gluQuadricNormals(obj1, GLU_SMOOTH);
	gluQuadricTexture(obj1, GL_TRUE);
	gluSphere(obj1, 0.5, 20, 20);
	glPopMatrix();

	for (unsigned int i = 0;i < galhos.size();i++) {
		galhos[i]->Display();
	}
	glPopMatrix();
	glPopMatrix();
}


float Arvore::getPosiX() { return posiX; }
float Arvore::getPosiY() { return posiY; }
float Arvore::getPosiZ() { return posiZ; }
float Arvore::getAnguloX() { return angX; }
float Arvore::getAnguloY() { return angY; }
float Arvore::getAnguloZ() { return angZ; }
float Arvore::getDimX() { return dimX; }
float Arvore::getDimY() { return dimY; }
float Arvore::getDimZ() { return dimZ; }
void Arvore::setPosiX(float a) { posiX = a; }
void Arvore::setPosiY(float a) { posiY = a; }
void Arvore::setPosiZ(float a) { posiZ = a; }
void Arvore::setAngX(float a) { angX = a; }
void Arvore::setAngY(float a) { angY = a; }
void Arvore::setAngZ(float a) { angZ = a; }