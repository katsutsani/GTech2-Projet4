#pragma once
#include <SDL.h>
#include <stdio.h>
#include <vector>
#include "Button.h"

using namespace std;


class MainSDLWindow
{
public:
	MainSDLWindow(void);
	~MainSDLWindow(void);

	bool isRunning = true;

	int Init(const char* Jesus, int width, int height);
	SDL_Renderer* GetRenderer(void);

	void handleEvent();
		
	void render();

	void createButton();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	vector<newButton> buttonList;
};
