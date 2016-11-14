#ifndef Camera_h
#define Camera_h

#include <iostream>
#include <GL/glut.h>

//Custom includes
#include "Estruturas.h"

class Camera{
    private:
    Coord3d coord;
    Coord3d lookAt;
    float speed;

    public:
    Camera();
    ~Camera();

    float getSpeed();
    void setSpeed(float speed);

    void setCoord(Coord3d coord);
    Coord3d* getCoord_ptr();
    void setLookAt(Coord3d lookAt);
    Coord3d* getLookAt_ptr();

    void setCoordX(float delta);
    void setCoordY(float delta);
    void setCoordZ(float delta);

    void setLookAtX(float delta);
    void setLookAtY(float delta);
    void setLookAtZ(float delta);

    void MoveForward();
    void MoveBack();

    void RotateRight();
    void RotateLeft();

    void MoveUp();
    void MoveDown();

    void Update();
};
#endif