
#include "Lago.h"
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

#define PI 3.14159265
using namespace std;
Lago::Lago(Coord3d coord) {

	posiX = coord.x;
	posiY = coord.y;
	posiZ = coord.z;
	dimX = 10;
	dimY = 2.5;
	dimZ = 10;
	qtdBolasZ = 10;
	qtdBolasX = 20;
	tamanhoBolas = dimZ/(qtdBolasZ*0.75);

	int c = 0;
	for (int a = 1;a <= qtdBolasX/2;a++) {
		if(a<= qtdBolasZ/2)c+=2;
		for (int b = 1;b <= c/2;b++) {
			bolas.push_back(new BolaLago(posiX + (((qtdBolasX/2)+1-a)*(dimX / qtdBolasX) - 0.5*(dimX / qtdBolasX)),posiY, posiZ + (b*(dimZ / qtdBolasZ) - 0.5*(dimZ / qtdBolasZ)), tamanhoBolas, tamanhoBolas, tamanhoBolas,-35*a-35*b));
			bolas.push_back(new BolaLago(posiX + (((qtdBolasX / 2) + 1 - a)*(dimX / qtdBolasX) - 0.5*(dimX / qtdBolasX)),posiY, posiZ - (b*(dimZ / qtdBolasZ) - 0.5*(dimZ / qtdBolasZ)), tamanhoBolas, tamanhoBolas, tamanhoBolas,-35*a-35*b));
			bolas.push_back(new BolaLago(posiX - (((qtdBolasX / 2) + 1 - a)*(dimX / qtdBolasX) - 0.5*(dimX / qtdBolasX)),posiY, posiZ + (b*(dimZ / qtdBolasZ) - 0.5*(dimZ / qtdBolasZ)), tamanhoBolas, tamanhoBolas, tamanhoBolas,-35*(qtdBolasX+1-a)-35*b));
			bolas.push_back(new BolaLago(posiX - (((qtdBolasX / 2) + 1 - a)*(dimX / qtdBolasX) - 0.5*(dimX / qtdBolasX)),posiY, posiZ - (b*(dimZ / qtdBolasZ) - 0.5*(dimZ / qtdBolasZ)), tamanhoBolas, tamanhoBolas, tamanhoBolas,-35*(qtdBolasX+1-a)-35*b));
		}
	}

}


void Lago::Display() {
	
	for (unsigned int i = 0;i < bolas.size();i++) {
		bolas[i]->desenha();
	}

}


float Lago::getPosiX() { return posiX; }
float Lago::getPosiY() { return posiY; }
float Lago::getPosiZ() { return posiZ; }
float Lago::getDimX() { return dimX; }
float Lago::getDimY() { return dimY; }
float Lago::getDimZ() { return dimZ; }
void Lago::setPosiX(float a) { posiX = a; }
void Lago::setPosiY(float a) { posiY = a; }
void Lago::setPosiZ(float a) { posiZ = a; }