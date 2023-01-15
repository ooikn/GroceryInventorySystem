#include <iostream>
#include <iomanip>
#include "Item.h"
#include "List.h"
#include <string>
using namespace std;

int main() {
	Item item;
	List<Item> manage;
	int select,sortSelect;
	bool exit = false;
	string itemToRestock;

	manage.readFromFile(); // read the data in the item excel file
	do {
		cout << "Welcome to Grocery Inventory System\n" // menu for the user to choose the function
			<< "1. Add item\n"
			<< "2. Display item\n"
			<< "3. Sort items\n"
			<< "4. Search items\n"
			<< "5. Restock items\n"
			<< "6. Exit\n"
			<< "Pleae select your option: ";
		cin >> select;
		cout << endl;
		while (cin.fail() || select <=0 || select > 6) // check the validation of the input
		{
			cin.clear();
			cin.ignore(10,'\n');
			cout << "Invallid Option\n"
				<< "Please select your option again : ";
			cin >> select;
			cout << endl;
		}
		if (select == 1) 
		{
			manage.addItem(); // call the addItem function in List class
			cout << "The item is added successfully!\n\n";
			
		}
		else if (select == 2) 
		{
			manage.displayItem(); //call the displayItem function in List class
		}
		else if (select == 3)
		{
			cout << "Sort Condition:\n"
				<< "1. Item ID\n"
				<< "2. Item Name\n"
				<< "3. Item Price(RM)\n"
				<< "4. Item Quantity\n"
				<<"Please select the sort condition: ";
			cin >> sortSelect;
			while (cin.fail() || select <= 0 || select > 4) // check the validation of the input
			{
				cin.clear();
				cin.ignore(10, '\n');
				cout << "Invallid Option\n"
					<< "Please select your sort condition again : ";
				cin >> select;
				cout << endl;
			}
			manage.sortItems(sortSelect); // call sort function to sort the items
			cout << "The items are sorted successfully!\n";
			cout << endl;
			
			
		}
		else if (select == 5) { 
			if (manage.numberOfItem() == 0) { // check if the inventory is empty
				cout << "There is no item in the inventory!" << endl << endl;
			}
			else {
				cout << "Enter the itemID or itemName of the item you wish to restock: "; // allow user to input the quantity to restock
				getline(cin, itemToRestock);
				cout << endl;
				if (manage.restockItems(itemToRestock) == false) { // no item match
					cout << "No item match your description!\n\n";
				}
			}
		}
		else {
			cout << "The system success to exit!\n";
			exit = true;
		}
	} while (!exit);
	manage.writeToFile(); // insert the data into item excel file
	cout << "You can check the details in item excel file!\n\n";
	return 0;
}
