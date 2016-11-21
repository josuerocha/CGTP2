#include "Luz.h"

using namespace std;
Luz::Luz(Camera* camera){

    this->camera = camera;
 	//Luz ambiente
	/*GLfloat posicaoLuzAmbiente[4] = {0.0, 20.0, 0.0, 1.0};
	GLfloat luzAmbiente[4] = {0.2, 0.2, 0.2, 1.0};          
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);                   
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);                         
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuzAmbiente);*/

	//Luz difusa e especular em cima da camera
	GLfloat posicaocamera[4] = {camera->getCoord_ptr()->x,camera->getCoord_ptr()->y,camera->getCoord_ptr()->z,1.0};
	GLfloat luzMovel[4]={0.1f,0.1f,0.1f,1.0};
    colorMovingLight = Cor(0.1f,0.1f,0.1f,1.0);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, luzMovel);
	glLightfv(GL_LIGHT1, GL_EMISSION, luzMovel);
	glLightfv(GL_LIGHT1, GL_SPECULAR, luzMovel);
	glLightfv(GL_LIGHT1, GL_POSITION, posicaocamera);

	//Luz na posicao fixa 1
	GLfloat luzFixa1[4] = {0.2f, 0.2f, 1.0f, 1.0f};
	GLfloat posicaoLuzFixa1[4] = {0.0f, 1.0f, 20.0f, 1.0f};
	glLightfv(GL_LIGHT2, GL_DIFFUSE, luzFixa1);
	glLightfv(GL_LIGHT2, GL_SPECULAR, luzFixa1);
	glLightfv(GL_LIGHT2, GL_POSITION, posicaoLuzFixa1);

	//Luz na posicao fixa 2
	GLfloat luzFixa2[4] = {1.0f, 0.2f, 0.2f, 1.0f};
	GLfloat posicaoLuzFixa2[4] = {0.0f, 1.0f, -20.0f, 1.0f};
	glLightfv(GL_LIGHT3, GL_DIFFUSE, luzFixa2);
	glLightfv(GL_LIGHT3, GL_SPECULAR, luzFixa2);
	glLightfv(GL_LIGHT3, GL_POSITION, posicaoLuzFixa2);
               						   
	glEnable(GL_LIGHT0);												   
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);

    movingLightFlag = true;
    fixedLightFlag = true;

}

Luz::~Luz(){

}

void Luz::IncrementMovingLight(){
    
    if((colorMovingLight.r + 0.1f) >= 0 && (colorMovingLight.r + 0.1f) <= 2.1){
        colorMovingLight.r += 0.1; colorMovingLight.g += 0.1; colorMovingLight.b += 0.1;
        GLfloat luzMovel[4] = {colorMovingLight.r, colorMovingLight.g, colorMovingLight.b, colorMovingLight.a};
        glLightfv(GL_LIGHT1, GL_DIFFUSE, luzMovel);
	    glLightfv(GL_LIGHT1, GL_SPECULAR, luzMovel);        
    }
}

void Luz::DecrementMovingLight(){

    if((colorMovingLight.r - 0.1f) >= 0 && (colorMovingLight.r - 0.1f) <= 2.1){
        colorMovingLight.r -= 0.1; colorMovingLight.g -= 0.1; colorMovingLight.b -= 0.1;
        GLfloat luzMovel[4] = {colorMovingLight.r, colorMovingLight.g, colorMovingLight.b, colorMovingLight.a};
        glLightfv(GL_LIGHT1, GL_DIFFUSE, luzMovel);
	    glLightfv(GL_LIGHT1, GL_SPECULAR, luzMovel);        
    }
}


void Luz::SwitchMovingLight(){
    if(movingLightFlag) {   glDisable(GL_LIGHT1); }
    else {  glEnable(GL_LIGHT1); }
    movingLightFlag = !movingLightFlag;
}

void Luz::SwitchFixedLights(){

    if(fixedLightFlag) {  
        glDisable(GL_LIGHT2);
		glDisable(GL_LIGHT3);  
        cout<<"DISABLING"<<endl;
    }
    else {  
        glEnable(GL_LIGHT2);
		glEnable(GL_LIGHT3); 
        cout<<"ENABLING"<<endl;
    }
    fixedLightFlag = !fixedLightFlag;
}
