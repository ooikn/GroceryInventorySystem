#include <iostream>
#include <iomanip>
#include "Item.h"
#include "List.h"
#include <string>
using namespace std;

int main() {
	Item item;
	List<Item> manage;
	int select;
	bool exit = false;
	do {
		cout << "Welcome to Grocery Inventory System\n"
			<< "1. Add item\n"
			<< "2. Display item\n"
			<< "3. Sort items\n"
			<< "4. Search items\n"
			<< "5. Restock items\n"
			<< "6. Exit\n"
			<< "Pleae select your option: ";
		cin >> select;
		cout << endl;
		while (cin.fail() || select <=0 || select > 6) {
			cin.clear();
			cin.ignore(10,'\n');
			cout << "Invallid Option\n"
				<< "Please select your option again : ";
			cin >> select;
			cout << endl;
		}
		if (select == 1)
		{
			manage.addItem();
			
		}
		else if (select == 2) 
		{
			manage.displayItem();
		}
		else if (select == 6) {
			cout << "The system success to exit!\n";
			exit = true;
		}
	} while (!exit);
	return 0;
}