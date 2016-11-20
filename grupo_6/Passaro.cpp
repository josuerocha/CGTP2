#include "Passaro.h"

using namespace std;

Passaro::Passaro(Coord3d coord,Coord2d raioElipse, float speed, GLuint* texturaCorpo,GLuint* texturaOlho){
    wingRotation = 45;
    this->coord = coord;
    decreaseRotation = false;
	this->raioVoo = raioElipse;
	this->speed = speed;
	anguloVoo = 0;

	this->texturaCorpo = texturaCorpo;
	this->texturaOlho = texturaOlho;
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
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, *texturaCorpo);
		
		GLUquadricObj *obj = gluNewQuadric();
		gluQuadricNormals(obj, GLU_SMOOTH);
		gluQuadricTexture(obj, GL_TRUE);
		
		gluSphere(obj,0.5,30,30);

		glDisable(GL_TEXTURE_2D);
}

void Passaro::DrawEyes(){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, *texturaOlho);

	GLUquadricObj *obj = gluNewQuadric();
	gluQuadricNormals(obj, GLU_SMOOTH);
	gluQuadricTexture(obj, GL_TRUE);

    glPushMatrix();
		//color eye 1
		glTranslated(0.5,0,0);
		gluSphere(obj,0.1,30,30);
	glPopMatrix();

	glPushMatrix();
		glTranslated(-0.5,0,0);
		gluSphere(obj,0.1,30,30);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}

void Passaro::DrawBody(){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, *texturaCorpo);
    
	GLUquadricObj *obj = gluNewQuadric();
	gluQuadricNormals(obj, GLU_SMOOTH);
	gluQuadricTexture(obj, GL_TRUE);

	glPushMatrix();
        glTranslated(0,0,-1);
        gluSphere(obj,0.8f,30,30);		
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
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

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, *texturaCorpo);

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

	glDisable(GL_TEXTURE_2D);
}

void Passaro::Display(){
    glPushMatrix();
        glTranslatef(coord.x,coord.y,coord.z);
		glScalef(0.5,0.5,0.5);
		glRotatef(-anguloVoo,0,1,0); //Rotaciona passaro enquanto voa
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

void Passaro::LerArquivo() {
	int posicao = 0;
	vector <Coord3d> out_vertices;
	vector <float> out_uvs;
	vector <float> out_normals;

	vector <unsigned int> vertexIndices, uvIndices, normalIndices;


	const char * path = "passaro.txt";

	FILE * file = fopen(path, "r");
	if (file == NULL) {
		printf("Impossible to open the file !\n");
		//return false;
	}

	while (1) {
		char lineHeader[128];
		// read the first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break; // EOF = End Of File. Quit the loop.

				   // else : parse lineHeader
		if (strcmp(lineHeader, "vn") == 0) {
			Coord3d normal;
			fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z, &normal);
			temp_normais.push_back(normal);
		}
		else if (strcmp(lineHeader, "v1") == 0) {
				Coord3d v1;
				fscanf(file, "%f %f %f", &v1.x, &v1.y, &v1.z);
				temp_v1.push_back(v1);
		}
		else if (strcmp(lineHeader, "v2") == 0) {
			Coord3d v2;
			fscanf(file, "%f %f %f", &v2.x, &v2.y, &v2.z);
			temp_v2.push_back(v2);
		}
		else if (strcmp(lineHeader, "v3") == 0) {
			Coord3d v3;
			fscanf(file, "%f %f %f", &v3.x, &v3.y, &v3.z);
			temp_v3.push_back(v3);
		}
		else if (strcmp(lineHeader, "v4") == 0) {
			Coord3d v4;
			fscanf(file, "%f %f %f", &v4.x, &v4.y, &v4.z);
			temp_v4.push_back(v4);
		}
		else if (strcmp(lineHeader, "v5") == 0) {
			Coord3d v5;
			fscanf(file, "%f %f %f", &v5.x, &v5.y, &v5.z);
			temp_v5.push_back(v5);
		}
		else if (strcmp(lineHeader, "v6") == 0) {
			Coord3d v6;
			fscanf(file, "%f %f %f", &v6.x, &v6.y, &v6.z);
			temp_v6.push_back(v6);
		}
		else if (strcmp(lineHeader, "v7") == 0) {
			Coord3d v7;
			fscanf(file, "%f %f %f", &v7.x, &v7.y, &v7.z);
			temp_v7.push_back(v7);
		}
		/*else if (strcmp(lineHeader, "de") == 0) {
			vertex vetor;
			fscanf(file, "%f %f %f\n", &vetor.x, &vetor.y, &vetor.z);
			temp_vetores.push_back(vetor);
		}
		else if (strcmp(lineHeader, "dbo") == 0) {
			vertex vetor;
			fscanf(file, "%f %f %f\n", &vetor.x, &vetor.y, &vetor.z);
			temp_qualuqercoisa.push_back(vetor);
		}*/

	}
}