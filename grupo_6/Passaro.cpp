#include "Passaro.h"

using namespace std;

Passaro::Passaro(Coord3d coord,Coord2d raioElipse, float speed){
    wingRotation = 45;
    this->coord = coord;
    decreaseRotation = false;
	this->raioVoo = raioElipse;
	this->speed = speed;
	anguloVoo = 0;
}

Passaro::~Passaro(){

}

void Passaro::DrawBeak(){
    glPushMatrix();	
		glTranslated(0,0,0.4);
		glutSolidCone(0.2,0.4,30,30);
	glPopMatrix();
}

void Passaro::DrawHead(){
		glutSolidSphere(0.5,30,30);
}

void Passaro::DrawEyes(){
    glPushMatrix();
		//color eye 1
		glTranslated(0.5,0,0);
		glutSolidSphere(0.1,30,30);
	glPopMatrix();

	glPushMatrix();
		glTranslated(-0.5,0,0);
		glutSolidSphere(0.1,30,30);
	glPopMatrix();

}

void Passaro::DrawBody(){
    glPushMatrix();
        glTranslated(0,0,-1);
        glutSolidSphere(0.9f,30,30);		
	glPopMatrix();
}
void Passaro::DrawWings(){

	if(wingRotation == 45){
        decreaseRotation = true;
    }
    else if(wingRotation == -45){
        decreaseRotation = false;
    }

    if(decreaseRotation){
        wingRotation -=5;
    }
    else{
        wingRotation += 5;
    }

	glRotatef(wingRotation,0,0,1);
    
	//drawing wing 1
	glPushMatrix();		
		glRotatef(180,0,1,0);
		glTranslatef(-0.75f,0.0f,0.75f);
		glBegin(GL_TRIANGLES);
			glVertex3f(0.75f,0.0f,0.75f);
			glVertex3f(1.25f,0.0f,-0.75f);
			glVertex3f(-0.75f,0.0f,0.0f);
		glEnd();		
	glPopMatrix();
		
	//drawing wing 2
	glPushMatrix();
		glTranslatef(-0.75f,0,-0.75f);

		glBegin(GL_TRIANGLES);
			glVertex3f(0.75f,0.0f,0.75f);
			glVertex3f(1.25f,0.0f,-0.75f);
			glVertex3f(-0.75f,0.0f,0.0f);
		glEnd();		
	glPopMatrix();
}

void Passaro::Display(){
    glPushMatrix();
        glTranslatef(coord.x,coord.y,coord.z);
		glRotatef(anguloVoo,0,0,1); //Rotaciona passaro enquanto voa
        DrawHead();
        DrawBody();
        DrawBeak();
        DrawEyes();
        DrawWings();
    glPopMatrix();

	Fly();
}

void Passaro::Fly(){
	Coord2d proximaPosicao = FuncoesExtra::ElipsePoints(raioVoo.x,raioVoo.y, anguloVoo);

	coord.x	= proximaPosicao.x;
	coord.z	= proximaPosicao.y;

	anguloVoo += speed;

	if(anguloVoo >= 360){ anguloVoo = 0; }
}