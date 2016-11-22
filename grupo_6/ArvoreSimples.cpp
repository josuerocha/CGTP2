#include "ArvoreSimples.h"

using namespace std;

ArvoreSimples::ArvoreSimples(Coord3d coord,GLuint* copaTex,GLuint* troncoTex){
    this->copaTex = copaTex;
    this->troncoTex = troncoTex;

    this->coord = coord;

    ReadFile("modelos//arvoresimples.txt");
}

ArvoreSimples::~ArvoreSimples(){
    
}


void ArvoreSimples::Display(){
    GLfloat reflexao[4] = {0.7, 0.2, 0.3, 1.0};
	GLint brilho = 100;

	glMaterialfv(GL_FRONT, GL_AMBIENT, reflexao);
	glMateriali(GL_FRONT, GL_SHININESS, brilho);

    glPushMatrix();

    DrawTrunk();
    DrawCopa();

    glPopMatrix();
}

void ArvoreSimples::DrawTrunk(){
        GLUquadricObj *obj1 = gluNewQuadric();
        glBindTexture(GL_TEXTURE_2D, *troncoTex);
        gluQuadricNormals(obj1, GLU_SMOOTH);
        gluQuadricTexture(obj1, GL_TRUE);
        glRotatef(-90, 1, 0, 0);
        glTranslatef(coord.x,coord.z,coord.y);
        gluCylinder(obj1, cilindros[0].baseRadius, cilindros[0].topRadius, cilindros[0].height,cilindros[0].slices,cilindros[0].stacks);
}

void ArvoreSimples::DrawCopa(){
        GLUquadricObj *obj2 = gluNewQuadric();
        glBindTexture(GL_TEXTURE_2D, *copaTex);
        gluQuadricNormals(obj2, GLU_SMOOTH);
        gluQuadricTexture(obj2, GL_TRUE);
        glTranslatef(0,0,5);
        gluCylinder(obj2,cilindros[1].baseRadius, cilindros[1].topRadius, cilindros[1].height,cilindros[1].slices,cilindros[1].stacks);
        
        glTranslatef(0,0,2);
        GLUquadricObj *obj3 = gluNewQuadric();
        glBindTexture(GL_TEXTURE_2D, *copaTex);
        gluQuadricNormals(obj3, GLU_SMOOTH);
        gluQuadricTexture(obj3, GL_TRUE);
        gluCylinder(obj2, cilindros[1].baseRadius, cilindros[1].topRadius, cilindros[1].height,cilindros[1].slices,cilindros[1].stacks);

        glTranslatef(0,0,2);
        GLUquadricObj *obj4 = gluNewQuadric();
        glBindTexture(GL_TEXTURE_2D, *copaTex);
        gluQuadricNormals(obj4, GLU_SMOOTH);
        gluQuadricTexture(obj4, GL_TRUE);
        gluCylinder(obj2, cilindros[1].baseRadius, cilindros[1].topRadius, cilindros[1].height,cilindros[1].slices,cilindros[1].stacks);
}

void ArvoreSimples::ReadFile(const char *path){
    FILE * file = fopen(path, "r");
	if (file == NULL) {
		printf("Impossible to open the file arvore!\n");
		//return false;
	}
	while (1) {
		char lineHeader[128];
		// read the first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break; // EOF = End Of File. Quit the loop.

				   // else : parse lineHeader
		if (strcmp(lineHeader, "c") == 0) {
			Cilindro cilindro;
			fscanf(file, "%f %f %f %f %f\n", &cilindro.baseRadius, &cilindro.topRadius, &cilindro.height, &cilindro.slices,&cilindro.stacks);
			cilindros.push_back(cilindro);
		}
}
}