#pragma once
#include <SDL.h>
#include <stdio.h>
#include <vector>
#include "Button.h"
#include <SDL_ttf.h>
#include "product.h"
#include <unordered_map>
#include "list.h"

using namespace std;


class MainSDLWindow
{
public:
	MainSDLWindow(void);
	~MainSDLWindow(void);

	bool isRunning = true;

	int Init(const char* BabyApp, int width, int height);
	SDL_Renderer* GetRenderer(void);

	void handleEvent();
		
	void render(int page, shoplist);

	void createButton();

	void timer();

	int page = 0;
private: 
	SDL_Window* window;
	SDL_Renderer* renderer;
	vector<newButton> buttonList;

	SDL_Surface* surface;
	SDL_Texture* texture;
	TTF_Font* font;
	TTF_Font* fontText;

	int mouseX = 0;
	int mouseY = 0;
	int texW = 0;
	int texH = 0;
};
