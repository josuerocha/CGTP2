#include "CarregadorTexturas.h"
using namespace std;

CarregadorTexturas::CarregadorTexturas(){

}

CarregadorTexturas::~CarregadorTexturas(){

}

void CarregadorTexturas::LoadAll(){
     this->ceuTextura = LoadTexture("files/ceu.jpg");
     this->chaoTextura = LoadTexture("files/grass.jpg");

}

GLuint CarregadorTexturas::LoadTexture(const char* filename){
	GLuint tex_ID = SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,(SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT));
	glEnable( GL_TEXTURE_2D );
	glBindTexture( GL_TEXTURE_2D, tex_ID );
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	return tex_ID;
}