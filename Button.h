#pragma once
#include <SDL.h>
#include <functional>
using namespace std;

class newButton
{
public:

	newButton(SDL_Renderer* renderer, int buttonX, int buttonY, int buttonW, int buttonH, function<void()> onClick);
	~newButton();

	function<void()> GetCubes = [] {}; // Used to optimize button clicking

	SDL_Rect getRect();

	void render();
private:

	SDL_Renderer* renderer;
	SDL_Rect rect;
};

