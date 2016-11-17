#include "EsferaMundo.h"

#include <iostream>
#include <string>


using namespace std;

EsferaMundo::EsferaMundo()
{
   
    pSphere = gluNewQuadric();
    gluQuadricDrawStyle(pSphere, GLU_FILL);
    gluQuadricNormals(pSphere, GLU_SMOOTH);
    gluQuadricTexture(pSphere, GLU_TRUE);

    //Rotação esfera
    
    xRotated=43;
    yRotated=50; 
    zRotated = 30.0;
}

EsferaMundo::~EsferaMundo()
{
}

void EsferaMundo::Load(){
     this->ceuTextura = FuncoesExtra::LoadTexture("files/ceu.jpg");
}

void EsferaMundo::Display(){
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,ceuTextura);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTranslatef(0.0,0.0,-5.0);
    glRotatef(xRotated,1.0,0.0,0.0);
    glRotatef(yRotated,0.0,1.0,0.0);
    glRotatef(zRotated,0.0,0.0,1.0);
    glScalef(1.0,1.0,1.0);
    
	gluSphere(pSphere, 20, 18, 18);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}


