
#include "Moinho.h"
#include <iostream>
#include <ctime>


#define PI 3.14159265
using namespace std;
Moinho::Moinho(GLuint* c1,
	GLuint* l1,
	GLuint* f1,
	GLuint* t1,
	GLuint* co,
	GLuint* ei,
	Coord3d coord) {

	posiX= coord.x;
	posiY= coord.y;
	posiZ= coord.z;
	dimX = 6;
	dimY = 10;
	dimZ = 4;
	angX = 0;
	angY = 180;
	angZ = 0;
	velocidade = 0;
	velocAngParabola = 0.5;
	angHelice = 0;
	cima1 = c1;
	lado1 = l1;
	frente1 = f1;
	tras1 = t1;
	corpo = co;
	eixo = ei;


}


void Moinho::Display() {
	GLfloat reflexao[4] = {0.7, 0.2, 0.3, 1.0};
	GLint brilho = 100;

	glPushMatrix();
	glTranslatef(posiX, posiY, posiZ);
	glRotatef(angX, 1, 0, 0);
	glRotatef(angY, 0, 1, 0);
	glRotatef(angZ, 0, 0, 1);


	glPushMatrix();
	glTranslatef(0, 0, 0);
	glScalef(0.5*dimX, dimY, 0.75*dimZ);

	GLUquadricObj *obj2 = gluNewQuadric();

	glMaterialfv(GL_FRONT, GL_AMBIENT, reflexao);
	glMateriali(GL_FRONT, GL_SHININESS, brilho);

	glBindTexture(GL_TEXTURE_2D, *corpo);
	gluQuadricNormals(obj2, GLU_SMOOTH);
	gluQuadricTexture(obj2, GL_TRUE);
	glRotatef(-90, 1, 0, 0);
	gluCylinder(obj2, 0.75, 0.5, 1, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.75*dimY, -0.5*dimZ);
	glScalef(0.25*dimX, 0.25*dimX, 0.15*dimZ);
	
	GLUquadricObj *obj3 = gluNewQuadric();

	glBindTexture(GL_TEXTURE_2D, *eixo);
	gluQuadricNormals(obj3, GLU_SMOOTH);
	gluQuadricTexture(obj3, GL_TRUE);
	//glRotatef(-90, 1, 0, 0);
	gluCylinder(obj3, 0.5, 0.5, 1, 20, 20);
	glPopMatrix();

	desenhaHelice();
	glPopMatrix();

}
void Moinho::desenhaHelice() {

	glPushMatrix();
	glTranslatef(0, 0.75*dimY, -0.45*dimZ);
	glRotatef(angHelice, 0, 0, 1);

	desenhaHeliceParte();
	glRotatef(90, 0, 0, 1);
	desenhaHeliceParte();

	glPopMatrix();
	angHelice += velocAngParabola;
}


void Moinho::desenhaHeliceParte() {

	glPushMatrix();
	//area lateral direita
	//glBindTexture(GL_TEXTURE_2D, texturas[LINHA]);
	glBindTexture(GL_TEXTURE_2D, *lado1);
	glBegin(GL_QUADS);
	glNormal3f(1, 0, 0);
	glTexCoord2f(1.0f, 0.0f);glVertex3f(0.5*dimX, -0.07*dimY, 0.02*dimZ);
	glTexCoord2f(1.0f, 1.0f);glVertex3f(0.5*dimX, 0.07*dimY, 0.02*dimZ);
	glTexCoord2f(0.0f, 1.0f);glVertex3f(0.5*dimX, 0.07*dimY, -0.02*dimZ);
	glTexCoord2f(0.0f, 0.0f);glVertex3f(0.5*dimX, -0.07*dimY, -0.02*dimZ);
	glEnd();

	//area frontal
	
	glBindTexture(GL_TEXTURE_2D, *tras1);
	glBegin(GL_QUADS);
	glNormal3f(0, 0, 1);
	glTexCoord2f(1.0f, 1.0f);glVertex3f(0.5*dimX, 0.07*dimY, 0.02*dimZ);
	glTexCoord2f(1.0f, 0.0f);glVertex3f(0.5*dimX, -0.07*dimY, 0.02*dimZ);
	glTexCoord2f(0.0f, 0.0f);glVertex3f(-0.5*dimX, -0.07*dimY, 0.02*dimZ);
	glTexCoord2f(0.0f, 1.0f);glVertex3f(-0.5*dimX, 0.07*dimY, 0.02*dimZ);
	glEnd();

	//area lateral esquerda

	glBindTexture(GL_TEXTURE_2D, *lado1);
	glBegin(GL_QUADS);
	glNormal3f(-1, 0, 0);
	glTexCoord2f(1.0f, 1.0f);glVertex3f(-0.5*dimX, 0.07*dimY, 0.02*dimZ);
	glTexCoord2f(1.0f, 0.0f);glVertex3f(-0.5*dimX, -0.07*dimY, 0.02*dimZ);
	glTexCoord2f(0.0f, 0.0f);glVertex3f(-0.5*dimX, -0.07*dimY, -0.02*dimZ);
	glTexCoord2f(0.0f, 1.0f);glVertex3f(-0.5*dimX, 0.07*dimY, -0.02*dimZ);
	glEnd();

	//area do tr�s

	glBindTexture(GL_TEXTURE_2D, *frente1);
	glBegin(GL_QUADS);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0.0f, 1.0f);glVertex3f(0.5*dimX, 0.07*dimY, -0.02*dimZ);
	glTexCoord2f(0.0f, 0.0f);glVertex3f(0.5*dimX, -0.07*dimY, -0.02*dimZ);
	glTexCoord2f(1.0f, 0.0f);glVertex3f(-0.5*dimX, -0.07*dimY, -0.02*dimZ);
	glTexCoord2f(1.0f, 1.0f);glVertex3f(-0.5*dimX, 0.07*dimY, -0.02*dimZ);
	glEnd();

	//area de cima

	glBindTexture(GL_TEXTURE_2D, *cima1);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glTexCoord2f(1.0f, 0.0f);glVertex3f(0.5*dimX, 0.07*dimY, 0.02*dimZ);
	glTexCoord2f(0.0f, 0.0f);glVertex3f(-0.5*dimX, 0.07*dimY, 0.02*dimZ);
	glTexCoord2f(0.0f, 1.0f);glVertex3f(-0.5*dimX, 0.07*dimY, -0.02*dimZ);
	glTexCoord2f(1.0f, 1.0f);glVertex3f(0.5*dimX, 0.07*dimY, -0.02*dimZ);
	glEnd();

	//area de baixo

	glBindTexture(GL_TEXTURE_2D, *cima1);
	glBegin(GL_QUADS);
	glNormal3f(0, -1, 0);
	glVertex3f(0.5*dimX, -0.07*dimY, 0.02*dimZ);
	glVertex3f(-0.5*dimX, -0.07*dimY, 0.02*dimZ);
	glVertex3f(-0.5*dimX, -0.07*dimY, -0.02*dimZ);
	glVertex3f(0.5*dimX, -0.07*dimY, -0.02*dimZ);
	glEnd();

	glPopMatrix();

}

float Moinho::getPosiX() { return posiX; }
float Moinho::getPosiY() { return posiY; }
float Moinho::getPosiZ() { return posiZ; }
float Moinho::getAnguloX() { return angX; }
float Moinho::getAnguloY() { return angY; }
float Moinho::getAnguloZ() { return angZ; }
float Moinho::getDimX() { return dimX; }
float Moinho::getDimY() { return dimY; }
float Moinho::getDimZ() { return dimZ; }
void Moinho::setPosiX(float a) { posiX = a; }
void Moinho::setPosiY(float a) { posiY = a; }
void Moinho::setPosiZ(float a) { posiZ = a; }
void Moinho::setAngX(float a) { angX = a; }
void Moinho::setAngY(float a) { angY = a; }
void Moinho::setAngZ(float a) { angZ = a; }
