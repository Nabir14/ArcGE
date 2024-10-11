#pragma once

#include <SDL2/SDL.h>

#define ARCK_QUIT -1
#define ARCK_0 0
#define ARCK_1 1
#define ARCK_2 2
#define ARCK_3 3
#define ARCK_4 4
#define ARCK_5 5
#define ARCK_6 6
#define ARCK_7 7
#define ARCK_8 8
#define ARCK_9 9

class ArcGE{
	public:
		SDL_Window* ArcGEWindow;
		SDL_Renderer* ArcGERenderer;
		SDL_Event ArcGEEvent;
	void init(const char* windowTitle, int windowWidth, int windowHeight){
		ArcGEWindow = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
		ArcGERenderer = SDL_CreateRenderer(ArcGEWindow, -1, SDL_RENDERER_ACCELERATED);
	}
};

class Scene{
        public:
		ArcGE* arcci;
		int ccR = 0;
		int ccG = 0;
		int ccB = 0;
		int ccA = 0;
	Scene(ArcGE* uci) : arcci(uci){}
	void setClearColor(int clearColorR, int clearColorG, int clearColorB, int clearColorA){
		this->ccR = clearColorR;
		this->ccG = clearColorG;
		this->ccB = clearColorB;
		this->ccA = clearColorA;
	}
        int pollEvent(){
                SDL_PollEvent(&arcci->ArcGEEvent);
                if(arcci->ArcGEEvent.type == SDL_QUIT){
                	return -1;
                }else if(arcci->ArcGEEvent.type == SDL_KEYDOWN){
                	switch(arcci->ArcGEEvent.key.keysym.sym){
			case SDLK_0:
				return 0;
				break;
			case SDLK_1:
				return 1;
				break;
			case SDLK_2:
				return 2;
				break;
			case SDLK_3:
				return 3;
				break;
			case SDLK_4:
				return 4;
				break;
			case SDLK_5:
				return 5;
				break;
			case SDLK_6:
				return 6;
				break;
			case SDLK_7:
				return 7;
				break;
			case SDLK_8:
				return 8;
				break;
			case SDLK_9:
				return 9;
			}
                }
                return 0;
        }
        void render(){
                SDL_SetRenderDrawColor(arcci->ArcGERenderer, ccR, ccG, ccB, ccA);
                SDL_RenderClear(arcci->ArcGERenderer);
                SDL_RenderPresent(arcci->ArcGERenderer);
        }
        void freeMemory(){
                arcci->ArcGEWindow = NULL;
                arcci->ArcGERenderer = NULL;
                SDL_DestroyWindow(arcci->ArcGEWindow);
                SDL_DestroyRenderer(arcci->ArcGERenderer);
        }
};
