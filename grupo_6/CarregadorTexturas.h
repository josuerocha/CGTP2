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

    CarregadorTexturas();
    ~CarregadorTexturas();

    void LoadAll();
    GLuint LoadTexture(const char* filename);
};

#endif