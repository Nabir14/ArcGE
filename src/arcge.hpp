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
#define ARCK_UP 10
#define ARCK_DOWN 11
#define ARCK_LEFT 12
#define ARCK_RIGHT 13

class ArcGE{
	public:
		SDL_Window* ArcGEWindow;
		SDL_Renderer* ArcGERenderer;
		SDL_Event ArcGEEvent;
	void init(const char* windowTitle, int windowWidth, int windowHeight){
		SDL_Init(SDL_INIT_VIDEO);
		ArcGEWindow = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
		ArcGERenderer = SDL_CreateRenderer(ArcGEWindow, -1, SDL_RENDERER_ACCELERATED);
	}
};

class Scene{
        public:
		ArcGE* arcci;
	Scene(ArcGE* uci) : arcci(uci){}
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
				break;
			case SDLK_UP:
				return 10;
				break;
			case SDLK_DOWN:
				return 11;
				break;
			case SDLK_LEFT:
				return 12;
				break;
			case SDLK_RIGHT:
				return 13;
				break;
			}
                }
                return 0;
        }
        void clear(int r, int g, int b, int a){
                SDL_SetRenderDrawColor(arcci->ArcGERenderer, r, g, b, a);
                SDL_RenderClear(arcci->ArcGERenderer);
        }
        void render(){
                SDL_RenderPresent(arcci->ArcGERenderer);
        }
        void freeMemory(){
                arcci->ArcGEWindow = NULL;
                arcci->ArcGERenderer = NULL;
                SDL_DestroyWindow(arcci->ArcGEWindow);
                SDL_DestroyRenderer(arcci->ArcGERenderer);
        }
};

class QuadMesh2DCPU{
	public:
		ArcGE* arcci;
		SDL_Rect rect;
		SDL_Texture* texture;
		int rcR = 255;
		int rcG = 255;
		int rcB = 255;
		int rcA = 255;
	QuadMesh2DCPU(ArcGE* uci) : arcci(uci){}
	void createMesh(int pX, int pY, int sX, int sY){
		this->rect = {pX, pY, sX, sY};
	}
	void setPos(int x, int y){
		this->rect.x = x;
		this->rect.y = y;
	}
	void setSize(int x, int y){
		this->rect.w = x;
		this->rect.h = y;
	}
	void setColor(int r, int g, int b, int a){
		this->rcR = r;
		this->rcG = g;
		this->rcB = b;
		this->rcA = a;
	}
	void setTexture(const char* path){
		SDL_Surface* textureSurface = SDL_LoadBMP(path);
		texture = SDL_CreateTextureFromSurface(arcci->ArcGERenderer, textureSurface);
		SDL_FreeSurface(textureSurface);
	}
	void draw(){
		SDL_SetRenderDrawColor(arcci->ArcGERenderer, rcR, rcG, rcB, rcA);
		SDL_RenderFillRect(arcci->ArcGERenderer, &rect);
		SDL_RenderCopy(arcci->ArcGERenderer, texture, NULL, &rect);
	}
};
