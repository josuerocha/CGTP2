#include "FuncoesExtra.h"


FuncoesExtra::FuncoesExtra(){
}

FuncoesExtra::~FuncoesExtra(){
}

GLuint FuncoesExtra::LoadTexture(const char* filename){
	GLuint tex_ID = SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,(SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT));
	glEnable( GL_TEXTURE_2D );
	glBindTexture( GL_TEXTURE_2D, tex_ID );
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	return tex_ID;
}

float FuncoesExtra::CalculateDistance3d(Coord a,Coord b){
	float distance = pow(b.x - a.x,2) + pow(b.y - a.y,2) + pow(b.z - a.z,2);
	return distance; 
}