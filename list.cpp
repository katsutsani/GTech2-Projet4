#include "list.h"
#include<iostream>
#include<ranges>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

shoplist::shoplist() {
	
}

shoplist::~shoplist() {

}
void shoplist::createProduct(const char* name, int quantity) {
	this->listProduct[name] = product(name, quantity);
}

void shoplist::addToThelist(shoplist shoplist,const char* name, int quantity) {
	if (liste.size() == 0) {
		this->listProduct[name].changeToBuyQuantity(shoplist, quantity, '+');
		this->liste.push_back(&this->listProduct[name]);
		cout << this->listProduct[name].getName() << " a ete ajoute a la liste de course" << endl;
	}
	else {
		for (int i = 0; i < liste.size(); i++) {
			const char* productName = liste[i]->getName();
			if (productName == this->listProduct[name].getName()) {
				cout << "Cet article est deja dans la liste de course" << endl;
				return;
			}
			else {
				this->listProduct[name].changeToBuyQuantity(shoplist, quantity, '+');
				this->liste.push_back(&this->listProduct[name]);
				cout << this->listProduct[name].getName() << " a ete ajoute a la liste de course" << endl;
				return;
			}
		}
	}
	
	
}

void shoplist::changeQuantity(shoplist& shoplist,const char* name, int value,const char signe) {
	this->listProduct[name].changeToBuyQuantity(shoplist,value, signe);
}

void shoplist::removeToThelist(const char* name) {
	for (int i = 0; i < this->liste.size(); i++) {
		if (this->liste[i]->getName() == name) {
			this->liste.erase(this->liste.begin() + i);
		}
	}
}

void shoplist::showlist() {
	for (int i = 0; i < this->liste.size(); i++) {
		this->liste[i]->showProductName();
	}
}