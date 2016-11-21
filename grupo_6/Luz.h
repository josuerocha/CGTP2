#ifndef Luz_h
#define Luz_h

//Standard includes
#include "GL/glut.h"
#include <iostream>
#include "soil/SOIL.h"

//Custom includes
#include "Estruturas.h"
#include "Camera.h"

class Luz{

private:
    bool fixedLightFlag;
    bool movingLightFlag;

    Coord3d coordFixedLight1;
    Coord3d coordFixedLight2;

    Color colorMovingLight;
    Camera* camera;
    GLuint* posteTex; 
    GLuint* lampadaTex;

public:
    Luz(Camera* camera, GLuint* posteTex, GLuint* lampadaTex);
    ~Luz();

    void IncrementMovingLight();
    void DecrementMovingLight();

    void SwitchMovingLight();
    void SwitchFixedLights();

    void Display();

    void DrawPole(Coord3d coord);
};


#endif