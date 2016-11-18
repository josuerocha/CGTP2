#ifndef Camera_h
#define Camera_h

#include <iostream>
#include "GL/glut.h"
#include <math.h>

//Custom includes
#include "Estruturas.h"
#include "FuncoesExtra.h"

class Camera{
    private:
    Coord3d coord;
    Coord3d lookAt;
    Coord3d normalVector;
    float speed;
    float angle;
    GLdouble limitRadius;

    public:
    Camera();
    ~Camera();

    float getSpeed();
    void setSpeed(float speed);

    void setCoord(Coord3d coord);
    Coord3d* getCoord_ptr();
    void setLookAt(Coord3d lookAt);
    Coord3d* getLookAt_ptr();

    void AlterCoordX(float delta);
    void AlterCoordY(float delta);
    void AlterCoordZ(float delta);

    void AlterLookAtX(float delta);
    void AlterLookAtY(float delta);
    void AlterLookAtZ(float delta);

    void setCoordX(float x);
    void setCoordY(float y);
    void setCoordZ(float z);

    void setLookAtX(float x);
    void setLookAtY(float y);
    void setLookAtZ(float z);

    void MoveForward();
    void MoveBack();

    void RotateRight();
    void RotateLeft();

    void MoveUp();
    void MoveDown();

    void setLimitRadius(GLdouble limitRadius);

    bool CheckBounds(Coord3d newCamCoordinate);

    void Update();
};
#endif