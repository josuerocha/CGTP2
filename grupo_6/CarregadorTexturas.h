#ifndef CarregadorTexturas_h
#define CarregadorTexturas_h

//Standard includes
#include "GL/glut.h"
#include <iostream>
#include "soil/SOIL.h"

class CarregadorTexturas{
private:
    

public:
    GLuint chaoTextura;
    GLuint ceuTextura;
    GLuint metal;
    GLuint madeira;
    GLuint madeiraVermelha;
    GLuint troncoArvore;
    GLuint folhasArvores;
    GLuint redBird;
	GLuint brownBird;
	GLuint colorfulBird;
    GLuint eye;
    GLuint water;
    GLuint poste;
    GLuint lampada;
    GLuint mesa;
    GLuint banco;
	GLuint topoAreia;
	GLuint baseAreia;
	GLuint caixao;
	GLuint baseBarco;
	GLuint cilindroBarco;
	GLuint trianguloBarco;

    CarregadorTexturas();
    ~CarregadorTexturas();

    void LoadAll();
    GLuint LoadTexture(const char* filename);
};

#endif