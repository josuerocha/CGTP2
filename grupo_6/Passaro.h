#ifndef Passaro_h
#define Passaro_h

//Standard includes
#include "GL/glut.h"
#include <iostream>
#include "soil/SOIL.h"

//Custom includes
#include "Estruturas.h"

class Passaro{
    private:
     int wingRotation;
     bool decreaseRotation;

    public:
    Passaro();
    ~Passaro();

    void DrawHead();
    void DrawBody();
    void DrawBeak();
    void DrawEyes();
    void DrawWings();

    void Display();

};



#endif
