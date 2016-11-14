#include "../header/Camera.h"
#include <iostream>
using namespace std;

Camera::Camera()
{	
    coord = Coord3d(0,0,5);
    speed = 0.01;
    angle = 0;
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

void Camera::MoveForward(){
    coord.z -= speed;
    lookAt.z -= speed;
}

void Camera::MoveBack(){
    coord.z += speed;
    lookAt.z += speed;
}

void Camera::RotateRight(){
    angle -= speed;
    float deltax = sin(angle);
	float deltaz = -cos(angle);

    this->lookAt = this->coord;

    AlterLookAtX(deltax);
    AlterLookAtZ(deltaz);
}

void Camera::RotateLeft(){
    angle += speed;
    float deltax = sin(angle);
	float deltaz = -cos(angle);

    this->lookAt = this->coord;

    AlterLookAtX(deltax);
    AlterLookAtZ(deltaz);
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