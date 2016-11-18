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
		glTranslated(0,0,1);
		glutSolidCone(0.4,0.5,30,30);
	glPopMatrix();
}

void Passaro::DrawHead(){
		glutSolidSphere(0.5,30,30);
}

void Passaro::DrawEyes(){
    glPushMatrix();
		glColor3ub(0,0,0);
		glTranslated(1,0,0);
		glutSolidSphere(0.2,30,30);
	glPopMatrix();
	glPushMatrix();
		glColor3ub(0,0,0);
		glTranslated(-1,0,0);
		glutSolidSphere(0.2,30,30);
	glPopMatrix();

}

void Passaro::DrawBody(){
    glPushMatrix();
        glTranslated(0,0,-2.5);
        glutSolidSphere(2,30,30);		
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

	glPushMatrix();		
		glRotatef(90,0,1,0);
		glRotatef(90,0,1,0);
		glTranslatef(-2,0,2.5);
		glBegin(GL_TRIANGLES);
			glVertex3f(2,0,2);
			glVertex3f(2,0,-2);
			glVertex3f(-2,0,0);
		glEnd();		
	glPopMatrix();
		
	glPushMatrix();
		glColor3ub(139,69,19);
		glRotatef(90,0,1,0);
		glRotatef(-90,0,1,0);
		glTranslatef(-2,0,-2.5);

		glBegin(GL_TRIANGLES);
			glVertex3f(2,0,2);
			glVertex3f(2,0,-2);
			glVertex3f(-2,0,0);
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