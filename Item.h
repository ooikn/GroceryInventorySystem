#pragma once
#include <string>
using namespace std;

class Item {
public:
	Item(); //default constructor
	~Item(); //destructor
	void setItemID(string ID);
	void setItemName(string name);
	void setItemType(string type);
	void setItemPrice(double price);
	void setItemQuantity(int quantity);
	void setArrivalDate(string aDate);
	void setExpireDate(string eDate);
	string getItemID();
	string getItemName();
	string getItemType();
	double getItemPrice();
	int getItemQuantity();
	string getArrivalDate();
	string getExpireDate();

private:
	string itemID;
	string itemName;
	string itemType;
	double itemPrice;
	int itemQuantity;
	string arrivalDate;
	string expireDate;
};