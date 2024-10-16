#include <iostream>
#include <cstdlib>
#include "../arcge.hpp"
using namespace std;

int main(){
// Initalize The Library
	ArcGE arcge;
	arcge.init("ArcGE Random Mesh Test", 640, 480);

// Create A New Scene
	Scene myScene(&arcge);

// Render Loop
	bool run = true;
	while(run){

// Check For Key Presses [scene.pollEvent() returns key presses as ARCK_KEY]
		switch(myScene.pollEvent()){
			case ARCK_QUIT:
				run = false;
				break;
		}

// Clear Window With A Specified Color
		myScene.clear(0, 0, 0, 255);

// For Loop Creating Unique Quad Objects
		for(int i = 0; i < 16; i++){

// Create Quad Mesh
			QuadMesh2DCPU myCube(&arcge);

// Randomly Choose Random Position, Size And Color
			myCube.setPos(rand() % 640, rand() % 480);
			myCube.setSize(rand() % 64, rand() % 64);
			myCube.setColor(rand() % 255, rand() % 255, rand() % 255, rand() % 255);

// Draw The Object
			myCube.draw();
		}

// Render The Scene
		myScene.render();
	}

// Free The Memory After The Program Closes
	arcge.quit();
	return 0;
}
