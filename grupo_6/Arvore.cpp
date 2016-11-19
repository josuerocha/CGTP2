
#include "Arvore.h"
#include <iostream>
#include <ctime>
#include <vector>


#define PI 3.14159265
using namespace std;
Arvore::Arvore(Coord3d coord) {


	posiX = coord.x;
	posiY = coord.y;
	posiZ = coord.z;
	dimX = 50;
	dimY = 500;
	dimZ = 50;
	angX = 0;
	angY = 0;
	angZ = 0;
	/*
	galhos.push_back(new Galho(posiX+0*dimX, posiY + 0.90*dimY, posiZ,15,200,0));
	galhos.push_back(new Galho(posiX + 0.25*dimX, posiY + 0.65*dimY, posiZ,20, 200, 180));
	galhos.push_back(new Galho(posiX + 0.30*dimX, posiY + 0.60*dimY, posiZ, 20, 200, 45));
	galhos.push_back(new Galho(posiX + 0.15*dimX, posiY + 0.75*dimY, posiZ, 15, 200, -45));
	galhos.push_back(new Galho(posiX + 0.05*dimX, posiY + 0.85*dimY, posiZ, 15, 200, 135));
	galhos.push_back(new Galho(posiX + 0.20*dimX, posiY + 0.70*dimY, posiZ, 15, 200, -135));
	galhos.push_back(new Galho(posiX + 0.05*dimX, posiY + 0.70*dimY, posiZ, 15, 200, 15));
	galhos.push_back(new Galho(posiX + 0.10*dimX, posiY + 0.80*dimY, posiZ, 15, 200, -85));
	galhos.push_back(new Galho(posiX + 0.10*dimX, posiY + 0.75*dimY, posiZ, 15, 200, 85));
	*/
	for (int a = 1;a < 4;a++) {
		for (int c = a;c < 180;c+=35) {
			galhos.push_back(new Galho(posiX , posiY + (0.5+a*0.15)*dimY, posiZ, 20, 200, c));
			galhos.push_back(new Galho(posiX , posiY + (0.5+a*0.15)*dimY, posiZ, 20, 200, -c));
			//galhos.push_back(new Galho(posiX + (0.5 - a*0.15)*dimX, posiY + (0.45 + a*0.15)*dimY, posiZ, 20, 200, c));
			//galhos.push_back(new Galho(posiX + (0.5 - a*0.15)*dimX, posiY + (0.45 + a*0.15)*dimY, posiZ, 20, 200, -c));
		}
	}

}


void Arvore::desenha() {

	glColor3f(0.36, 0.2, 0.09);
	glPushMatrix();
	glTranslatef(posiX, posiY, posiZ);
	glRotatef(angX, 1, 0, 0);
	glRotatef(angY, 0, 1, 0);
	glRotatef(angZ, 0, 0, 1);

	glPushMatrix();
	glScalef(0.01, 0.01, 0.01);
	
	glPushMatrix();
	glTranslatef(0, 0, 0);//dependendo do angulo que desenha pode ser glTranslatef(-0.25*dimX,0,0);
	glScalef(dimX, 0.5*dimY, dimZ);
	//desenhar um cilindro raio 0.5 e altura 1, base centrada no(0,0,0), paralelo ao eixo X
	GLUquadricObj *obj2 = gluNewQuadric();
	glEnable(GL_TEXTURE_2D);
	//glColor3f(0.5, 0.5, 0.5);
	//glBindTexture(GL_TEXTURE_2D, *corpo);
	gluQuadricNormals(obj2, GLU_SMOOTH);
	gluQuadricTexture(obj2, GL_TRUE);
	glRotatef(-90, 1, 0, 0);
	gluCylinder(obj2, 0.5, 0.5, 1, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.5*dimY, 0);
	glScalef(dimX, dimY, dimZ);//glScalef(0.5*dimX, dimY, 1);
											  //desenhar um circulo raio 0.5, centro(0,0,0)
	GLUquadricObj *obj1 = gluNewQuadric();
	//glColor3f(0.5, 0.5, 0.5);
	//glBindTexture(GL_TEXTURE_2D, texture_id[textura]);
	gluQuadricNormals(obj1, GLU_SMOOTH);
	gluQuadricTexture(obj1, GL_TRUE);
	gluSphere(obj1, 0.5, 20, 20);
	glPopMatrix();

	
	for (int i = 0;i < galhos.size();i++) {
		galhos[i]->desenha();
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