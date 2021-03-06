#include "PlanoChao.h"

#include <iostream>
#include <string>


using namespace std;

PlanoChao::PlanoChao()
{
  
}

PlanoChao::PlanoChao(GLuint* chaoTextura)
{
   this->chaoTextura = *chaoTextura;
}

PlanoChao::~PlanoChao()
{
}

void PlanoChao::Display(){

    glBindTexture(GL_TEXTURE_2D, chaoTextura);
	glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-140.0f, 0.0f, 140.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-140.0f, 0.0f, -140.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(140.0f, 0.0f,-140.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(140.0f, 0.0f, 140.0f);
	glEnd();

}