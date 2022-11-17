#include "product.h"
#include "list.h"
#include <iostream>

using namespace std;

product::product() {
	this->name = NULL;
	this->quantity = NULL;
	this->QuantityToBuy = 0;
}

product::~product() {

};

product::product(const char* name, int quantity) {
	this->name = name;
	this->quantity = quantity;
	this->QuantityToBuy = 0;
};

void product::removeProduct() {
	this->~product();
};

void product::changeQuantity(int quantity, char signe) {
	switch (signe) {
	case '+':
		this->quantity = this->quantity + quantity;
	case '-':
		this->quantity = this->quantity - quantity;
		if (this->quantity <= 0) {
			cout << "Vous n'avez plus de " << this->name << " le produit a donc ete ajoute a la liste de course";
			this->QuantityToBuy = this->QuantityToBuy + 1;
		}
	}

}
int product::getQuantity() {
	return this->quantity;
}

const char* product::getName() {
	return name;
}

void product::showProductName() {
	 cout <<name <<endl;
}

void product::changeToBuyQuantity(shoplist& shoplist,int value,const char signe) {
	if (signe == '+') {
		this->QuantityToBuy = this->QuantityToBuy + value;
		cout << "New quantity to buy " << this->QuantityToBuy << endl;
	}
	else if (signe == '-') {
		this->QuantityToBuy = this->QuantityToBuy - value;
		if (this->QuantityToBuy <= 0) {
			cout << "Vous venez de supprimer cet article de la liste" << endl;
			shoplist.removeToThelist(this->name);
		}
	}
}