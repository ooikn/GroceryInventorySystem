#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <Windows.h>
#include "Item.h"
using namespace std;
#ifndef MANAGEITEM_H
#define MANAGEITEM_H

template<class t>
class List {
private:
	struct Node {
	public:
		t data;
		Node* link;
	};
	Node* pHead;
	Node* pCurr;
	Node* pTail;
	int itemNum;
	int foodNum;
	int drinkNum;

public:
	List();
	~List();
	void addItem();
	void displayItem();
	int numberOfItem();
	int numOfFood();
	int numOfDrink();
};
#endif

template <class t>
List<t>::List() {
	itemNum = 0;
	foodNum = 0;
	drinkNum = 0;
	pHead = 0;
	pCurr = 0;
	pTail = 0;
}

template <class t>
List<t>::~List() {}

template <class t>
void List<t>::addItem() {
	Node* pNew = new Node; // create a new node to store data
	Item item;
	int aDay, aMonth, aYear, eDay, eMonth, eYear,quantity;
	double price;
	string name, Id,aDate,eDate;
	char type;

	cout << "Please enter the item name: "; // allow user to input the name
	cin.ignore(10, '\n');
	getline(cin, name);
	item.setItemName(name);

	cout << "\nPlease enter the item type (F-Food / D-Drink) : "; // allow user to input the item type
	cin >> type;
	while (toupper(type) != 'F' && toupper(type) != 'D') // check the validation for type
	{
		cout << "Invalid type!\n"
			<< "Please enter the item type again: ";
		cin >> type;
	}
	if (toupper(type) == 'F') // generate item id for the type of food
	{
		foodNum++; // increment of food's number
		Id = "F-" + to_string(foodNum);
		item.setItemType("Food");
	}
	else // generate item id for the type of drink
	{
		drinkNum++; // increment of drink's number
		Id = "D-" + to_string(drinkNum);
		item.setItemType("Drink");
	}
	item.setItemID(Id);
	
	cout << "\nPlease enter the arrival date\n" // allow user to input the arrival date
		<< "Year: ";
	cin >> aYear;
	while (cin.fail() || aYear < 1900 || aYear > 9999) // check the validation of year
	{
		cin.clear();
		cin.ignore(10, '\n');
		cout << "The range of the valid year is 1900-9999\n"
			<< "Please enter the year again: ";
		cin >> aYear;
	}

	cout << "Month: ";
	cin >> aMonth;
	while (cin.fail() || aMonth < 1 || aMonth >12) // check the validation of month
	{
		cin.clear();
		cin.ignore(10, '\n');
		cout << "The range of valid month is 1-12\n"
			<< "Please enter the month again: ";
		cin >> aMonth;
	}

	cout << "Day: ";
	cin >> aDay;
	if (aMonth == 2 || aMonth == 4 || aMonth == 6 || aMonth == 9 || aMonth == 11) // check the validation of day for month those do not contain 31 days
	{
		if (aMonth == 2 ) // check the validation of day for February
		{
			if (aYear % 2 == 0) // check the validation of day for February of leap year
			{
				while (cin.fail() || aDay < 0 || aDay > 29) 
				{
					cin.clear();
					cin.ignore(10, '\n');
					cout << "The range of valid day for this month is 1-29\n"
						"Please enter the day again: ";
					cin >> aDay;
				}
			}
			else // check the validation of day for February if the year is not the leap year
			{
				while (cin.fail() || aDay < 0 || aDay > 28) 
				{
					cin.clear();
					cin.ignore(10, '\n');
					cout << "The range of valid day for this month is 1-28\n"
						"Please enter the day again: ";
					cin >> aDay;
				}
			}
			
		}
		else // check the validation of day for month those do not contain 31 days except February
		{
			while (cin.fail() || aDay < 1 || aDay > 30)
			{
				cin.clear();
				cin.ignore(10, '\n');
				cout << "The range of valid day for this month is 1-30\n"
					"Please enter the day again: ";
				cin >> aDay;
			}
		}
	}
	else // check the validation of day for month those contain 31 days
	{
		while (cin.fail() || aDay < 1 || aDay >31)
		{
			cin.clear();
			cin.ignore(10, '\n');
			cout << "The range of valid day for this month is 1-31\n"
				"Please enter the day again: ";
			cin >> aDay;
		}
	}
	aDate = to_string(aDay) + "/" + to_string(aMonth) + "/" + to_string(aYear); // convert the int date to string
	item.setArrivalDate(aDate);
	
	
	cout << "\nPlease enter the expired date\n" // allow user to input the expired date
		<< "Year: ";
	cin >> eYear;
	while (cin.fail() || eYear < 1900 || eYear < aYear) // check the validation of year whether is more than arrival date or not
	{
		cin.clear();
		cin.ignore(10, '\n');
		cout << "The range of the valid year is " << aYear << "-9999\n"
			<< "Please enter the year again: ";
		cin >> eYear;
	}

	cout << "Month: ";
	cin >> eMonth;
	do {
		if (cin.fail() || eMonth < 1 || eMonth >12) // check the validation of month
		{
			cin.clear();
			cin.ignore(10, '\n');
			cout << "The range of valid month is 1-12\n"
				<< "Please enter the month again: ";
			cin >> eMonth;
		}
		if (eYear == aYear) // check the validation of month so the month is more than arrival date if the year is the same
		{
			while (eMonth < aMonth) 
			{
				cin.clear();
				cin.ignore(10, '\n');
				cout << "The value of expired month cannot less than arrival month\n"
					<< "Please enter the month again: ";
				cin >> eMonth;
			}
		}
	} while (cin.fail() || eMonth < 1 || eMonth >12);

	cout << "Day: ";
	cin >> eDay;
	if (eMonth == 2 || eMonth == 4 || eMonth == 6 || eMonth == 9 || eMonth == 11) // check the validation of day for month those not contain 31 days
	{
		if (eMonth == 2) // check the validation of day for February
		{
			if (eYear % 2 == 0) // check the validation of February of leap year
			{
				do
				{
					if (cin.fail() || eDay < 0 || eDay > 29) 
					{
						cin.clear();
						cin.ignore(10, '\n');
						cout << "The range of valid day for this month is 1-29\n"
							"Please enter the day again: ";
						cin >> eDay;
					}
					if (eYear == aYear) // check the validation of day if year and month is same
					{
						if (eMonth == aMonth)
						{
							while (eDay < aDay)
							{
								cin.clear();
								cin.ignore(10, '\n');
								cout << "The value of expired day cannot less than or same as arrival day\n"
									<< "Please enter the day again: ";
								cin >> eDay;
							}
						}
					}
				} while (cin.fail() || eDay < 0 || eDay > 29);
			}
			else // check the validation of February which is not the leap year
			{
				do
				{
					if (cin.fail() || eDay < 0 || eDay > 28)
					{
						cin.clear();
						cin.ignore(10, '\n');
						cout << "The range of valid day for this month is 1-28\n"
							"Please enter the day again: ";
						cin >> eDay;
					}
					if (eYear == aYear) // check the validation of day if year and month is same
					{
						if (eMonth == aMonth)
						{
							while (eDay < aDay)
							{
								cin.clear();
								cin.ignore(10, '\n');
								cout << "The value of expired day cannot less than or same as arrival day\n"
									<< "Please enter the day again: ";
								cin >> eDay;
							}
						}
					}
				} while (cin.fail() || eDay < 0 || eDay > 28);
			}
		}
		else // check the validation of day for month those not contain 31 days except February
		{
			do 
			{
				if (cin.fail() || eDay < 1 || eDay > 30)
				{
					cin.clear();
					cin.ignore(10, '\n');
					cout << "The range of valid day for this month is 1-30\n"
						"Please enter the day again: ";
					cin >> eDay;
				}
				if (eYear == aYear)  // check the validation of day if year and month is same
				{
					if (eMonth == aMonth) 
					{
						while (eDay < aDay)
						{
							cin.clear();
							cin.ignore(10, '\n');
							cout << "The value of expired day cannot less than arrival day\n"
								<< "Please enter the day again: ";
							cin >> eDay;
						}
					}
				}
			} while (cin.fail() || eDay < 1 || eDay > 30);
		}
	}
	else // check the validation of day for month those contain 31 days
	{
		do
		{
			if (cin.fail() || eDay < 1 || eDay >31)
			{
				cin.clear();
				cin.ignore(10, '\n');
				cout << "The range of valid day for this month is 1-31\n"
					"Please enter the day again: ";
				cin >> eDay;
			}
			if (eYear == aYear) // check the validation of day if year and month is same
			{
				if (eMonth == aMonth) 
				{
					while (eDay < aDay)
					{
						cin.clear();
						cin.ignore(10, '\n');
						cout << "The value of expired day cannot less than or same as arrival day\n"
							<< "Please enter the day again: ";
						cin >> eDay;
					}
				}
			}
		} while (cin.fail() || eDay < 1 || eDay >31);
	}
	eDate = to_string(eDay) + "/" + to_string(eMonth) + "/" + to_string(eYear); // convert the int date to string
	item.setExpireDate(eDate);

	cout << "\nPlease enter the price of the item(RM): RM "; // allow user to input the price
	cin >> price;
	while (cin.fail() || price <= 0) // check the validation of price
	{
		cout << "Invalid price.\n"
			<< "Please enter the price(RM) again: RM ";
		cin >> price;
	}
	item.setItemPrice(price);
	
	cout << "\nPlease enter the quantity of the items: "; // allow user to input the quantity
	cin >> quantity;
	while (cin.fail() || quantity < 0) // check the validation of quantity
	{
		cout << "Invalid quantity.\n"
			<< "Please enter the quantity again: ";
		cin >> quantity;
	}
	cout << endl;
	item.setItemQuantity(quantity);

	pNew->data = item; // insert all value into data part
	if (itemNum == 0) // insert a new node into linked list if the list is empty
	{
		pNew->link = pHead;
		pHead = pNew;
		pTail = pNew;
		pCurr = pHead;
	}
	else // insert a new node into linked list if the list is not empty
	{
		pNew->link = pCurr->link;
		pCurr->link = pNew;
		pCurr = pNew;
		if (pCurr == NULL) 
		{
			pTail = pCurr;
		}
	}
	itemNum++; // increment of item's number
}

template <class t>
void List<t>::displayItem() {
	HANDLE text = GetStdHandle(STD_OUTPUT_HANDLE);
	bool warning = false;
	int numLow = 0;
	pCurr = pHead; // set the current node position to the first node

	cout << setfill('-') << setw(102) << " " << endl;
	cout << "|" << setfill(' ') << setw(10) << left << "Item ID "
		<< "|" << setfill(' ') << setw(20) << left << "Item Name "
		<< "|" << setfill(' ') << setw(8) << left << "Type "
		<< "|" << setfill(' ') << setw(15) << left << "Arrival Date "
		<< "|" << setfill(' ') << setw(15) << left << "Expired Date "
		<< "|" << setfill(' ') << setw(15) << left << "Price(RM) "
		<< "|" << setfill(' ') << setw(10) << left << "Quantity "
		<< "|" << endl;
	cout << setfill('-') << setw(102) << right << " " << endl;

	while (pCurr != 0) // display all data of linked list
	{
		if (pCurr->data.getItemQuantity() <= 5)
		{
			SetConsoleTextAttribute(text, FOREGROUND_RED | FOREGROUND_INTENSITY); // change the text colour to red if the quantity of item is less than or equal to 5
			warning = true; // record that there has item is less than or equal to 5
			numLow++;
		}

		cout << "|" << setfill(' ') << setw(10) << left << pCurr->data.getItemID()
			<< "|" << setfill(' ') << setw(20) << left << pCurr->data.getItemName()
			<< "|" << setfill(' ') << setw(8) << left << pCurr->data.getItemType()
			<< "|" << setfill(' ') << setw(15) << left << pCurr->data.getArrivalDate()
			<< "|" << setfill(' ') << setw(15) << left << pCurr->data.getExpireDate()
			<< "|" << setfill(' ') << setw(15) << fixed << setprecision(2) << left << pCurr->data.getItemPrice()
			<< "|" << setfill(' ') << setw(10) << left  << pCurr->data.getItemQuantity()
			<< "|" << endl;

		SetConsoleTextAttribute(text, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN); // change the text back to white colour
		cout << setfill('-') << setw(102) << right << " " << endl;

		pCurr = pCurr->link;
	}

	if (warning) // if there has item less than or equal to 5,show message
	{
		SetConsoleTextAttribute(text, FOREGROUND_RED | FOREGROUND_INTENSITY); // change the text to red colour
		cout << "The red line items means the quantity is low, please restock it!";
		SetConsoleTextAttribute(text, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN); // change the text back to white colour
	}
	cout << endl;

	cout << "Summary of the Details:\n"
		<< "Total Number of Items: " << itemNum << endl
		<< "Total Number of Foods: " << foodNum << endl
		<< "Total Number of Drinks: " << drinkNum << endl
		<< "Total Number of Items Which Need to Restock: " << numLow 
		<< endl << endl;
	// ignore the code under this line
	/*ofstream itemFile;
	itemFile.open("item.csv",ios::out);
	itemFile << "ID" << ","
		<< "Name" << ","
		<< "Type" << ","
		<< "Arrival Date" << "," 
		<< "Expired Date" << ","
		<< "Price(RM)" << "," 
		<< "Quantity" << endl;

	while (pCurr != 0) {
		itemFile << pCurr->data.getItemID() << ","
			<< pCurr->data.getItemName() << ","
			<< pCurr->data.getItemType() << ","
			<< pCurr->data.getArrivalDate() << ","
			<< pCurr->data.getExpireDate() << ","
			<< pCurr->data.getItemPrice() << ","
			<< pCurr->data.getItemQuantity() << endl;
		pCurr = pCurr->link;
	}
	itemFile.close();*/
}

template <class t>
int List<t>::numberOfItem() {
	return itemNum;
}

template <class t>
int List<t>::numOfFood() {
	return foodNum;
}

template <class t>
int List<t>::numOfDrink() {
	return drinkNum;
}


