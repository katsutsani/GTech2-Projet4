#pragma once
#include <SDL.h>

class newButton
{
public:
	newButton(SDL_Renderer* renderer, int buttonX, int buttonY, int buttonW, int buttonH);
	~newButton();

	void render();
private:
	SDL_Renderer* renderer;
	SDL_Rect rect;
};

