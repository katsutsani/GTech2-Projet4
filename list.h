#pragma once
#include <vector>
#include "product.h"

class list {
	protected:
		vector<product> liste;
	public:
		list();
		~list();
		void addToThelist(product, int);
		void removeToThelist(product);
};