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
        GLUquadricObj *sphere_ptr;
        GLfloat xRotated, yRotated, zRotated;
	    GLdouble radius;

    public:
        EsferaMundo();
        EsferaMundo(GLuint* ceuTextura);
	    ~EsferaMundo();

        GLdouble getRadius();
        void Display();

};


#endif