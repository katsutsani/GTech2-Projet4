#pragma once

class product {
protected:
	char name;
	int quantity;

public:
	product();
	~product();
	product(char, int);
	void removeProduct();
	void changeQuantity(int, char);
};