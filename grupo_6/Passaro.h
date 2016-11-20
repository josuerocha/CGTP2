#ifndef Passaro_h
#define Passaro_h

//Standard includes
#include "GL/glut.h"
#include <iostream>
#include "soil/SOIL.h"
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>

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
        GLuint* texturaCorpo;
        GLuint* texturaOlho;

        std::vector<Coord3d> temp_v1;
        std::vector<Coord3d> temp_v2;
        std::vector<Coord3d> temp_v3;
        std::vector<Coord3d> temp_v4;
        std::vector<Coord3d> temp_v5;
        std::vector<Coord3d> temp_v6;
        std::vector<Coord3d> temp_v7;
        std::vector<Coord3d> temp_normais;

    public:
        Passaro(Coord3d coord, Coord2d raioElipse, float speed,GLuint* texturaCorpo,GLuint* texturaOlho);
        ~Passaro();

        void DrawHead();
        void DrawBody();
        void DrawBeak();
        void DrawEyes();
        void DrawWings();
        void LerArquivo();
        void Fly();

        void Display();

};



#endif
