#include <SDL.h>
#include "Window.h"
#include "Button.h"

using namespace std;



SDL_Renderer* MainSDLWindow::GetRenderer(void){

    return this->renderer;

}

void MainSDLWindow::createButton()
{
    this->buttonList.push_back(newButton::newButton(this->renderer, 0, 0, 32, 32));
}

void MainSDLWindow::render()
{
    SDL_RenderClear(this->renderer);

    for (auto i = 0; i < buttonList.size(); i++)
    {
        this->buttonList[i].render();
    }

    SDL_RenderPresent(this->renderer);
}

void MainSDLWindow::handleEvent()
{
    SDL_Event e;
    while (SDL_PollEvent(&e)) 
    {
        switch (e.type)
        {
        case SDL_QUIT:
            this->isRunning = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            break;
        default:
            break;
        }
    }
}

MainSDLWindow::MainSDLWindow()
{
    this->window = NULL;
    this->renderer = NULL;
}

MainSDLWindow::~MainSDLWindow()
{
    if (this->renderer != NULL)
        SDL_DestroyRenderer(this->renderer);
    if (this->window != NULL)
        SDL_DestroyWindow(this->window);
    SDL_Quit();
}

int MainSDLWindow::Init(const char* Jesus, int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Erreur d'initialisation de la SDL : %s", SDL_GetError());
        return 0;
    }
    this->window = SDL_CreateWindow(Jesus, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (this->window == NULL)
    {
        printf("Erreur de création de la fenêtre : %s", SDL_GetError());
        return 0;
    }
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_SOFTWARE);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    return 0;
}
