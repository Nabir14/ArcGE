/*

[      ArcGE     ]
[Author: Nabir14 ]
[Version: 0.4    ]
[License: GPLv3  ]

*/

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

class ArcGE{
	public:
		SDL_Window* ArcGEWindow;
		SDL_Renderer* ArcGERenderer;
		SDL_Event ArcGEEvent;
		int WINDOW_WIDTH = 0;
		int WINDOW_HEIGHT = 0;
	void init(const char* windowTitle, int windowWidth, int windowHeight){
		SDL_Init(SDL_INIT_VIDEO);
		ArcGEWindow = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
		ArcGERenderer = SDL_CreateRenderer(ArcGEWindow, -1, SDL_RENDERER_ACCELERATED);
		this->WINDOW_WIDTH = windowWidth;
		this->WINDOW_HEIGHT = windowHeight;
	}
	void setProgramIcon(const char* path){
		SDL_Surface* icon = SDL_LoadBMP(path);
		SDL_SetWindowIcon(ArcGEWindow, icon);
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
			case SDLK_a:
				return 14;
				break;
			case SDLK_b:
				return 15;
				break;
			case SDLK_c:
				return 16;
				break;
			case SDLK_d:
				return 17;
				break;
			case SDLK_e:
				return 18;
				break;
			case SDLK_f:
				return 19;
				break;
			case SDLK_g:
				return 20;
				break;
			case SDLK_h:
				return 21;
				break;
			case SDLK_i:
				return 22;
				break;
			case SDLK_j:
				return 23;
				break;
			case SDLK_k:
				return 24;
				break;
			case SDLK_l:
				return 25;
				break;
			case SDLK_m:
				return 26;
				break;
			case SDLK_n:
				return 27;
				break;
			case SDLK_o:
				return 28;
				break;
			case SDLK_p:
				return 29;
				break;
			case SDLK_q:
				return 30;
				break;
			case SDLK_r:
				return 31;
				break;
			case SDLK_s:
				return 32;
				break;
			case SDLK_t:
				return 33;
				break;
			case SDLK_u:
				return 34;
				break;
			case SDLK_v:
				return 35;
				break;
			case SDLK_w:
				return 36;
				break;
			case SDLK_x:
				return 37;
				break;
			case SDLK_y:
				return 38;
				break;
			case SDLK_z:
				return 39;
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
