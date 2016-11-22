
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
	qtdOndasZ = 10;
	qtdOndasX = 20;
	tamanhoOndas = dimZ/(qtdOndasZ*0.75);
	anguloOndas = 2;

	

	int c = 0;
	for (int a = 1;a <= qtdOndasX/2;a++) {
		if (a <= 1)c += qtdOndasZ;
		//Criação das Ondas que compoem o lago de acordo com sua dimensao
		for (int b = 1;b <= c/2;b++) {
			ondas.push_back(new OndaLago(posiX + (((qtdOndasX/2)+1-a)*(dimX / qtdOndasX) - 0.5*(dimX / qtdOndasX)),posiY, posiZ + (b*(dimZ / qtdOndasZ) - 0.5*(dimZ / qtdOndasZ)), tamanhoOndas, tamanhoOndas, tamanhoOndas,-3*a-3*(ceil(b/anguloOndas)),textura));
			ondas.push_back(new OndaLago(posiX + (((qtdOndasX / 2) + 1 - a)*(dimX / qtdOndasX) - 0.5*(dimX / qtdOndasX)),posiY, posiZ - (b*(dimZ / qtdOndasZ) - 0.5*(dimZ / qtdOndasZ)), tamanhoOndas, tamanhoOndas, tamanhoOndas,-3*a-3* (ceil(b / anguloOndas)),textura));
			ondas.push_back(new OndaLago(posiX - (((qtdOndasX / 2) + 1 - a)*(dimX / qtdOndasX) - 0.5*(dimX / qtdOndasX)),posiY, posiZ + (b*(dimZ / qtdOndasZ) - 0.5*(dimZ / qtdOndasZ)), tamanhoOndas, tamanhoOndas, tamanhoOndas,-3*(qtdOndasX+1-a)-3* (ceil(b / anguloOndas)),textura));
			ondas.push_back(new OndaLago(posiX - (((qtdOndasX / 2) + 1 - a)*(dimX / qtdOndasX) - 0.5*(dimX / qtdOndasX)),posiY, posiZ - (b*(dimZ / qtdOndasZ) - 0.5*(dimZ / qtdOndasZ)), tamanhoOndas, tamanhoOndas, tamanhoOndas,-3*(qtdOndasX+1-a)-3* (ceil(b / anguloOndas)),textura));
		}
	}
}

Lago::~Lago(){

}

void Lago::Display() {
	
	for (unsigned int i = 0;i < ondas.size();i++) {
		ondas[i]->desenha();
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