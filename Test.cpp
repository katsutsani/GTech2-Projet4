#include "Window.h"
#include "list.h"
#include "product.h"
#include <iostream>
#include <SDL.h>
#include <stdio.h>

using namespace std;



int main(int argc, char* args[])
{
    MainSDLWindow maFenetre;
    maFenetre.Init("Jesus", 680, 420);
    product biberon("biberon",40);
    product test("test", 40);
    list shoplist;
    cout << biberon.getName() << endl;
    shoplist.addToThelist(biberon,4);
    shoplist.addToThelist(test, 4);
    shoplist.showlist();
    shoplist.removeToThelist("test");
    shoplist.showlist();
    return 0;
}