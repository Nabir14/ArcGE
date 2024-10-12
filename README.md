# ArcGE
**Arc Game Engine** is a Game Development Library made in C++, SDL2 and OpenGL.

![arc-logo-transparent](https://github.com/user-attachments/assets/a5d1a3ae-622c-4d87-83e2-b82295a97394)

# How To Get ArcGE:
*(as last modified) ArcGE has stable release yet.*

**1. Clone The Repo:**
```sh
git clone https://github.com/Nabir14/ArcGE.git
```
**Copy The Include Header To Your Project Directory:**
```sh
cp ArcGE/src/arcge.hpp ~/yourprojectdirectory
```
**3. Include The Library In Your Souce File:**
```cpp
#include "arcge.hpp"
```
**4. Compile:**
```sh
g++ yourfilename.cpp -o yourexecutablename -lSDL2
```
**5. Run && Enjoy:**
```sh
./yourexecutablename
```

# Example Codes:
**Window Initialization And User Input:**
```cpp
#include <iostream>
#include "../arcge.hpp"
using namespace std;

int main(){
	ArcGE age;
	age.init("ArcGE Window Example", 640, 480);
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
	myScene.freeMemory();
	return 0;
}
```

**Object And Texture Example:**
```cpp
#include <iostream>
#include "../arcge.hpp"
using namespace std;

int main(){
	ArcGE arcge;
	arcge.init("ArcGE Mesh Test", 640, 480);

	Scene myScene(&arcge);

	QuadMesh2DCPU myCube(&arcge);
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
				myCube.setPos(posX, posY);
				break;
			case ARCK_DOWN:
				posY += 6;
				myCube.setPos(posX, posY);
				break;
			case ARCK_LEFT:
				posX -= 6;
				myCube.setPos(posX, posY);
				break;
			case ARCK_RIGHT:
				posX += 6;
				myCube.setPos(posX, posY);
				break;
		}
		myScene.clear(0, 0, 0, 255);
		myCube.draw();
		myScene.render();
	}
	myScene.freeMemory();
}
```

**Note: If you have encountered any bugs or want to contribute to the project please do a pull request.**
