#include <iostream>
#include "../arcge.hpp"
using namespace std;

int main(){
	ArcGE age;
	age.init("ArcGE Window With Icon Example", 640, 480);
	age.setProgramIcon("images/arcge-icon.bmp");
	Scene myScene(&age);
	bool run = true;
	while(run){
		switch(myScene.pollEvent()){
			case ARCK_QUIT:
				run = false;
				break;
			case ARCK_1:
				myScene.clear(255, 0, 0, 255);
				break;
			case ARCK_2:
				myScene.clear(0 ,255, 0, 255);
				break;
			case ARCK_3:
				myScene.clear(0, 0, 255, 255);
				break;
		}
		myScene.render();
	}
	age.quit();
	return 0;
}
