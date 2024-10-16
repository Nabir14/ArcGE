#include <iostream>
#include <cstdlib>
#include "../arcge.hpp"
using namespace std;

int main(){
// Initalize The Library
	ArcGE arcge;
	arcge.init("ArcGE Scene Background Test", 640, 480);

// Create A New Scene
	Scene myScene(&arcge);

// Set Scene Background
	myScene.setBackground("images/bg.jpg");

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

// Render The Scene
		myScene.render();
	}

// Free The Memory After The Program Closes
	arcge.quit();
	return 0;
}
