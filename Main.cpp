
#include "Window.h"
#include "Button.h"
#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include <SDL_ttf.h>
#include "list.h"
#include "product.h"

using namespace std;



int main(int argc, char* args[])
{
    MainSDLWindow maFenetre;
    shoplist shoplist;
    shoplist.createProduct("biberon", 1);
    shoplist.createProduct("pot_de_lait_en_poudre", 4);
    shoplist.createProduct("paquet_de_couche", 0);
    shoplist.createProduct("tetine", 0);
    maFenetre.Init("Baby's App :D", 820, 560); // Window size initiation
    shoplist.addToThelist(shoplist, "paquet_de_couche", 1);
    shoplist.addToThelist(shoplist, "tetine", 1);

    while (maFenetre.isRunning) {  // Main loop
        maFenetre.handleEvent();
        maFenetre.render(maFenetre.page,shoplist);
        maFenetre.createButton();
    }

    maFenetre.~MainSDLWindow();
    return 0;
}