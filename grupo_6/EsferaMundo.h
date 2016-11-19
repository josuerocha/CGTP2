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
        GLUquadricObj *sphere_ptr = NULL;
        GLfloat xRotated, yRotated, zRotated;
	    GLdouble radius = 500;

    public:
        EsferaMundo();
        EsferaMundo(GLuint* ceuTextura);
	    ~EsferaMundo();

        GLdouble getRadius();
        void Display();

};


#endif