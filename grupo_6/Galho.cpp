
#include "Galho.h"
#include <iostream>
#include <ctime>


#define PI 3.14159265
using namespace std;
Galho::Galho(float x, float y, float z, float g, float c, float angy2,GLuint* folhasTex, GLuint* troncoTex) {

	this->troncoTex = troncoTex;
	posiX = x;
	posiY = y;
	posiZ = z;
	grossura = g;
	comprimento = c;
	angX = 0;
	angY = angy2;
	angZ = 45;

	folhas.push_back(new Folha(comprimento, 0, 0,20,40,-angY,folhasTex));
	folhas.push_back(new Folha(0.9*comprimento, -0.05*grossura, 0, 20, 40, -angY,folhasTex));
	folhas.push_back(new Folha(0.8*comprimento, -0.1*grossura, 0, 20, 40, -angY,folhasTex));
	folhas.push_back(new Folha(0.7*comprimento, -0.15*grossura, 0, 20, 40, -angY,folhasTex));
	folhas.push_back(new Folha(0.6*comprimento, -0.2*grossura, 0, 20, 40, -angY,folhasTex));
	folhas.push_back(new Folha(0.5*comprimento, -0.25*grossura, 0, 20, 40, -angY,folhasTex));
	folhas.push_back(new Folha(0.4*comprimento, -0.2*grossura, 0, 20, 40, -angY,folhasTex));
	folhas.push_back(new Folha(0.3*comprimento, -0.15*grossura, 0, 20, 40, -angY,folhasTex));
}


void Galho::Display() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, *troncoTex);

	glPushMatrix();
	glTranslatef(posiX, posiY, posiZ);
	glRotatef(angX, 1, 0, 0);
	glRotatef(angY, 0, 1, 0);
	glRotatef(angZ, 0, 0, 1);
	
	glPushMatrix();
	glTranslatef(0.5*comprimento, 0, 0);
	glScalef(comprimento, grossura, grossura);//glScalef(0.5*dimX, dimY, 1);
										 //desenhar um circulo raio 0.5, centro(0,0,0)
	GLUquadricObj *obj1 = gluNewQuadric();
	//glColor3f(0.5, 0.5, 0.5);
	//glBindTexture(GL_TEXTURE_2D, texture_id[textura]);
	gluQuadricNormals(obj1, GLU_SMOOTH);
	gluQuadricTexture(obj1, GL_TRUE);
	gluSphere(obj1, 0.5, 20, 20);
	glPopMatrix();

	for (uint i = 0;i < folhas.size();i++) {
		folhas[i]->Display();
	}
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}


float Galho::getPosiX() { return posiX; }
float Galho::getPosiY() { return posiY; }
float Galho::getPosiZ() { return posiZ; }
float Galho::getAnguloX() { return angX; }
float Galho::getAnguloY() { return angY; }
float Galho::getAnguloZ() { return angZ; }
void Galho::setPosiX(float a) { posiX = a; }
void Galho::setPosiY(float a) { posiY = a; }
void Galho::setPosiZ(float a) { posiZ = a; }
void Galho::setAngX(float a) { angX = a; }
void Galho::setAngY(float a) { angY = a; }
void Galho::setAngZ(float a) { angZ = a; }