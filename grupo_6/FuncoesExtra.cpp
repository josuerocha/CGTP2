#include "FuncoesExtra.h"


FuncoesExtra::FuncoesExtra(){
}

FuncoesExtra::~FuncoesExtra(){
}

float FuncoesExtra::CalculateDistance3d(Coord3d a , Coord3d b){
	
	float distance = pow(b.x - a.x,2) + pow(b.y - a.y,2) + pow(b.z - a.z,2);
	return distance; 

}
 
Coord2d FuncoesExtra::ElipsePoints(float raioX, float raioY, int angle){

   	float fatorConversaoGrausRad =  3.14159/180.0;
	float anguloRadianos = angle * fatorConversaoGrausRad;
    return Coord2d(cos(anguloRadianos)*raioX, sin(anguloRadianos)*raioY);

}