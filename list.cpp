#include "list.h"
#include<iostream>
#include<ranges>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

list::list() {
	
}

list::~list() {

}

void list::addToThelist(product name, int quantity) {
	this->liste.push_back(name);
}

void list::removeToThelist(const char* name) {
	for (int i = 0; i < liste.size(); i++) {
		const char* productName  = liste[i].getName();
		if (productName == name) {
			liste.erase(liste.begin() + i);
		}
	}
}

void list::showlist() {
	for (int i = 0; i < liste.size(); i++) {
		liste[i].showProductName();
	}
}