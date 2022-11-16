#include "Button.h"
#include "Window.h"
#include <SDL.h>

using namespace std;

newButton::newButton(SDL_Renderer* renderer, int buttonX, int buttonY, int buttonW, int buttonH)
{
    this->renderer = renderer;

    this->rect.x = buttonX;
    this->rect.y = buttonY;
    this->rect.w = buttonW;
    this->rect.h = buttonH;
}

void newButton::render()
{
    SDL_SetRenderDrawColor(this->renderer, 200, 200, 200, 255);
    SDL_RenderFillRect(this->renderer, &rect);

    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
}

newButton::~newButton()
{
}