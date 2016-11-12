#include "Tela.h"
#include <iostream>
using namespace std;




void Tela::keyboardDown(unsigned char key, int x, int y) {
	cout << "Tecla regular pressionada: " << char(key) << ". Mouse (" << x << ',' << y << ')' << endl;

	switch (key) {
        case FORWARD:
            keyBuffer[0] = true;
        break;

        case BACKWARD:
            keyBuffer[1] = true;
        break;

        case RIGHT:
            keyBuffer[2] = true;
        break;

        case LEFT:
            keyBuffer[3] = true;
        break;
	}
	cout << "POSICAO X: " << x << "POSICAO Y: " << y << endl;
}

void Tela::keyboardUp(unsigned char key, int x, int y) {
	cout << "Tecla regular solta: " << char(key) << ". Mouse (" << x << ',' << y << ')' << endl;
	switch (key) {
	case FORWARD:
		keyBuffer[0] = false;
		break;
	case BACKWARD:
		keyBuffer[1] = false;
		break;
	case RIGHT:
		keyBuffer[2] = false;
		break;
	case LEFT:
		keyBuffer[3] = false;
		break;
	}
}

void Tela::mouseClick(int button, int state, int x, int y) {

	if (state == GLUT_DOWN) {
		GLint viewport[4]; //var to hold the viewport info
		GLdouble modelview[16]; //var to hold the modelview info
		GLdouble projection[16]; //var to hold the projection matrix info
		GLfloat winX, winY, winZ; //variables to hold screen x,y,z coordinates
		GLdouble worldX, worldY, worldZ; //variables to hold world x,y,z coordinates

		glGetDoublev(GL_MODELVIEW_MATRIX, modelview); //get the modelview info
		glGetDoublev(GL_PROJECTION_MATRIX, projection); //get the projection matrix info
		glGetIntegerv(GL_VIEWPORT, viewport); //get the viewport info

		winX = (float)x;
		winY = (float)viewport[3] - (float)y;
		winZ = 0;

		//get the world coordinates from the screen coordinates
		gluUnProject(winX, winY, winZ, modelview, projection, viewport, &worldX, &worldY, &worldZ);

		if (button == 0) {this->shoot = 1; keyBuffer[4] = true;}
		else if (button == 2) { this->shoot = 2; keyBuffer[5] = true;}
		mouse = (Coord(worldX, worldY));
		if (menu->emMenuPrincipal) {
			menu->clickAtivo = true;
			menu->mouse = mouse;
		}
		cout << "Mouse click: " << button << ". Posicao (" << mouse.x << ',' << mouse.y << ')' << endl;
	}
	else
	{
		keyBuffer[4] = false;
		shoot = 0 ;
	}
}

void Tela::AlteraTamanhoJanela(GLsizei w, GLsizei h)
{	if (h == 0) h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de sele��o (left, right, bottom, top)
	if (w <= h){
		gluOrtho2D(0.0f, 800.0f, 0.0f, 600.0f*h / w);
		janela.height = 600 * h / w;
	}
	else{
		gluOrtho2D(0.0f, 800.0f*w / h, 0.0f, 600.0f);
		janela.width = 800 * w / h;
	}
	cout << "TAMANHO TELA " << w << "  " << h;
}


void Tela::Display() {


}