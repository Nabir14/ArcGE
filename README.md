# ArcGE
**Arc Game Engine** is a Game Development Library made in C++ and SDL2.

![arc-logo-transparent](https://github.com/user-attachments/assets/a5d1a3ae-622c-4d87-83e2-b82295a97394)

**Library Information:**
- Version: `0.5` (Alpha)
- Renderer: `2D (CPU Accelerated)`

# How To Use ArcGE:
*(as last modified) ArcGE has no stable release yet.*

**0. Install Dependencies:**
```sh
sudo apt-get install libsdl2-2.0-0 libsdl2-dev libsdl2-image-2.0-0-dev
```
**1. Clone The Repository:**
```sh
git clone https://github.com/Nabir14/ArcGE.git
```
**Copy The Include Header To Your Project Directory:**
```sh
cp ArcGE/src/arcge.hpp ~/yourprojectdirectory
```
**3. Include The Library In Your Source File:**
```cpp
#include "arcge.hpp"
```
**4. Compile The Code:**
```sh
g++ yourfilename.cpp -o yourexecutablename -lSDL2 -lSDL2_image
```
**5. Run && Enjoy:**
```sh
./yourexecutablename
```

# Example Codes:
*Check "tests" in "src" for test code files*

**Window Initialization And User Input:**
```cpp
#include <iostream>
#include "../arcge.hpp"
using namespace std;

int main(){
// Initialize ArcGE Library
	ArcGE age;
	age.init("ArcGE Window Example", 640, 480);

// Create A Scene And Link Initialized Library

       Scene myScene(&age);

// Render Loop
	bool run = true;
	while(run){

// Check For Key Press And Clear Window With Specified Color [scene.pollEvent() returns press key as ARCK_KEY]
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

// Render Everything In The Scene
		myScene.render();
	}

// Free Memory After Program Closes
	arcge.quit();
	return 0;
}
```
**Window With Icon Example:**
```cpp
#include <iostream>
#include "../arcge.hpp"
using namespace std;

int main(){
// Initialize The Library
	ArcGE age;
	age.init("ArcGE Window With Icon Example", 640, 480);

// Set A Window Icon	age.setProgramIcon("images/arcge-icon.bmp");

// Create A Scene
	Scene myScene(&age);
	bool run = true;
	while(run){

// Poll Event and Clear Screen With A Specific Color [scene.pollEvent() renturns pressed key as ARCK_KEY]
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

// Render Everything In The Scene
		myScene.render();
	}

// Free Memory After Program Closes
	arcge.quit();
	return 0;
}
```
**Scene Background Example:**
```cpp
#include <iostream>
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
```
**Object And Texture Example:**
```cpp
#include <iostream>
#include "../arcge.hpp"
using namespace std;

int main(){
// Initialize The ArcGE Library
	ArcGE arcge;
	arcge.init("ArcGE Mesh Test", 640, 480);

// Create A Scene And Link The Initialized Library
	Scene myScene(&arcge);

// Create A Mesh [using Quad mesh as example]
	Rect2DCPU myCube(&arcge);

// Set Size And Position
	myCube.setSize(64, 64);
	myCube.setPos(320, 240);

// Set Texture	myCube.setTexture("images/bmp_24.bmp");

// Some Useful Variables
	int posX = 0;
	int posY = 0;
	bool run = true;

// Game Loop
	while(run){

// Check For Key Press And Update The Objects Position. [scene.pollEvent() returns pressed key as ARCK_KEY]
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

// Clear The Window With A Specified Color
		myScene.clear(0, 0, 0, 255);

// Draw The Object
		myCube.draw();

// Render Everything In The Scene
		myScene.render();
	}

// Free Memory After Program Closes
	arcge.quit();
        return 0;
}
```
**Random Mesh Example:**
```cpp
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
			Rect2DCPU myCube(&arcge);

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
```

**Note: If you have encountered any bugs or want to contribute to the project please do a pull request.**
