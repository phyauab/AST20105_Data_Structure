//Group 21
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <sstream>
#include "showList.h"
using namespace std;

void printMainMenu()
{
	//main menu
	cout << " -----------------------" << endl;
	cout << "          Menu          " << endl;
	cout << " -----------------------" << endl;
	cout << " 1. Print Record" << endl;
	cout << " 2. Insert Record" << endl;
	cout << " 3. Search Record" << endl;
	cout << " 4. Delete Record" << endl;
	cout << " 5. Modify Record" << endl;
	cout << " 6. Show Statistics" << endl;
	cout << " -1. Exit" << endl;
	cout << " Please choose an option: ";
}

void printSearchMenu()
{
	//search menu
	cout << " -----------------------" << endl;
	cout << "          Search        " << endl;
	cout << " -----------------------" << endl;
	cout << " How do you want to search record?" << endl;
	cout << " 1. ID" << endl;
	cout << " 2. Type" << endl;
	cout << " 3. Title" << endl;
	cout << " 4. Year" << endl;
	cout << " 5. RunTime Minutes" << endl;
	cout << " 6. Genres" << endl;
	cout << " 7. Search With Multiples" << endl;
	cout << " -1. Exit" << endl;
	cout << " Please choose an option: ";
}

void deleteRecord(showList* list)
{
	int option = 0;
	//search menu
	cout << " -----------------------" << endl;
	cout << "          Delete        " << endl;
	cout << " -----------------------" << endl;
	cout << " How do you want to delete record?" << endl;
	cout << " 1. ID" << endl;
	cout << " 2. Type" << endl;
	cout << " 3. Title" << endl;
	cout << " 4. Year" << endl;
	cout << " 5. RunTime Minutes" << endl;
	cout << " 6. Genres" << endl;
	cout << " -1. Exit" << endl;
	cout << " Please choose an option: ";
	cin >> option;

	switch (option)
	{
		case 1:
		{
			string id = "";
			cout << " Enter an id: ";
			cin >> id;
			list->deleteById(id);
			break;
		}
		case 2:
		{
			string type = "";
			cout << " Enter a type: ";
			cin >> type;
			list->deleteByType(type);
			break;
		}
		case 3:
		{
			string title;
			cout << " Enter a title: ";
			cin.ignore();
			getline(cin, title);
			list->deleteByTitle(title);
			break;
		}
		case 4:
		{
			int year = 0;
			cout << " Enter a year: ";
			cin >> year;
			list->deleteByYear(year);
			break;
		}
		case 5:
		{
			string min;
			cout << " Enter the runTime: ";
			cin.ignore();
			getline(cin, min);
			list->deleteByRunTimeMinutes(min);
			break;
		}
		case 6:
		{
			string genre;
			cout << " Enter a genre: ";
			cin.ignore();
			getline(cin, genre);
			list->deleteByGenre(genre);
			break;
		}
		case -1:
			return;
	}
		
}

void searchRecord(showList* list) {

	showList subList;
	int option = 0;

	printSearchMenu();
	cin >> option;

	switch (option)
	{
		cout << "	-----------------------" << endl;
		case 1:
		{
			string id = "";
			cout << " Enter an id: ";
			cin >> id;
			list->searchById(id);
			break;
		}
		case 2:
		{
			string type = "";
			cout << " Enter a type: ";
			cin >> type;
			list->searchByType(type);
			break;
		}
		case 3:
		{
			string title;
			cout << " Enter a title: ";
			cin.ignore();
			getline(cin, title);
			list->searchByTitle(title);
			break;
		}
		case 4:
		{
			int year = 0;
			cout << " Enter a year: ";
			cin >> year;
			list->searchByYear(year);
			break;
		}
		case 5:
		{
			string input = "";
			cout << " Enter the runtime in minutes(? for unknown): ";
			cin >> input;
			list->searchByRunTimeMinutes(input);
			break;
		}
		case 6:
		{
			string genre = "";
			cout << " Enter a genre: ";
			cin.ignore();
			getline(cin, genre);
			list->searchByGenre(genre);
			break;
		}
		case 7:
		{
			string type = "";
			string title = "";
			string year = "";
			string min = "";
			string genre = "";
			cout << " Enter / for blank" << endl;
			cout << " Enter a type: ";
			cin >> type;
			cout << " Enter a title: ";
			cin.ignore();
			getline(cin, title);
			cout << " Enter a year: ";
			cin >> year;
			cout << " Enter the runtime in minutes(? for unknown): ";
			cin >> min;
			cout << " Enter genre(s): ";
			cin.ignore();
			getline(cin, genre);
			list->searchWithMultiples(type, title, year, min, genre);
			break;
		}
		case -1:
		{
			return;
		}
	}
	option = 0;
}

int main() {

	showList list;

	//get initial dataset
	list.insertRecord();

	//enter main menu and start
	while (true) {

		int option = 0;
		printMainMenu();
		cin >> option;

		switch (option)
		{
			case 1:
				list.printList();
				break;
			case 2:
				cout << " ----------------------" << endl;
				list.insertRecord();
				break;
			case 3:
				searchRecord(&list);
				break;
			case 4:
				deleteRecord(&list);
				break;
			case 5:
				list.modify();
				break;
			case 6:
				list.stat();
				break;
			case -1:
				exit(1);
		}
		option = 0;
	}

	system("pause");
	return 0;
}