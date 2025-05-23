/*

[      ArcGE     ]
[Author: Nabir14 ]
[Version: 0.6    ]
[License: GPLv3  ]

*/

#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>

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
#define ARCK_A 14
#define ARCK_B 15
#define ARCK_C 16
#define ARCK_D 17
#define ARCK_E 18
#define ARCK_F 19
#define ARCK_G 20
#define ARCK_H 21
#define ARCK_I 22
#define ARCK_J 23
#define ARCK_K 24
#define ARCK_L 25
#define ARCK_M 26
#define ARCK_N 27
#define ARCK_O 28
#define ARCK_P 29
#define ARCK_Q 30
#define ARCK_R 31
#define ARCK_S 32
#define ARCK_T 33
#define ARCK_U 34
#define ARCK_V 35
#define ARCK_W 36
#define ARCK_X 37
#define ARCK_Y 38
#define ARCK_Z 39
#define ARCK_ESCAPE 40

class ArcGE{
	public:
		SDL_Window* ArcGEWindow;
		SDL_Renderer* ArcGERenderer;
		SDL_Event ArcGEEvent;
		int WINDOW_WIDTH = 0;
		int WINDOW_HEIGHT = 0;
	void init(const char* windowTitle, int windowWidth, int windowHeight){
		SDL_Init(SDL_INIT_VIDEO);

		SDL_CreateWindowAndRenderer(windowTitle, windowWidth, windowHeight, SDL_WINDOW_RESIZABLE, &ArcGEWindow, &ArcGERenderer);
		this->WINDOW_WIDTH = windowWidth;
		this->WINDOW_HEIGHT = windowHeight;
	}
	void setProgramIcon(const char* path){
		SDL_Surface* icon = IMG_Load(path);
		SDL_SetWindowIcon(ArcGEWindow, icon);
		SDL_DestroySurface(icon);
	}
	void quit(){
		SDL_DestroyWindow(ArcGEWindow);
		SDL_DestroyRenderer(ArcGERenderer);
		SDL_Quit();
	}
};

class Scene{
        public:
		ArcGE* arcci;
		SDL_Surface* sceneBackground;
		SDL_Texture* bgTexture;
		SDL_FRect bgRect;
	Scene(ArcGE* uci) : arcci(uci){}
        int pollEvent(){
                SDL_PollEvent(&arcci->ArcGEEvent);
                if(arcci->ArcGEEvent.type == SDL_EVENT_QUIT){
                	return -1;
                }else if(arcci->ArcGEEvent.type == SDL_EVENT_KEY_DOWN){
                	switch(arcci->ArcGEEvent.key.key){
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
			case SDLK_A:
				return 14;
				break;
			case SDLK_B:
				return 15;
				break;
			case SDLK_C:
				return 16;
				break;
			case SDLK_D:
				return 17;
				break;
			case SDLK_E:
				return 18;
				break;
			case SDLK_F:
				return 19;
				break;
			case SDLK_G:
				return 20;
				break;
			case SDLK_H:
				return 21;
				break;
			case SDLK_I:
				return 22;
				break;
			case SDLK_J:
				return 23;
				break;
			case SDLK_K:
				return 24;
				break;
			case SDLK_L:
				return 25;
				break;
			case SDLK_M:
				return 26;
				break;
			case SDLK_N:
				return 27;
				break;
			case SDLK_O:
				return 28;
				break;
			case SDLK_P:
				return 29;
				break;
			case SDLK_Q:
				return 30;
				break;
			case SDLK_R:
				return 31;
				break;
			case SDLK_S:
				return 32;
				break;
			case SDLK_T:
				return 33;
				break;
			case SDLK_U:
				return 34;
				break;
			case SDLK_V:
				return 35;
				break;
			case SDLK_W:
				return 36;
				break;
			case SDLK_X:
				return 37;
				break;
			case SDLK_Y:
				return 38;
				break;
			case SDLK_Z:
				return 39;
				break;
			case SDLK_ESCAPE:
				return 40;
				break;
			}
                }
                return 0;
        }
        void clear(int r, int g, int b, int a){
                SDL_SetRenderDrawColor(arcci->ArcGERenderer, r, g, b, a);
                SDL_RenderClear(arcci->ArcGERenderer);
		SDL_RenderTexture(arcci->ArcGERenderer, bgTexture, NULL, &bgRect);
        }
        void render(){
                SDL_RenderPresent(arcci->ArcGERenderer);
        }
	void setBackground(const char* path){
		sceneBackground = IMG_Load(path);
		bgRect = {0, 0, (float)arcci->WINDOW_WIDTH, (float)arcci->WINDOW_HEIGHT};
		bgTexture = SDL_CreateTextureFromSurface(arcci->ArcGERenderer, sceneBackground);
		SDL_DestroySurface(sceneBackground);
	}
};

class Rect2DCPU{
	public:
		ArcGE* arcci;
		SDL_FRect rect;
		SDL_Texture* texture;
		int rcR = 255;
		int rcG = 255;
		int rcB = 255;
		int rcA = 255;
	Rect2DCPU(ArcGE* uci) : arcci(uci){}
	void createMesh(float pX, float pY, float sX, float sY){
		this->rect = {pX, pY, sX, sY};
	}
	void setPos(float x, float y){
		this->rect.x = x;
		this->rect.y = y;
	}
	void setSize(float x, float y){
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
		SDL_Surface* textureSurface = IMG_Load(path);
		texture = SDL_CreateTextureFromSurface(arcci->ArcGERenderer, textureSurface);
		SDL_DestroySurface(textureSurface);
	}
	void draw(){
		SDL_SetRenderDrawColor(arcci->ArcGERenderer, rcR, rcG, rcB, rcA);
		SDL_RenderFillRect(arcci->ArcGERenderer, &rect);
		SDL_RenderTexture(arcci->ArcGERenderer, texture, NULL, &rect);
	}
};
