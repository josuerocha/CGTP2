#include "Tela.h"
#include <iostream>
using namespace std;

Tela::Tela()
{	
	//animacaoInicial = AnimacaoInicial();

	//menu = new MainMenu();
	//Inicia cenário com tela inteira
	fullScreen = true;

	speed = 0.01;
	xRotated = yRotated = zRotated = 30.0;
    xRotated=43;
    yRotated=50; 
}

Tela::~Tela(){

}

void Tela::KeyboardDown(unsigned char key, int x, int y) {
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

        case FULLSCREEN:
			if(fullScreen){
       	 		glutFullScreen();
    		}
			else{
				glutReshapeWindow(800, 600);
				glutPositionWindow(270, 80);
			}
            fullScreen = !fullScreen;
        break;

		//esc para sair do jogo
		case EXIT_ENVIRONMENT:
			exit(0);
		break;
	}
	cout << "POSICAO X: " << x << "POSICAO Y: " << y << endl;
}

void Tela::KeyboardUp(unsigned char key, int x, int y) {
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

void Tela::KeyboardSpecialDown(int key, int x, int y){
	cout << "Tecla especial pressionada: " << char(key) << ". Mouse (" << x << ',' << y << ')' << endl;
	switch(key){
		case SHIFT:
			camera.setSpeed(0.05);
		break;
	}
}

void Tela::KeyboardSpecialUp(int key, int x, int y){
	cout << "Tecla especial solta: " << char(key) << ". Mouse (" << x << ',' << y << ')' << endl;
	switch(key){
		case SHIFT:
			camera.setSpeed(0.01);
		break;

	}
}


void Tela::MouseClick(int button, int state, int x, int y) {
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
        
        switch (button){
            case 0:
                keyBuffer[4] = true;
                break;
                
            case 2:
                keyBuffer[5] = true;
                break;

        }

		mouse = Coord2d(worldX, worldY);

		cout << "Mouse click: " << button << ". Posicao (" << mouse.x << ',' << mouse.y << ')' << endl;
	
    }
}

void Tela::MouseMotion(int x, int y) {
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
		mouse = Coord2d(worldX, worldY);
		cout << "Mouse moveu para (" << mouse.x << ',' << mouse.y << ')' << endl;
}


void Tela::Reshape(GLsizei w, GLsizei h)
{	if (h == 0) h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);

	int rate = 1.0f * w / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    glViewport(0, 0, w, h);
	gluPerspective(45.0, rate, 1.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
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

	camera.Update();
	//cout << "TAMANHO TELA " << w << "  " << h << endl;
	//cout<<"CAMERA Y "<<camera.y<<" LOOKAT Y "<<lookAt.y<<endl;
}

void Tela::DrawSphere(){

	glPushMatrix();
    glTranslatef(0.0,0.0,-5.0);
    glColor3f(1, 1, 1); 
    glRotatef(xRotated,1.0,0.0,0.0);
    glRotatef(yRotated,0.0,1.0,0.0);
    glRotatef(zRotated,0.0,0.0,1.0);
    glScalef(1.0,1.0,1.0);
    glutSolidSphere(radius,20,20);
	glPopMatrix();
}

void Tela::ControleTela(){
	//Movimento para frente
	if(keyBuffer[0]){
		camera.MoveForward();
	}
	//Movimento para trás;
	if(keyBuffer[1]){
		camera.MoveBack();
	}
	//Rotaciona camera direita
	if(keyBuffer[2]){
		camera.RotateLeft();
	}
	//Rotaciona camera esquerda
	if(keyBuffer[3]){
		camera.RotateRight();
	}

	camera.Update();
}

void Tela::Display() {
    glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	DrawSphere();


    glutSwapBuffers();
}