#include "product.h"
#include <iostream>

using namespace std;

product::product() {
	this->name = NULL;
	this->quantity = NULL;
};

product::~product() {

};

product::product(char name, int quantity) {
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
