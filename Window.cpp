#include <SDL.h>
#include "Window.h"
#include "Button.h"
#include <iostream>
#include <SDL_ttf.h>
#include <chrono>
#include <ctime>



using namespace std;

SDL_Renderer* MainSDLWindow::GetRenderer(void) {  // Gets renderer

	return this->renderer;

}

void MainSDLWindow::createButton()
{
	this->buttonList.push_back(newButton::newButton(this->renderer, 20, 20, 360, 60, []() 
		{
		auto start = chrono::system_clock::now();
		// Some computation here
		auto end = chrono::system_clock::now();

		chrono::duration<double> elapsed_seconds = end - start;
		time_t end_time = chrono::system_clock::to_time_t(end);

		cout << "finished computation at " << ctime(&end_time)
			<< "elapsed time: " << elapsed_seconds.count() << "s"
			<< endl; 
		})); //FIRST
	this->buttonList.push_back(newButton::newButton(this->renderer, 20, 130, 360, 60, []() {cout << "OK2" << endl; })); //SECOND
	this->buttonList.push_back(newButton::newButton(this->renderer, 20, 240, 360, 60, []() {cout << "OK3" << endl; })); //THIRD
	this->buttonList.push_back(newButton::newButton(this->renderer, 20, 350, 360, 60, []() {cout << "OK4" << endl; })); //FOURTH

	this->buttonList.push_back(newButton::newButton(this->renderer, 400, 0, 900, 900, []() {cout << "OK5" << endl; })); //HALF MENU


}

void MainSDLWindow::render() //Renders button list
{
	SDL_RenderClear(this->renderer);
	for (auto i = 0; i < buttonList.size(); i++)
	{
		this->buttonList[i].render(); // Add buttons to list
	}

	this->font = TTF_OpenFont("Fonts/LTComical.ttf", 50);
	SDL_Color color = { 0, 0, 0 };
	this->surface = TTF_RenderText_Solid(this->font, //Buying list
		"Liste de course", color);
	this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
	SDL_Rect peste = { 35,25,this->surface->w,this->surface->h };
	SDL_RenderCopy(this->renderer, this->texture, NULL,&peste );
	SDL_FreeSurface(this->surface);
	SDL_DestroyTexture(this->texture);

	this->surface = TTF_RenderText_Solid(this->font, //Product list
		"Liste des produits", color);
	this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
	SDL_Rect reste = { 45,130,this->surface->w,this->surface->h };
	SDL_RenderCopy(this->renderer, this->texture, NULL, &reste);
	SDL_FreeSurface(this->surface);
	SDL_DestroyTexture(this->texture);


	this->surface = TTF_RenderText_Solid(this->font, // Timer
		"Baby Timer", color);
	this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
	SDL_Rect veste = { 45,240,this->surface->w,this->surface->h };
	SDL_RenderCopy(this->renderer, this->texture, NULL, &veste);
	SDL_FreeSurface(this->surface);
	SDL_DestroyTexture(this->texture);

	this->surface = TTF_RenderText_Solid(this->font, // Baby fed or not
		"Baby fed", color);
	this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
	SDL_Rect leste = { 45,350,this->surface->w,this->surface->h };
	SDL_RenderCopy(this->renderer, this->texture, NULL, &leste);
	SDL_FreeSurface(this->surface);
	SDL_DestroyTexture(this->texture);

	this->surface = TTF_RenderText_Solid(this->font, // Time and last time baby was fed
		"Time since last meal", color);
	this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
	SDL_Rect geste = { 430,35,this->surface->w,this->surface->h };
	SDL_RenderCopy(this->renderer, this->texture, NULL, &geste);
	SDL_FreeSurface(this->surface);
	SDL_DestroyTexture(this->texture);

	SDL_RenderPresent(this->renderer);
}

void MainSDLWindow::timer()
{

	SDL_RenderClear(this->renderer);
	auto start = chrono::system_clock::now();
	// Some computation here
	auto end = chrono::system_clock::now();

	chrono::duration<double> elapsed_seconds = end - start;
	time_t end_time = chrono::system_clock::to_time_t(end);

	cout << "finished computation at " << ctime(&end_time)
		<< "elapsed time: " << elapsed_seconds.count() << "s"
		<< endl;
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
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Erreur d'initialisation de la SDL : %s", SDL_GetError());
		return 0;
	}
	if (TTF_Init() == -1) {
		printf("TTF_Init: %s\n", TTF_GetError());
		exit(2);
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
