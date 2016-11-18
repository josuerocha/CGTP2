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
	    ~PlanoChao();
        void Display();
        void Load();

};


#endif