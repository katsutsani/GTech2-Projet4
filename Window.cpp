#include <SDL.h>
#include "Window.h"
#include "Button.h"
#include <iostream>
#include <SDL_ttf.h>
#include <chrono>
#include <time.h>
#include <string>
#include <cstring>


using namespace std;

SDL_Renderer* MainSDLWindow::GetRenderer(void) {  // Gets renderer

	return this->renderer;

}

void MainSDLWindow::createButton()
{

	this->buttonList.push_back(newButton::newButton(this->renderer, 20, 20, 360, 60, [](){})); //To-Buy List
	this->buttonList.push_back(newButton::newButton(this->renderer, 20, 130, 360, 60, []() {cout << "OK2" << endl; })); //Products List
	this->buttonList.push_back(newButton::newButton(this->renderer, 20, 240, 360, 60, []() {cout << "OK3" << endl; })); //Baby Timer
	this->buttonList.push_back(newButton::newButton(this->renderer, 20, 350, 360, 60, []() {cout << "OK4" << endl; })); //Baby Fed

	this->buttonList.push_back(newButton::newButton(this->renderer, 400, 0, 900, 900, []() {cout << "OK5" << endl; })); //HALF MENU
}

void MainSDLWindow::render(int page, shoplist shoplist) //Renders button list
{
	time_t seconds;
	struct tm instant;

	time(&seconds);
	localtime_s(&instant, &seconds);

	printf("%d:%d:%d\n", instant.tm_hour, instant.tm_min, instant.tm_sec);

	string Timer = to_string(instant.tm_hour)+"H "+to_string(instant.tm_min)+"M "+to_string(instant.tm_sec)+"S ";

	SDL_RenderClear(this->renderer);
	for (auto i = 0; i < buttonList.size(); i++)
	{
		this->buttonList[i].render(); // Add buttons to list
	}
	SDL_Color color = { 0, 0, 0 };
	if (page == 0) {
		this->font = TTF_OpenFont("Fonts/LTComical.ttf", 50);
		this->surface = TTF_RenderText_Solid(this->font, // Clock
			Timer.c_str(), color);
		this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
		SDL_Rect geste = { 470,110,this->surface->w,this->surface->h };
		SDL_RenderCopy(this->renderer, this->texture, NULL, &geste);
		SDL_FreeSurface(this->surface);
		SDL_DestroyTexture(this->texture);
	}
	else {
		this->fontText = TTF_OpenFont("Fonts/LTComical.ttf", 20);
		this->surface = TTF_RenderText_Solid(this->fontText, // Clock
			Timer.c_str(), color);
		this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
		SDL_Rect geste = { 455,25,this->surface->w,this->surface->h };
		SDL_RenderCopy(this->renderer, this->texture, NULL, &geste);
		SDL_FreeSurface(this->surface);
		SDL_DestroyTexture(this->texture);
	}

	this->surface = TTF_RenderText_Solid(this->font, //Buying list
		"To-Buy list", color);
	this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
	SDL_Rect peste = { 35,25,this->surface->w,this->surface->h };
	SDL_RenderCopy(this->renderer, this->texture, NULL,&peste );
	SDL_FreeSurface(this->surface);
	SDL_DestroyTexture(this->texture);

	this->surface = TTF_RenderText_Solid(this->font, //Product list
		"Products list", color);
	this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
	SDL_Rect reste = { 40,135,this->surface->w,this->surface->h };
	SDL_RenderCopy(this->renderer, this->texture, NULL, &reste);
	SDL_FreeSurface(this->surface);
	SDL_DestroyTexture(this->texture);


	this->surface = TTF_RenderText_Solid(this->font, // Baby timer since last meal
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
	
	if(page == 0) 
	{
		this->surface = TTF_RenderText_Solid(this->font, // Clock message
			"Time of the day", color);
		this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
		SDL_Rect oeste = { 455,35,this->surface->w,this->surface->h };
		SDL_RenderCopy(this->renderer, this->texture, NULL, &oeste);
		SDL_FreeSurface(this->surface);
		SDL_DestroyTexture(this->texture);
	}
	else if (page == 1) {
		int ToBuyproduct_X = 455;
		int ToBuyproduct_y = 75;
		int ToBuyquantity_x = 755;
		for (int i = 0; i < shoplist.getShoplist().size(); i++) {

			this->surface = TTF_RenderText_Solid(this->fontText, // Clock message
				shoplist.getShoplist()[i]->getName(), color);
			this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
			SDL_Rect name = { ToBuyproduct_X,ToBuyproduct_y,this->surface->w,this->surface->h };
			SDL_RenderCopy(this->renderer, this->texture, NULL, &name);
			SDL_FreeSurface(this->surface);
			SDL_DestroyTexture(this->texture);

			string quantity = to_string(shoplist.getShoplist()[i]->getQuantityToBuy());


			this->surface = TTF_RenderText_Solid(this->fontText, // Clock message
				quantity.c_str(), color);
			this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
			SDL_Rect ShowQuantity = { ToBuyquantity_x,ToBuyproduct_y,this->surface->w,this->surface->h };
			SDL_RenderCopy(this->renderer, this->texture, NULL, &ShowQuantity);
			SDL_FreeSurface(this->surface);
			SDL_DestroyTexture(this->texture);

			ToBuyproduct_y += 30;
		}
	}
	else if (page == 2) {
		int product_X = 455;
		int product_y = 75;
		int quantity_x =755;
		for (auto i = shoplist.listProduct.begin(); i != shoplist.listProduct.end(); i++)
		{
			if (i->second.getQuantity() != 0) {
				this->surface = TTF_RenderText_Solid(this->fontText, // Clock message
					i->first, color);
				this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
				SDL_Rect name = { product_X,product_y,this->surface->w,this->surface->h };
				SDL_RenderCopy(this->renderer, this->texture, NULL, &name);
				SDL_FreeSurface(this->surface);
				SDL_DestroyTexture(this->texture);

				string quantity = to_string(i->second.getQuantity());


				this->surface = TTF_RenderText_Solid(this->fontText, // Clock message
					quantity.c_str(), color);
				this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
				SDL_Rect ShowQuantity = { quantity_x,product_y,this->surface->w,this->surface->h };
				SDL_RenderCopy(this->renderer, this->texture, NULL, &ShowQuantity);
				SDL_FreeSurface(this->surface);
				SDL_DestroyTexture(this->texture);

				product_y += 30;
			}
		}
	}
		

	SDL_RenderPresent(this->renderer);
}

void MainSDLWindow::timer()
{
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
				for (auto i = 1; i <= this->buttonList.size(); i++)
				{
					if (this->mouseX > this->buttonList[i-1].getRect().x && this->mouseX < this->buttonList[i-1].getRect().x + this->buttonList[i-1].getRect().w && this->mouseY < this->buttonList[i-1].getRect().y + this->buttonList[i-1].getRect().h && this->mouseY > this->buttonList[i-1].getRect().y) //FIRST
					{	
						this->buttonList[i-1].GetCubes();

						if (i == 1)
						{
							this->page = 1;
						}
						else if (i == 2) {
							this->page = 2;
						}
						else if (i == 3) {
							this->page = 3;
						}
						else if (i == 4) {
							this->page = 4;
						}
					}

				}

			}
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
