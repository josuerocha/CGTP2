#include "Passaro.h"

Passaro::Passaro(){

}

Passaro::~Passaro(){

}

void Passaro::DrawBeak(){
    glPushMatrix();	
		glTranslated(0,0,1);
		glutSolidCone(0.4,0.5,50,200);
	glPopMatrix();
}

void Passaro::DrawHead(){
		glutSolidSphere(1,50,200);
}

void Passaro::DrawEyes(){
    glPushMatrix();
		glColor3ub(0,0,0);
		glTranslated(1,0,0);
		glutSolidSphere(0.2,50,200);
	glPopMatrix();
	glPushMatrix();
		glColor3ub(0,0,0);
		glTranslated(-1,0,0);
		glutSolidSphere(0.2,50,200);
	glPopMatrix();

}

void Passaro::DrawBody(){
    glPushMatrix();
        glTranslated(0,0,-2.5);
        glutSolidSphere(2,50,200);		
	glPopMatrix();
}
void Passaro::DrawWings(){
	if(asa1==45)
		asa1=40;
	else if(asa1==40)
		asa1=35;
	else if(asa1==35)
		asa1 = 25;
	else if(asa1 == 25)
		asa1 = 15;
	else if(asa1 == 15)
		asa1 = 5;
	else if(asa1 == 5)
		asa1 = 0;
	else if(asa1 == 0)
		asa1 = -15;
	else if(asa1 == -15)
		asa1 = -25;
	else if(asa1 == -25)
		asa1 = -35;
	else if(asa1 == -35)
		asa1 = -40;
	else
		asa1 = 45;
	glRotatef(asa1,0,0,1);

	glPushMatrix();
		glColor3ub(139,69,19);		
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
    DrawHead();
    DrawBody();
    DrawBeak();
    DrawEyes();
    DrawWings();
}