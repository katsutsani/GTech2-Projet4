#include <SDL.h>
#include "Window.h"
#include "Button.h"
#include <iostream>
#include <SDL_ttf.h>



using namespace std;

SDL_Renderer* MainSDLWindow::GetRenderer(void) {  // Gets renderer

	return this->renderer;

}

void MainSDLWindow::createButton()
{
	this->buttonList.push_back(newButton::newButton(this->renderer, 20, 20, 120, 60, []() {cout << "OK1" << endl; })); //FIRST
	this->buttonList.push_back(newButton::newButton(this->renderer, 20, 130, 120, 60, []() {cout << "OK2" << endl; })); //SECOND
	this->buttonList.push_back(newButton::newButton(this->renderer, 20, 240, 120, 60, []() {cout << "OK3" << endl; })); //THIRD
	this->buttonList.push_back(newButton::newButton(this->renderer, 20, 350, 120, 60, []() {cout << "OK4" << endl; })); //FOURTH
	this->buttonList.push_back(newButton::newButton(this->renderer, 20, 460, 120, 60, []() {cout << "OK5" << endl; })); //FIFTH
}

void MainSDLWindow::render() //Renders button list
{
	SDL_RenderClear(this->renderer);
	for (auto i = 0; i < buttonList.size(); i++)
	{
		this->buttonList[i].render(); // Add buttons to list
	}

	this->font = TTF_OpenFont("Fonts/LTComical.ttf", 50);
	SDL_Color color = { 85, 52, 155 };
	this->surface = TTF_RenderText_Solid(this->font,
		"Retarded fuck", color);
	this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
	SDL_Rect dest = { 10,510,this->surface->w,this->surface->h };
	SDL_RenderCopy(this->renderer, this->texture, NULL,&dest );
	SDL_FreeSurface(this->surface);
	SDL_DestroyTexture(this->texture);

	this->surface = TTF_RenderText_Solid(this->font,
		"test", color);
	this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
	SDL_Rect test = { 100,300,this->surface->w,this->surface->h };
	SDL_RenderCopy(this->renderer, this->texture, NULL, &test);
	SDL_FreeSurface(this->surface);
	SDL_DestroyTexture(this->texture);


	this->surface = TTF_RenderText_Solid(this->font,
		"pd", color);
	this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
	SDL_Rect veste = { 60,100,this->surface->w,this->surface->h };
	SDL_RenderCopy(this->renderer, this->texture, NULL, &veste);
	SDL_FreeSurface(this->surface);
	SDL_DestroyTexture(this->texture);

	SDL_RenderPresent(this->renderer);
}

void MainSDLWindow::handleEvent() // Manage Events
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{ 
		case SDL_QUIT:  // Closes app
			this->isRunning = false; 
			break;

		case SDL_MOUSEMOTION: // Get mouse position on screen
			SDL_GetMouseState(&this->mouseX, &this->mouseY);

			cout << "x: " << mouseX << ", y: " << mouseY << endl;
			break;

		case SDL_MOUSEBUTTONDOWN: // click event for the buttons

			if (e.button.button == SDL_BUTTON_LEFT)
			{
				for (auto i = 0; i < this->buttonList.size(); i++)
				{
					if (this->mouseX > this->buttonList[i].getRect().x && this->mouseX < this->buttonList[i].getRect().x + this->buttonList[i].getRect().w && this->mouseY < this->buttonList[i].getRect().y + this->buttonList[i].getRect().h && this->mouseY > this->buttonList[i].getRect().y) //FIRST
						this->buttonList[i].GetCubes();
				}
			}
			break;
		default:
			break;
		}
	}
}

MainSDLWindow::MainSDLWindow() // Window initiation
{
	this->window = NULL;
	this->renderer = NULL;
	this->surface = NULL;
	this->texture = NULL;
	this->font = NULL;

}

MainSDLWindow::~MainSDLWindow()
{
	if (this->renderer != NULL)
		SDL_DestroyRenderer(this->renderer);
	if (this->window != NULL)
		SDL_DestroyWindow(this->window);


	SDL_DestroyTexture(this->texture);
	SDL_FreeSurface(this->surface);
	TTF_Quit();
	SDL_Quit();
}

int MainSDLWindow::Init(const char* Jesus, int width, int height)
{
	if (TTF_Init() == -1) {
		printf("TTF_Init: %s\n", TTF_GetError());
		exit(2);
	}
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
