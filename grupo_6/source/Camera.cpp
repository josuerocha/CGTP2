#include "../header/Camera.h"
#include <iostream>
using namespace std;

Camera::Camera()
{	
    coord.z = 5;
    speed = 0.01;
}

Camera::~Camera(){

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

void Camera::setCoordX(float delta){
    coord.x += delta;
}

void Camera::setCoordY(float delta){
    coord.y += delta;
}

void Camera::setCoordZ(float delta){
    coord.z += delta;
}

void Camera::setLookAtX(float delta){
    lookAt.x += delta;
}

void Camera::setLookAtY(float delta){
    lookAt.y += delta;
}

void Camera::setLookAtZ(float delta){
    lookAt.z += delta;
}

void Camera::MoveForward(){
    coord.z -= speed;
    lookAt.z -= speed;
}

void Camera::MoveBack(){
    coord.z += speed;
    lookAt.z += speed;
}

void Camera::RotateRight(){

}

void Camera::RotateLeft(){

}

void Camera::MoveUp(){
    coord.y += speed;
    lookAt.y += speed;
}

void Camera::MoveDown(){
    coord.y -= speed;
    lookAt.y -= speed;
}

void Camera::Update(){
    glLoadIdentity();
	gluLookAt(coord.x, coord.y, coord.z, lookAt.x , lookAt.y, lookAt.z , 0.0f, 1.0f, 0.0f);
}