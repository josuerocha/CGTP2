
#include "Folha.h"
#include <iostream>
#include <ctime>


#define PI 3.14159265
using namespace std;
Folha::Folha(float x, float y, float z, float g, float c, float angy2, GLuint* folhasTex) {
	this->folhasTex = folhasTex;
	posiX = x;
	posiY = y;
	posiZ = z;
	grossura = g;
	comprimento = c;
	angX = 0;
	angY = angy2;
	angZ =0;
	angZMax = 40;
	velocidade = 1;
	subindo = true;
}


void Folha::Display() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, *folhasTex);
	glPushMatrix();
	glTranslatef(posiX, posiY, posiZ);
	//glRotatef(angX, 1, 0, 0);
	glRotatef(-45, 0, 0, 1);
	glRotatef(angY, 0, 1, 0);

	glPushMatrix();
	glRotatef(-angZ, 0, 0, 1);
	glTranslatef(0,-0.5*comprimento, 0);
	glScalef(grossura,comprimento, grossura);//glScalef(0.5*dimX, dimY, 1);
											  //desenhar um circulo raio 0.5, centro(0,0,0)
	GLUquadricObj *obj1 = gluNewQuadric();
	//glColor3f(0.5, 0.5, 0.5);
	//glBindTexture(GL_TEXTURE_2D, texture_id[textura]);
	gluQuadricNormals(obj1, GLU_SMOOTH);
	gluQuadricTexture(obj1, GL_TRUE);
	gluSphere(obj1, 0.5, 20, 20);
	glPopMatrix();


	glPopMatrix();

	if (subindo)
		angZ += velocidade;
	else
		angZ -= velocidade;

	if (angZ >= angZMax)
		subindo = false;
	else if (angZ <= 0)
		subindo = true;

	glEnable(GL_TEXTURE_2D);
}


float Folha::getPosiX() { return posiX; }
float Folha::getPosiY() { return posiY; }
float Folha::getPosiZ() { return posiZ; }
float Folha::getAnguloX() { return angX; }
float Folha::getAnguloY() { return angY; }
float Folha::getAnguloZ() { return angZ; }
void Folha::setPosiX(float a) { posiX = a; }
void Folha::setPosiY(float a) { posiY = a; }
void Folha::setPosiZ(float a) { posiZ = a; }
void Folha::setAngX(float a) { angX = a; }
void Folha::setAngY(float a) { angY = a; }
void Folha::setAngZ(float a) { angZ = a; }