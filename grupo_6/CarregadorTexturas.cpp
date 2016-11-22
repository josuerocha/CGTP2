#include "CarregadorTexturas.h"
using namespace std;

CarregadorTexturas::CarregadorTexturas(){

}

CarregadorTexturas::~CarregadorTexturas(){

}

void CarregadorTexturas::LoadAll(){
	this->mesa = LoadTexture("files/madeira.jpg");
	this->banco = LoadTexture("files/madeira.jpg");
	this->caixao = LoadTexture("files/baseareia.jpg");
	this->baseBarco = LoadTexture("files/baseBarco.jpg");
	this->cilindroBarco = LoadTexture("files/cilindroBarco.jpg");
	this->trianguloBarco = LoadTexture("files/trianguloBarco.jpg");
	this->topoAreia = LoadTexture("files/topoareia.jpg");
	this->baseAreia = LoadTexture("files/baseareia.jpg");
	this->lampada = LoadTexture("files/luz.jpg");
	this->poste = LoadTexture("files/poste.jpg");
	this->ceuTextura = LoadTexture("files/ceu.jpg");
	this->chaoTextura = LoadTexture("files/grass.jpg");
	this->madeira = LoadTexture("files/madeira.jpg");
	this->madeiraVermelha = LoadTexture("files/madeiravermelha.jpg");
	this->metal = LoadTexture("files/metal.jpg");
	this->troncoArvore = LoadTexture("files/tronco.jpg");
	this->folhasArvores = LoadTexture("files/grass.jpg");
	this->redBird = LoadTexture("files/birdred.jpg");
	this->brownBird = LoadTexture("files/birdbrown.jpg");
	this->colorfulBird = LoadTexture("files/birdcolorful.jpg");
	this->eye = LoadTexture("files/eye.jpg");
	this->water = LoadTexture("files/water.jpg");
	
	this->estruturaCasa = LoadTexture("files/madeira.jpg");
	this->telhadoCasa = LoadTexture("files/madeiravermelha.jpg");
	this->balde = LoadTexture("files/trianguloBarco.jpg");
	this->bola = LoadTexture("files/bola.jpg");
	this->correioCaixa = LoadTexture("files/luz.jpg");
	this->correioCilindro = LoadTexture("files/madeiravermelha.jpg");

}

GLuint CarregadorTexturas::LoadTexture(const char* filename){
	GLuint tex_ID = SOIL_load_OGL_texture( filename, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	glEnable( GL_TEXTURE_2D );
	glBindTexture( GL_TEXTURE_2D, tex_ID );
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	return tex_ID;
}

