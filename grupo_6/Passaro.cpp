#include "Passaro.h"

Passaro::Passaro(Coord3d coord){
    wingRotation = 45;
    this->coord = coord;
    decreaseRotation = false;
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
        DrawHead();
        DrawBody();
        DrawBeak();
        DrawEyes();
        DrawWings();
    glPopMatrix();
}