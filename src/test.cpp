#include <iostream>
#include "arcge.hpp"
using namespace std;

int main(){
	ArcGE age;
	age.init("arc", 640, 480);
	Scene myScene(&age);
	myScene.setClearColor(0, 0, 0, 255);
	bool run = true;
	while(run){
		switch(myScene.pollEvent()){
			case ARCK_QUIT:
				run = false;
				break;
			case ARCK_1:
				myScene.setClearColor(255, 0, 0, 255);
				break;
			case ARCK_2:
				myScene.setClearColor(0 ,255, 0, 255);
				break;
			case ARCK_3:
				myScene.setClearColor(0, 0, 255, 255);
				break;
		}
		myScene.render();
	}
	myScene.freeMemory();
	return 0;
}
