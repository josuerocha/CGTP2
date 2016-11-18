#include "FuncoesExtra.h"


FuncoesExtra::FuncoesExtra(){
}

FuncoesExtra::~FuncoesExtra(){
}

float FuncoesExtra::CalculateDistance3d(Coord3d a , Coord3d b){
	
	float distance = pow(b.x - a.x,2) + pow(b.y - a.y,2) + pow(b.z - a.z,2);
	return distance; 

}