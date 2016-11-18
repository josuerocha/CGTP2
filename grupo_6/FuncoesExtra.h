#ifndef FuncoesExtra_h
#define FuncoesExtra_h

//Standard includes
#include "GL/glut.h"
#include <iostream>
#include "soil/SOIL.h"
#include <string>
#include <math.h>

//Custom includes
#include "Estruturas.h"

class FuncoesExtra{
private:

public:
    FuncoesExtra();
	~FuncoesExtra();

    static float CalculateDistance3d(Coord3d a,Coord3d b);


};


#endif