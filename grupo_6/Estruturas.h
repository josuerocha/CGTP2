#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

//#define M_PI 3.14159
//------------- Estruturas de Dados -----------

typedef struct glutWindow {
	int width;
	int height;
	char* title;

	float field_of_view_angle;
	float z_near;
	float z_far;
} glutWindow;

typedef struct Coord2d {
	float x, y;
	Coord2d() {};
	Coord2d(float x, float y) {
		this->x = x;
		this->y = y;
	}
} Coord2d;

typedef struct Coord3d {
	float x, y, z;
	Coord3d() {
		this->x = 0;
		this->y = 0;
        this->z = 0;
	};
	Coord3d(float x, float y, float z) {
		this->x = x;
		this->y = y;
        this->z = z;
	}
} Coord3d;

typedef struct Dimensao2d {
	float largura, altura;
	Dimensao2d() {};
	Dimensao2d(float altura, float largura) {
		this->largura = largura;
		this->altura = altura;
	}
} Dimensao2d;

typedef struct Dimensao3d {
	float largura, altura, profundidade;
	Dimensao3d() {};
	Dimensao3d(float altura, float largura,float profundidade) {
		this->largura = largura;
		this->altura = altura;
        this->profundidade = profundidade;
	}
} Dimensao3d;

typedef struct Color {
	float r, g, b, a;
	Color() {};
	Color(float r, float g, float b, float a) {
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}
} Cor;

typedef struct Cilindro {
	float baseRadius, topRadius, height,slices,stacks;
	Cilindro() {
		this->baseRadius = 0;
		this->topRadius = 0;
		this->height = 0;
		this->slices = 0;
		this->stacks = 0;
	};
	Cilindro(float baseRadius, float topRadius, float height, float slices, float stacks) {
		this->baseRadius = baseRadius;
		this->topRadius = topRadius;
		this->height = height;
		this->slices = slices;
		this->stacks = stacks;
	}
} Cilindro;

#endif