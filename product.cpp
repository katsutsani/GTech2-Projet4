#include "product.h"
#include <iostream>

using namespace std;

product::~product() {

};

product::product(const char* name, int quantity) {
	this->name = name;
	this->quantity = quantity;
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
	}

}
void product::showProductName() {
	cout << this->name << endl;
}

const char* product::getName() {
	return name;
}