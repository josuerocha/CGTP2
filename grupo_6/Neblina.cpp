#include "Neblina.h"

using namespace std;

Neblina::Neblina(){

    density = 0.001;

    glFogf(GL_FOG_DENSITY, density);
}

Neblina::~Neblina(){
    
}

void Neblina::Display(){
    
    glFogf(GL_FOG_DENSITY, density);
    glutPostRedisplay();
}

void Neblina::AlterDensity(float delta){
    float newDensity = density * delta;
    if(newDensity >= 0.001 && newDensity <= 100){
        this->density = newDensity;
    }

    cout<<"Density "<< density<<endl;
}

void Neblina::setDensity(float density){
    this->density = density;
}

float Neblina::getDensity(){
    return density;
}

void Neblina::setColor(Color color){
    this->color[0] = color.r;
    this->color[1] = color.g;
    this->color[2] = color.b;
    this->color[3] = color.a;
}

Color Neblina::getColor(){
    Color color;
    color.r = this->color[0];
    color.g = this->color[1];
    color.b = this->color[2];
    color.a = this->color[3];
    
    return color;
}