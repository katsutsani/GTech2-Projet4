
#include "Window.h"
#include "Button.h"
#include <iostream>
#include <SDL.h>
#include <stdio.h>

using namespace std;



int main(int argc, char* args[])
{
    MainSDLWindow maFenetre;
    maFenetre.Init("Jesus", 680, 420);
    newButton course(maFenetre.GetRenderer(), 100, 50, 50, 50);
    newButton tableau(maFenetre.GetRenderer(), 50, 50, 50, 50);

    while (maFenetre.isRunning) {
        maFenetre.handleEvent();
        maFenetre.render();
    }

    maFenetre.~MainSDLWindow();
    return 0;
}