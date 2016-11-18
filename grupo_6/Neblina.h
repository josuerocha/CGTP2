#ifndef Neblina_h
#define Neblina_h

//Standard includes
#include "GL/glut.h"
#include <iostream>
#include "soil/SOIL.h"

//Custom includes
#include "Estruturas.h"

class Neblina{

private:
    float density;
    float color[4];

public:
    Neblina();
    ~Neblina();

    void setDensity(float density);
    float getDensity();
    void AlterDensity(float delta);

    void setColor(Color cor);
    Color getColor();

    void Display();

};


#endif