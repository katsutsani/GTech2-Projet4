#include "Button.h"
#include "Window.h"
#include <SDL.h>

using namespace std;

newButton::newButton(SDL_Renderer* renderer, int buttonX, int buttonY, int buttonW, int buttonH, function<void()> onClick) // Create new Button
{
    this->renderer = renderer;

    this->rect.x = buttonX;
    this->rect.y = buttonY;
    this->rect.w = buttonW;
    this->rect.h = buttonH;
    this->GetCubes = onClick;
}

SDL_Rect newButton::getRect()
{
    return this->rect;
}

void newButton::render()
{
    SDL_SetRenderDrawColor(this->renderer, 200, 200, 200, 255); // Color Rect
    SDL_RenderFillRect(this->renderer, &rect);

    SDL_SetRenderDrawColor(this->renderer, 200, 120, 240, 255); // Color Border
    SDL_RenderDrawRect(this->renderer, &rect);

    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255); // Color Main
}

newButton::~newButton()
{
}