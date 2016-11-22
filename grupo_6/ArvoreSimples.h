#ifndef ArvoreSimples_h
#define ArvoreSimples_h

//Standard includes
#include "GL/glut.h"
#include <iostream>
#include "soil/SOIL.h"
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>

//Standard includes
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>

//Custom includes
#include "Estruturas.h"
#include "FuncoesExtra.h"



class ArvoreSimples{
    private:
        GLuint* troncoTex;
        GLuint* copaTex;

        Coord3d coord;

        std::vector <Cilindro> cilindros;

    public:
        ArvoreSimples(Coord3d position,GLuint* copaTex,GLuint* troncoTex);
        ~ArvoreSimples();

        void Display();
        void ReadFile(const char *path);
        void DrawTrunk();
        void DrawCopa();
    

};


#endif