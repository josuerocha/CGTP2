#include "Tela.h"
#include <iostream>
using namespace std;

Tela::Tela(){	
	//Inicia cenário com tela inteira
	fullScreen = true;
}

Tela::~Tela(){

}

void Tela::Initialize(){
	glClearColor( 0.0, 0.0, 0.0, 0.0 );
	
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_BLEND); 
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_LIGHTING);       
	glShadeModel(GL_SMOOTH); //sombreamento suave                                              

	glEnable( GL_DEPTH_TEST);
	glEnable ( GL_TEXTURE_2D );                                            
	
	luz = new Luz(&camera, &carregadorTexturas.poste, &carregadorTexturas.lampada);

	//Carregando texturas
	carregadorTexturas.LoadAll();

	//Criando objetos da fase
	planoChao = new PlanoChao(&carregadorTexturas.chaoTextura);
	esferaMundo = new EsferaMundo(&carregadorTexturas.ceuTextura);
	moinho = new Moinho(&carregadorTexturas.madeira, &carregadorTexturas.metal, &carregadorTexturas.madeiraVermelha, &carregadorTexturas.madeiraVermelha, &carregadorTexturas.madeira, &carregadorTexturas.metal , Coord3d(90,0,30));
	lago = new Lago(Coord3d(20,-0.5,20),&carregadorTexturas.water);
	foguete = new Foguete(&carregadorTexturas.metal,&carregadorTexturas.madeiraVermelha);
	casa = new Casa(&carregadorTexturas.estruturaCasa,&carregadorTexturas.telhadoCasa);
	correio = new CaixaDeCorreios(&carregadorTexturas.correioCaixa, &carregadorTexturas.correioCilindro);
	caixaAreia = new CaixaAreia(&carregadorTexturas.topoAreia,&carregadorTexturas.baseAreia, &carregadorTexturas.balde, &carregadorTexturas.bola);

	vetorPassaros.push_back(new Passaro(Coord3d(15,6,6),Coord2d(50,30),0.5,&carregadorTexturas.redBird,&carregadorTexturas.eye));
	vetorPassaros.push_back(new Passaro(Coord3d(10,6,6),Coord2d(40,20),0.5,&carregadorTexturas.colorfulBird,&carregadorTexturas.eye));
	vetorPassaros.push_back(new Passaro(Coord3d(5,6,6),Coord2d(30,5),0.5,&carregadorTexturas.brownBird,&carregadorTexturas.eye));
	
	arvoreGrande = new Arvore(Coord3d(-10,0,-10),&carregadorTexturas.folhasArvores,&carregadorTexturas.troncoArvore);

	for (unsigned int i =0; i < 5; i++){
		for (unsigned int j =0; j < 5; j++){
			
			vetorArvoresSimples.push_back(new ArvoreSimples(Coord3d(i*10-15,0,j*10+20),&carregadorTexturas.folhasArvores,&carregadorTexturas.troncoArvore));
		}
	}

	banco = new Banco(&carregadorTexturas.banco);
	mesa = new Mesa(&carregadorTexturas.mesa);
	barco = new Barco(&carregadorTexturas.baseBarco, &carregadorTexturas.cilindroBarco,&carregadorTexturas.trianguloBarco);
	caixao = new Caixao(&carregadorTexturas.caixao,&carregadorTexturas.madeiraVermelha);


	//Setando limites da câmera
	camera.setLimitRadius(esferaMundo->getRadius());
	
}

void Tela::KeyboardDown(unsigned char key, int x, int y) {
	cout << "Tecla regular pressionada: " << char(key) << ". Mouse (" << x << ',' << y << ')' << endl;

	switch (key) {
        case FORWARD:
            keyBuffer[0] = true;
        break;

        case BACKWARD:
            keyBuffer[1] = true;
        break;

        case RIGHT:
            keyBuffer[2] = true;
        break;

        case LEFT:
            keyBuffer[3] = true;
        break;

        case FULLSCREEN:
			if(fullScreen){
       	 		glutFullScreen();
    		}
			else{
				glutReshapeWindow(800, 600);
				glutPositionWindow(270, 80);
			}
            fullScreen = !fullScreen;
        break;

		//esc para sair do jogo
		case EXIT_ENVIRONMENT:
			exit(0);
		break;

		case FOG_INCREASE://Increase fog density
			keyBuffer[8] = true;		
		break;
		
		case FOG_DECREASE://Decrease fog density
			keyBuffer[9] = true;
		break;

		case CAM_COORDINATES:
			cout<<"POSICAO DA CAMERA: "<<endl;
			cout<<"X "<<camera.getCoord_ptr()->x<<" Y "<<camera.getCoord_ptr()->y<<" Z "<<camera.getCoord_ptr()->z<<endl;
			cout<<"LOOK AT: "<<endl;
			cout<<"X "<<camera.getLookAt_ptr()->x<<" Y "<<camera.getLookAt_ptr()->y<<" Z "<<camera.getLookAt_ptr()->z<<endl;
			cout<<"NORMAL: "<<endl;
			cout<<"X "<<camera.getNormalVector()->x<<" Y "<<camera.getNormalVector()->y<<" Z "<<camera.getNormalVector()->z<<endl;
			cout<<"ANGLE "<<camera.getAngle()<<endl;
		break;

		case MOVING_LIGHT:
			luz->SwitchMovingLight();
		break;
		
		case INCREMENT_LIGHT:  
			luz->IncrementMovingLight();
		break;

		case DECREMENT_LIGHT:  
			luz->DecrementMovingLight();
		break;

		case FIXED_LIGHT_SWITCH:
			luz->SwitchFixedLights();
		break;
	}
	cout << "POSICAO X: " << x << "POSICAO Y: " << y << endl;
}

void Tela::KeyboardUp(unsigned char key, int x, int y) {
	cout << "Tecla regular solta: " << char(key) << ". Mouse (" << x << ',' << y << ')' << endl;
	switch (key) {
	case FORWARD:
		keyBuffer[0] = false;
		break;

	case BACKWARD:
		keyBuffer[1] = false;
		break;

	case RIGHT:
		keyBuffer[2] = false;
		break;

	case LEFT:
		keyBuffer[3] = false;
		break;

	case FOG_INCREASE://Increase fog density
			keyBuffer[8] = false;		
		break;
		
	case FOG_DECREASE://Decrease fog density
			keyBuffer[9] = false;
		break;
	}
}

void Tela::KeyboardSpecialDown(int key, int x, int y){
	cout << "Tecla especial pressionada: " << char(key) << ". Mouse (" << x << ',' << y << ')' << endl;
	switch(key){
		case SHIFT:
			camera.setSpeed(0.7);
		break;

		case UP:
			keyBuffer[4] = true;
		break;

		case DOWN:
			keyBuffer[5] = true;
		break;
	}
}

void Tela::KeyboardSpecialUp(int key, int x, int y){
	cout << "Tecla especial solta: " << char(key) << ". Mouse (" << x << ',' << y << ')' << endl;
	switch(key){
		case SHIFT:
			camera.setSpeed(0.3);
		break;

		case UP:
			keyBuffer[4] = false;
		break;

		case DOWN:
			keyBuffer[5] = false;
		break;
	}
}


void Tela::MouseClick(int button, int state, int x, int y) {
	if (state == GLUT_DOWN) {
		GLint viewport[4]; //var to hold the viewport info
		GLdouble modelview[16]; //var to hold the modelview info
		GLdouble projection[16]; //var to hold the projection matrix info
		GLfloat winX, winY, winZ; //variables to hold screen x,y,z coordinates
		GLdouble worldX, worldY, worldZ; //variables to hold world x,y,z coordinates

		glGetDoublev(GL_MODELVIEW_MATRIX, modelview); //get the modelview info
		glGetDoublev(GL_PROJECTION_MATRIX, projection); //get the projection matrix info
		glGetIntegerv(GL_VIEWPORT, viewport); //get the viewport info

		winX = (float)x;
		winY = (float)viewport[3] - (float)y;
		winZ = 0;

		//get the world coordinates from the screen coordinates
		gluUnProject(winX, winY, winZ, modelview, projection, viewport, &worldX, &worldY, &worldZ);
        
        switch (button){
            case 0:
                keyBuffer[6] = true;
                break;
                
            case 2:
                keyBuffer[7] = true;
                break;

        }

		mouse = Coord2d(worldX, worldY);

		cout << "Mouse click: " << button << ". Posicao (" << mouse.x << ',' << mouse.y << ')' << endl;
	
    }
}

void Tela::MouseMotion(int x, int y) {
		GLint viewport[4]; //var to hold the viewport info
		GLdouble modelview[16]; //var to hold the modelview info
		GLdouble projection[16]; //var to hold the projection matrix info
		GLfloat winX, winY, winZ; //variables to hold screen x,y,z coordinates
		GLdouble worldX, worldY, worldZ; //variables to hold world x,y,z coordinates

		glGetDoublev(GL_MODELVIEW_MATRIX, modelview); //get the modelview info
		glGetDoublev(GL_PROJECTION_MATRIX, projection); //get the projection matrix info
		glGetIntegerv(GL_VIEWPORT, viewport); //get the viewport info

		winX = (float)x;
		winY = (float)viewport[3] - (float)y;
		winZ = 0;

		//get the world coordinates from the screen coordinates
		gluUnProject(winX, winY, winZ, modelview, projection, viewport, &worldX, &worldY, &worldZ);
		mouse = Coord2d(worldX, worldY);
		cout << "Mouse moveu para (" << mouse.x << ',' << mouse.y << ')' << endl;
}

void Tela::Reshape(GLsizei w, GLsizei h)
{	if (h == 0) h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);

	int rate = 1.0f * w / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    glViewport(0, 0, w, h);
	gluPerspective(45.0, rate, 1.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Estabelece a janela de sele��o (left, right, bottom, top)
	if (w <= h){
		gluOrtho2D(0.0f, 800.0f, 0.0f, 600.0f*h / w);
		janela.height = 600 * h / w;
	}
	else{
		gluOrtho2D(0.0f, 800.0f*w / h, 0.0f, 600.0f);
		janela.width = 800 * w / h;
	}

	camera.Update();
	//cout << "TAMANHO TELA " << w << "  " << h << endl;
	//cout<<"CAMERA Y "<<camera.y<<" LOOKAT Y "<<lookAt.y<<endl;
}

void Tela::ControleTela(){
	//Movimento para frente
	if(keyBuffer[0]){
		camera.MoveForward();
		camera.Update();
	}
	//Movimento para trás;
	if(keyBuffer[1]){
		camera.MoveBack();
		camera.Update();
	}
	//Rotaciona camera direita
	if(keyBuffer[2]){
		camera.RotateLeft();
		camera.Update();
	}
	//Rotaciona camera esquerda
	if(keyBuffer[3]){
		camera.RotateRight();
		camera.Update();
	}
	//Move camera para cima
	if(keyBuffer[4]){
		camera.MoveUp();
		camera.Update();
	}
	//Move camera para baixo
	if(keyBuffer[5]){
		camera.MoveDown();
		camera.Update();
	}
	if(keyBuffer[8]){
		neblina.AlterDensity(1.1);
	}
	if(keyBuffer[9]){
		neblina.AlterDensity(0.9);
	}
}

void Tela::Display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_COLOR_MATERIAL);
	

	GLfloat componenteReflexao[4] = {0.6, 0.5, 0, 1.0};
	GLint brilho = 60;

	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, componenteReflexao);
	glMateriali(GL_FRONT, GL_SHININESS, brilho);

	//Muda estados dos componentes da tela
	camera.Update();
	planoChao->Display();
	esferaMundo->Display();
	neblina.Display();
	moinho->Display();
	caixao->Display();
	luz->Display();
	mesa->Display();
	banco->Display();
	barco->Display();
	caixaAreia->Display();
	arvoreGrande->Display();
	foguete->Display();
	casa->Display();
	correio->Display();

	//Exibe objetos em vetores
	DisplayBirds();
	DisplayTrees();

	lago->Display();

    glutSwapBuffers();
}

void Tela::DisplayBirds(){
	for (unsigned int i = 0; i<vetorPassaros.size(); i++){
		vetorPassaros[i]->Display();
	}
}

void Tela::DisplayTrees(){
	for (unsigned int i = 0; i<vetorArvoresSimples.size(); i++){
		vetorArvoresSimples[i]->Display();
	}
}
