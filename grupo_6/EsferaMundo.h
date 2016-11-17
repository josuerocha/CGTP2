#ifndef EsferaMundo_h
#define EsferaMundo_h

//Standard includes
#include "GL/glut.h"
#include <iostream>
#include "soil/SOIL.h"

//Custom includes
#include "Estruturas.h"
#include "FuncoesExtra.h"

class EsferaMundo{
    private:
        GLuint ceuTextura;
        GLUquadricObj *pSphere = NULL;
        GLfloat xRotated, yRotated, zRotated;
	    GLdouble radius = 5;

    public:
        EsferaMundo();
	    ~EsferaMundo();
        void Display();
        void Load();

};


#endif