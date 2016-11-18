#include "PlanoChao.h"

#include <iostream>
#include <string>


using namespace std;

PlanoChao::PlanoChao()
{
   
    
}

PlanoChao::~PlanoChao()
{
}

void PlanoChao::Load(){
     this->chaoTextura = FuncoesExtra::LoadTexture("files/grass.jpg");
}

void PlanoChao::Display(){
    glBindTexture(GL_TEXTURE_2D, chaoTextura);
	glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-40.0f, 0.1f, 59.5f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-40.0f, 0.1f,60.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(40.0f, 0.1f, 60.5f);
	glEnd();
}


