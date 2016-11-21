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

    Color colorMovingLight;
    Camera* camera;

public:
    Luz(Camera* camera);
    ~Luz();

    void IncrementMovingLight();
    void DecrementMovingLight();

    void SwitchMovingLight();
    void SwitchFixedLights();

};


#endif