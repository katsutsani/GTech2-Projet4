
#include "Window.h"
#include "Button.h"
#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include <SDL_ttf.h>

using namespace std;



int main(int argc, char* args[])
{
    MainSDLWindow maFenetre;
    maFenetre.Init("Baby's App :D", 820, 560); // Window size initiation

    while (maFenetre.isRunning) {  // Main loop
        maFenetre.handleEvent();
        maFenetre.render();
        maFenetre.createButton();
    }

    maFenetre.~MainSDLWindow();
    return 0;
}