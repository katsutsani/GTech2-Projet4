#include <SDL.h>
#include "Window.h"

using namespace std;

/*SDL_Renderer* MainSDLWindow::GetRenderer(void)
{
    return this->renderer;
}*/

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

    SDL_Event e; bool quit = false; while (quit == false) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) quit = true;
        }
    }

    return 0;
}
