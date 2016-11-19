#ifndef Passaro_h
#define Passaro_h

//Standard includes
#include "GL/glut.h"
#include <iostream>
#include "soil/SOIL.h"

//Custom includes
#include "Estruturas.h"
#include "FuncoesExtra.h"

class Passaro{
    private:
        
        Coord3d coord;
        int wingRotation;
        bool decreaseRotation;

        Coord2d raioVoo;
        float anguloVoo;
        float speed;

    public:
        Passaro(Coord3d coord, Coord2d raioElipse, float speed);
        ~Passaro();

        void DrawHead();
        void DrawBody();
        void DrawBeak();
        void DrawEyes();
        void DrawWings();
        void Fly();

        void Display();

};



#endif
