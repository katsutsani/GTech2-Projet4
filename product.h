#pragma once

class product {
protected:
	
	int quantity;

public:
	const char* name;
	~product();
	product(const char*, int);
	void removeProduct();
	void changeQuantity(int, char);
	const char* getName();
	void showProductName();
};