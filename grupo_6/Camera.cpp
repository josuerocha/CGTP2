#include "Camera.h"
#include <iostream>
using namespace std;

Camera::Camera(){	
    coord = Coord3d(-61.6172, 12.03 , 2.41987);
    normalVector = Coord3d(-0.999573, 0, -0.0291989);
    lookAt = Coord3d(-60.6177, 12.03, 2.44907);
    setSpeed(0.05);
    speedRotation = 0.025;
    angle = 1.6;
    Update();
}

Camera::~Camera(){

}

void Camera::setLimitRadius(GLdouble limitRadius){
    this->limitRadius = limitRadius;
}

void Camera::setSpeed(float speed){
    this->speed = speed;
}

float Camera::getSpeed(){
    return speed;
}

void Camera::setCoord(Coord3d coord){
    this->coord = coord;
}

Coord3d* Camera::getCoord_ptr(){
    return &coord;
}

void Camera::setLookAt(Coord3d lookAt){
    this->lookAt = lookAt;
}

Coord3d* Camera::getLookAt_ptr(){
    return &lookAt;
}

void Camera::setCoordX(float x){
    this->coord.x += x;
}

void Camera::setCoordY(float y){
    this->coord.y += y;
}

void Camera::setCoordZ(float z){
    this->coord.z += z;
}

void Camera::setLookAtX(float x){
    this->lookAt.x += x;
}

void Camera::setLookAtY(float y){
    this->lookAt.y += y;
}

void Camera::setLookAtZ(float z){
    this->lookAt.z += z;
}

void Camera::AlterCoordX(float delta){
    this->coord.x += delta;
}

void Camera::AlterCoordY(float delta){
    this->coord.y += delta;
}

void Camera::AlterCoordZ(float delta){
    this->coord.z += delta;
}

void Camera::AlterLookAtX(float delta){
    this->lookAt.x += delta;
}

void Camera::AlterLookAtY(float delta){
    this->lookAt.y += delta;
}

void Camera::AlterLookAtZ(float delta){
    this->lookAt.z += delta;
}

float Camera::getAngle(){
    return angle;
}

Coord3d* Camera::getNormalVector(){
    return &normalVector;
}

void Camera::MoveForward(){
   
    float camX = -normalVector.x * speed + coord.x;
    float camY = -normalVector.y * speed + coord.y;
    float camZ = -normalVector.z * speed + coord.z;

    Coord3d newCamCoordinate = Coord3d(camX,camY,camZ);
   
   if(CheckBounds(newCamCoordinate)){
      
        setCoord(newCamCoordinate);

        AlterLookAtX(-normalVector.x * speed);
        AlterLookAtY(-normalVector.y * speed);
        AlterLookAtZ(-normalVector.z * speed);
   }

}

void Camera::MoveBack(){
    float camX = normalVector.x * speed + coord.x;
    float camY = normalVector.y * speed + coord.y;
    float camZ = normalVector.z * speed + coord.z;

    Coord3d newCamCoordinate = Coord3d(camX,camY,camZ);
   
    if(CheckBounds(newCamCoordinate)){
      
        setCoord(newCamCoordinate);

        AlterLookAtX(normalVector.x * speed);
        AlterLookAtY(normalVector.y * speed);
        AlterLookAtZ(normalVector.z * speed);
   }

}

void Camera::RotateRight(){
    angle -= speedRotation;
    float deltax = sin(angle);
	float deltaz = -cos(angle);

    this->lookAt = this->coord;

    AlterLookAtX(deltax);
    AlterLookAtZ(deltaz);

    normalVector = Coord3d(coord.x - lookAt.x, normalVector.y ,coord.z - lookAt.z);
}

void Camera::RotateLeft(){
    angle += speedRotation;
    float deltax = sin(angle);
	float deltaz = -cos(angle);

    this->lookAt = this->coord;

    AlterLookAtX(deltax);
    AlterLookAtZ(deltaz);

    normalVector = Coord3d(coord.x - lookAt.x, normalVector.y ,coord.z - lookAt.z);
}

void Camera::MoveUp(){
    
    float newCamY = coord.y + speed;
    Coord3d newCamCoordinate = Coord3d(coord.x,newCamY,coord.z);

    float bogusCamY = coord.y + 0.5;
    Coord3d bogusCamCoordinate = Coord3d(coord.x,bogusCamY,coord.z);

    if(CheckBounds(bogusCamCoordinate)){
        setCoord(newCamCoordinate);
        lookAt.y += speed;
        normalVector.y = coord.y - lookAt.y;
    }
}

void Camera::MoveDown(){
    
    float newCamY = coord.y - speed;
    Coord3d newCamCoordinate = Coord3d(coord.x,newCamY,coord.z);
    float bogusCamY = coord.y - 0.5;
    Coord3d bogusCamCoordinate = Coord3d(coord.x,bogusCamY,coord.z);

    if(CheckBounds(bogusCamCoordinate)){
        setCoord(newCamCoordinate);
        lookAt.y -= speed;
        normalVector.y = coord.y - lookAt.y;
    }
}

void Camera::Update(){
    glLoadIdentity();
	gluLookAt(coord.x, coord.y, coord.z, lookAt.x , lookAt.y, lookAt.z , 0.0f, 1.0f, 0.0f);
    GLfloat camPosition[4] = {coord.x,coord.y,coord.z,1.0};
	glLightfv(GL_LIGHT1, GL_POSITION, camPosition);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION,camPosition);
}

bool Camera::CheckBounds(Coord3d newCamCoordinate){
    bool ableToMove = false;
    if(newCamCoordinate.y > 0.40){
        float distanceCenter = FuncoesExtra::CalculateDistance3d(Coord3d(0,0,0),newCamCoordinate);
        if(distanceCenter < (pow(limitRadius - 10,2))){
            ableToMove = true;
        }
    }

    return ableToMove;
}