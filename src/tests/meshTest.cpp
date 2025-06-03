#include <iostream>
#include "../arcge.hpp"
using namespace std;

int main(){
	ArcGE arcge;
	arcge.init("ArcGE Mesh Test", 640, 480);

	Scene myScene(&arcge);
	myScene.init();
	
	Camera2D cam(&arcge);
	myScene.setCamera(cam.rect);

	Rect2DCPU myCube(&myScene);
	myCube.setSize(64, 64);
	myCube.setPos(320, 240);
	myCube.setTexture("images/bmp_24.bmp");

	int posX = 0;
	int posY = 0;
	bool run = true;

	while(run){
		switch(myScene.pollEvent()){
			case ARCK_QUIT:
				run = false;
				break;
			case ARCK_UP:
				posY -= 6;
				cam.setPos(posX, posY);
				break;
			case ARCK_DOWN:
				posY += 6;
				cam.setPos(posX, posY);
				break;
			case ARCK_LEFT:
				posX -= 6;
				cam.setPos(posX, posY);
				break;
			case ARCK_RIGHT:
				posX += 6;
				cam.setPos(posX, posY);
				break;
		}
		myScene.clear(0, 0, 0, 255);
		myCube.draw();
		myScene.render();
	}
	myScene.free();
	arcge.quit();
	return 0;
}
