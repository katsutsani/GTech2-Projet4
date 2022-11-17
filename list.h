#pragma once
#include <vector>
#include "product.h"
#include <unordered_map>
using namespace std;

class shoplist {
	protected:
		vector<product*> liste;
		
	public:
		unordered_map<const char*, product> listProduct;
		shoplist();
		~shoplist();
		void addToThelist(shoplist,const char*, int);
		void removeToThelist(const char*);
		void showlist();
		vector<product*> getShoplist();
		void changeQuantity(shoplist&,const char*,int,const char);
		void createProduct(const char*, int);
};