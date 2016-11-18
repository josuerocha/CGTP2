#ifndef FuncoesExtra_h
#define FuncoesExtra_h

#include "GL/glut.h"
#include <iostream>
#include "soil/SOIL.h"
#include <string>

class FuncoesExtra{
private:

public:
    FuncoesExtra();
	~FuncoesExtra();

    static GLuint LoadTexture(const char* filename);
    static float CalculateDistance3d(Coord a,Coord b);


};


#endif