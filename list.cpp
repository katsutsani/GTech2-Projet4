#include "list.h"
#include <iostream>

using namespace std;

list::list() {
	
}

list::~list() {

}

void list::addToThelist(product name, int quantity) {
	this->liste.push_back(name);
}