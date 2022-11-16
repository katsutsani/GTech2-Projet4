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

    shoplist shoplist;

    maFenetre.Init("Jesus", 680, 420);

    shoplist.createProduct("biberon", 4);

    shoplist.createProduct("test", 4);

    shoplist.addToThelist(shoplist, "biberon",4);

    shoplist.addToThelist(shoplist, "test", 4);

    shoplist.showlist();

    shoplist.listProduct["biberon"].changeQuantity(4, '-');

    shoplist.changeQuantity(shoplist,"biberon", 5, '-');

    shoplist.showlist();

    return 0;
}


/*for (auto i = listProduct.begin(); i != listProduct.end(); i++)
{
    cout << i->second. << endl;
}*/