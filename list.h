#pragma once
#include <vector>
#include "product.h"
using namespace std;

class list {
	protected:
		vector<product> liste;
	public:
		list();
		~list();
		void addToThelist(product, int);
		void removeToThelist(const char*);
		void showlist();
};