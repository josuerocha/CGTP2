#ifndef PlanoChao_h
#define PlanoChao_h

//Standard includes
#include "GL/glut.h"
#include <iostream>
#include "soil/SOIL.h"

//Custom includes
#include "Estruturas.h"
#include "FuncoesExtra.h"

class PlanoChao{
    private:
        GLuint chaoTextura;

    public:
        PlanoChao();
        PlanoChao(GLuint* chaoTextura);
        
	    ~PlanoChao();

        void Display();

};


#endif