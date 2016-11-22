
#include "OndaLago.h"
#include <iostream>
#include <ctime>


#define PI 3.14159265
using namespace std;
OndaLago::OndaLago(float x, float y, float z, float dx, float dy, float dz,float tempo2, GLuint* textura) {
	posiX = x;
	posiY = y;
	posiZ = z;
	posiYdescanso = y;
	dimX = dx;
	dimY = dy;
	dimZ = dz;
	velocidade = 0.8;
	subindo = true;
	subiu = false;
	posiYMax = y + 0.4*dimY;
	posiYMin = y - 0.0*dimY;
	tempoEspera = 5;
	tempo = tempo2;

	this->textura = textura;

	brilho = 0;
}


void OndaLago::desenha() {
	bool enableTransparency = false;

	glBindTexture(GL_TEXTURE_2D, *textura);

	glPushMatrix();

	float random = RandomFloat(0, 1);

	if(random > 0.8){
		glEnable(GL_BLEND); 
		glBlendFunc(GL_SRC_ALPHA,GL_SRC_ALPHA);
		enableTransparency = true;
	}
	
	GLfloat componenteReflexao[4] = {0.5,0.5,0.5,1};


	componenteReflexao[3] = (GLfloat) RandomFloat(0,1);
	componenteReflexao[2] = (GLfloat) RandomFloat(0,1);

	brilho += 1;	

	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, componenteReflexao);
	glMateriali(GL_FRONT, GL_SHININESS, brilho);

	if (brilho >= 100){
		brilho = 0;
	}

	glTranslatef(posiX, posiY, posiZ);

	glPushMatrix();
	glScalef(dimX, dimY, dimZ);
											  //desenhar um circulo raio 0.5, centro(0,0,0)
	GLUquadricObj *obj1 = gluNewQuadric();
	gluQuadricNormals(obj1, GLU_SMOOTH);
	gluQuadricTexture(obj1, GL_TRUE);
	gluSphere(obj1, 0.5, 20, 20);
	glPopMatrix();

	glColor3f(1,1,1);
	glPopMatrix();


	if (tempo < tempoEspera) {
		tempo++;
	}else{
		if (subindo) {
			posiY += velocidade;
		}
		else {
			posiY -= velocidade;

		}
		if (posiY >= posiYMax) {
			subindo = false;
			subiu = true;
		}
		else if (posiY <= posiYMin) {
			subindo = true;
		}
		if (subindo && subiu && posiY >= posiYdescanso) {
			subiu = false;
			tempo = 0;
			posiY = posiYdescanso;
		}
	}
	if(enableTransparency){
		glDisable(GL_BLEND);
	}
}

float OndaLago::RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

float OndaLago::getPosiX() { return posiX; }
float OndaLago::getPosiY() { return posiY; }
float OndaLago::getPosiZ() { return posiZ; }
void OndaLago::setPosiX(float a) { posiX = a; }
void OndaLago::setPosiY(float a) { posiY = a; }
void OndaLago::setPosiZ(float a) { posiZ = a; }
