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
```

**Note: If you have encountered any bugs or want to contribute to the project please do a pull request.**
