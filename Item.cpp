#include "Item.h"
using namespace std;

Item::Item()
{
	itemID = " ";
	itemName = " ";
	itemType = " ";
	itemPrice = 0;
	itemQuantity = 0;

}

Item::~Item()
{

}

void Item::setItemID(string ID) {
	itemID = ID;
}

void Item::setItemName(string name)
{
	itemName = name;
}

void Item::setItemType(string type)
{
	itemType = type;
}

void Item::setItemPrice(double price)
{
	itemPrice = price;
}

void Item::setItemQuantity(int quantity)
{
	itemQuantity = quantity;
}

void Item::setArrivalDate(string aDate)
{
	arrivalDate = aDate;
}

void Item::setExpireDate(string eDate)
{
	expireDate = eDate;
	
}

string Item::getItemID()
{
	return itemID;
}

string Item::getItemName()
{
	return itemName;
}

string Item::getItemType()
{
	return itemType;
}

double Item::getItemPrice()
{
	return itemPrice;
}

int Item::getItemQuantity()
{
	return itemQuantity;
}

string Item::getArrivalDate()
{
	return arrivalDate;
}

string Item::getExpireDate()
{
	return expireDate;
}