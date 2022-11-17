#pragma once

class shoplist;

class product {
protected:
	
	int quantity;
	const char* name;
	int QuantityToBuy;
public:
	product();
	~product();
	product(const char*, int);
	void removeProduct();
	void changeQuantity(int, char);
	const char* getName();
	int getQuantity();
	int getQuantityToBuy();
	void showProductName();
	void changeToBuyQuantity(shoplist& liste,int value,const char signe);
};