
#include "Lago.h"
#include <iostream>
#include <ctime>
#include <vector>


#define PI 3.14159265
using namespace std;
Lago::Lago(Coord3d coord, GLuint* textura) {

	this->textura = textura;

	posiX = coord.x;
	posiY = coord.y;
	posiZ = coord.z;
	dimX = 20;
	dimY = 5;
	dimZ = 15;
	qtdBolasZ = 10;
	qtdBolasX = 20;
	tamanhoBolas = dimZ/(qtdBolasZ*0.75);
	anguloDaOnda = 2;

	

	int c = 0;
	for (int a = 1;a <= qtdBolasX/2;a++) {
		if (a <= 1)c += qtdBolasZ;
		//Criação das bolas que compoem o lago de acordo com sua dimensao
		for (int b = 1;b <= c/2;b++) {
			bolas.push_back(new BolaLago(posiX + (((qtdBolasX/2)+1-a)*(dimX / qtdBolasX) - 0.5*(dimX / qtdBolasX)),posiY, posiZ + (b*(dimZ / qtdBolasZ) - 0.5*(dimZ / qtdBolasZ)), tamanhoBolas, tamanhoBolas, tamanhoBolas,-3*a-3*(ceil(b/anguloDaOnda)),textura));
			bolas.push_back(new BolaLago(posiX + (((qtdBolasX / 2) + 1 - a)*(dimX / qtdBolasX) - 0.5*(dimX / qtdBolasX)),posiY, posiZ - (b*(dimZ / qtdBolasZ) - 0.5*(dimZ / qtdBolasZ)), tamanhoBolas, tamanhoBolas, tamanhoBolas,-3*a-3* (ceil(b / anguloDaOnda)),textura));
			bolas.push_back(new BolaLago(posiX - (((qtdBolasX / 2) + 1 - a)*(dimX / qtdBolasX) - 0.5*(dimX / qtdBolasX)),posiY, posiZ + (b*(dimZ / qtdBolasZ) - 0.5*(dimZ / qtdBolasZ)), tamanhoBolas, tamanhoBolas, tamanhoBolas,-3*(qtdBolasX+1-a)-3* (ceil(b / anguloDaOnda)),textura));
			bolas.push_back(new BolaLago(posiX - (((qtdBolasX / 2) + 1 - a)*(dimX / qtdBolasX) - 0.5*(dimX / qtdBolasX)),posiY, posiZ - (b*(dimZ / qtdBolasZ) - 0.5*(dimZ / qtdBolasZ)), tamanhoBolas, tamanhoBolas, tamanhoBolas,-3*(qtdBolasX+1-a)-3* (ceil(b / anguloDaOnda)),textura));
		}
	}
}

Lago::~Lago(){

}

void Lago::Display() {
	
	for (int i = 0;i < bolas.size();i++) {
		bolas[i]->desenha();
	}

}

float Lago::getPosiX() { 
	return posiX; 
}

float Lago::getPosiY() { return posiY; }
float Lago::getPosiZ() { return posiZ; }
float Lago::getDimX() { return dimX; }
float Lago::getDimY() { return dimY; }
float Lago::getDimZ() { return dimZ; }
void Lago::setPosiX(float a) { posiX = a; }
void Lago::setPosiY(float a) { posiY = a; }
void Lago::setPosiZ(float a) { posiZ = a; }