#include <stdio.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include "showList.h"
using namespace std;

//constructor
showList::showList() 
{
	head = NULL;
}

//destructor
showList::~showList()
{
	showNode *currNode = head;
	showNode *nextNode = NULL;
	while (currNode != NULL)
	{
		nextNode = currNode->next;
		delete currNode;
		currNode = nextNode;
	}
}

bool showList::isEmpty() {
	return head == NULL ? true : false;
}
void showList::printList() {

	//start printing
	int total = 0;
	for (showNode *currNode = head; currNode; currNode = currNode->next)
	{
		cout << " ----------------------------------------------------------------------------------------------------" << endl;
		cout << " " <<currNode->tconst << "\t" << currNode->titleType << "\t" << currNode->primaryTitle << "\t" << currNode->startYear << "\t";
		if (currNode->runtimeMinutes == 9999)
			cout << "\\N" << "\t";
		else
			cout << currNode->runtimeMinutes << "\t";
		cout << currNode->genres[0] << " " << currNode->genres[1] << " " << currNode->genres[2];
		cout << endl;
		total++;
	}
	cout << " ----------------------------------------------------------------------------------------------------" << endl;
	cout << " There are " << total << " records" << endl;
}

//this is a function to insert a batch of data
void showList::insertRecord()
{
	string fileString = "";

	//node data;
	string id = "";
	string type = "";
	string title = "";
	string year = "";
	string time = "";
	string genre = "";
	int count = 1;
	int brac = 0;

	//test
	string line;
	string fileName;
	cout << " Please Enter a file: ";
	cin >> fileName;

	if (fileName == "-1")
		return;

	ifstream myfile(fileName);
	int flength = 0;

	//start clock
	clock_t start, end;
	start = clock();
	showNode *currNode = head;
	if (!isEmpty())
		for (; currNode->next; currNode = currNode->next);
	int i = 0;
	//
	if (myfile)  //
	{
		while (getline(myfile, line))
		{
			flength = 0;
			for (char& c : line)
			{
				flength++;
				//cout << c;

				if (c == '\t')
					count++;
				else
				{
					switch (count)
					{
					case 1:
						id += c;
						break;
					case 2:
						type += c;
						break;
					case 3:
						title += c;
						break;
					case 4:
						year += c;
						break;
					case 5:
						time += c;
						break;
					case 6:
						if (c == '"')
							brac++;
						else if (c == ',')
							genre += ' ';
						else
							genre += c;
						break;
					}
				}

				if (brac == 2 || flength == line.length())
				{
					//start inserting
					string g = "";
					showNode *newNode = new showNode(id, type, title, stoi(year), time == "\\N" ? 9999 : stoi(time), genre);

					if (isEmpty())
					{
						head = newNode;
						currNode = head;
					}
					else
					{
						currNode->next = newNode;
						currNode = currNode->next;
					}

					id = "";
					type = "";
					title = "";
					year = "";
					time = "";
					genre = "";

					count = 1;
					brac = 0;
				}
			}
		}
		myfile.close();
	}

	//end clock
	end = clock();
	double duration_sec = double(end - start) / CLOCKS_PER_SEC;
	cout << " The time taken is " << duration_sec << "s" << endl;
}

void showList::searchById(string id)
{
	//start clock
	clock_t start, end;
	start = clock();

	//start searching
	showNode *currNode = head;
	
	cout << " ----------------------------------------------------------------------------------------------------" << endl;
	for (; currNode && currNode->tconst != id; currNode = currNode->next);
	if (currNode != NULL) {
		cout << " " << currNode->tconst << "\t" << currNode->titleType << "\t" << currNode->primaryTitle << "\t" << currNode->startYear << "\t";
		if (currNode->runtimeMinutes == 9999)
			cout << "\\N" << "\t";
		else
			cout << currNode->runtimeMinutes << "\t";
		cout << currNode->genres[0] << " " << currNode->genres[1] << " " << currNode->genres[2];
		cout << endl;

	}
	else
	{
		cout << " Sorry, Record not found!" << endl;
	}

	//end clock
	end = clock();
	double duration_sec = double(end - start) / CLOCKS_PER_SEC;
	cout << " ----------------------------------------------------------------------------------------------------" << endl;
	cout << " The time taken is " << duration_sec << "s" << endl;
}

void showList::searchByType(string type)
{
	//start clock
	clock_t start, end;
	start = clock();

	showNode *currNode = head;
	int total = 0;
	
	for (; currNode; currNode = currNode->next) {
		if (currNode->titleType == type)
		{
			cout << " ----------------------------------------------------------------------------------------------------" << endl;
			cout << " " << currNode->tconst << "\t" << currNode->titleType << "\t" << currNode->primaryTitle << "\t" << currNode->startYear << "\t";
			if (currNode->runtimeMinutes == 9999)
				cout << "\\N" << "\t";
			else
				cout << currNode->runtimeMinutes << "\t";
			cout << currNode->genres[0] << " " << currNode->genres[1] << " " << currNode->genres[2];
			cout << endl;
			total++;
		}
	}
	cout << " ----------------------------------------------------------------------------------------------------" << endl;
	if (total > 0) 
		cout << " There are total " << total << " record(s) found!" << endl;
	else 
		cout << " No record is found!" << endl;
	
	//end clock
	end = clock();
	double duration_sec = double(end - start) / CLOCKS_PER_SEC;
	cout << " ----------------------------------------------------------------------------------------------------" << endl;
	cout << " The time taken is " << duration_sec << "s" << endl;
}

void showList::searchByTitle(string title)
{
	//start clock
	clock_t start, end;
	start = clock();

	//start searching
	showNode *currNode = head;
	int total = 0;

	for (; currNode; currNode = currNode->next) {
		if (currNode->primaryTitle == title)
		{
			cout << " ----------------------------------------------------------------------------------------------------" << endl;
			cout << " " << currNode->tconst << "\t" << currNode->titleType << "\t" << currNode->primaryTitle << "\t" << currNode->startYear << "\t";
			if (currNode->runtimeMinutes == 9999)
				cout << "\\N" << "\t";
			else
				cout << currNode->runtimeMinutes << "\t";
			cout << currNode->genres[0] << " " << currNode->genres[1] << " " << currNode->genres[2];
			cout << endl;
			total++;
		}
	}
	cout << " ----------------------------------------------------------------------------------------------------" << endl;
	if (total > 0)
		cout << " There are total " << total << " record(s) found!" << endl;
	else
		cout << " No record is found!" << "\n" << endl;

	//end clock
	end = clock();
	double duration_sec = double(end - start) / CLOCKS_PER_SEC;
	cout << " ----------------------------------------------------------------------------------------------------" << endl;
	cout << " The time taken is " << duration_sec << "s" << endl;
}

void showList::searchByYear(int year) 
{
	//start clock
	clock_t start, end;
	start = clock();

	//start searching
	showNode *currNode = head;
	int total = 0;

	for (; currNode; currNode = currNode->next) {
		if (currNode->startYear == year)
		{
			cout << " ----------------------------------------------------------------------------------------------------" << endl;
			cout << " " << currNode->tconst << "\t" << currNode->titleType << "\t" << currNode->primaryTitle << "\t" << currNode->startYear << "\t";
			if (currNode->runtimeMinutes == 9999)
				cout << "\\N" << "\t";
			else
				cout << currNode->runtimeMinutes << "\t";
			cout << currNode->genres[0] << " " << currNode->genres[1] << " " << currNode->genres[2];
			cout << endl;
			total++;
		}
	}
	cout << " ----------------------------------------------------------------------------------------------------" << endl;
	if (total > 0)
		cout << " There are total " << total << " record(s) found!" << endl;
	else
		cout << " No record is found!" << "\n" << endl;

	//end clock
	end = clock();
	double duration_sec = double(end - start) / CLOCKS_PER_SEC;
	cout << " ----------------------------------------------------------------------------------------------------" << endl;
	cout << " The time taken is " << duration_sec << "s" << endl;
}

void showList::searchByRunTimeMinutes(string min)
{
	//start clock
	clock_t start, end;
	start = clock();

	//start searching
	showNode *currNode = head;
	int total = 0;
	int time = 999;

	if (min == "?")
		time = 9999;
	else
		time = stoi(min);

	for (; currNode; currNode = currNode->next) {
		if (currNode->runtimeMinutes == time)
		{
			cout << " ----------------------------------------------------------------------------------------------------" << endl;
			cout << " " << currNode->tconst << "\t" << currNode->titleType << "\t" << currNode->primaryTitle << "\t" << currNode->startYear << "\t";
			if (currNode->runtimeMinutes == 9999)
				cout << "\\N" << "\t";
			else
				cout << currNode->runtimeMinutes << "\t";
			cout << currNode->genres[0] << " " << currNode->genres[1] << " " << currNode->genres[2];
			cout << endl;
			total++;
		}
	}
	cout << " ----------------------------------------------------------------------------------------------------" << endl;
	if (total > 0)
		cout << " There are total " << total << " record(s) found!" << endl;
	else
		cout << " No record is found!" << "\n" << endl;

	//end clock
	end = clock();
	double duration_sec = double(end - start) / CLOCKS_PER_SEC;
	cout << " ----------------------------------------------------------------------------------------------------" << endl;
	cout << " The time taken is " << duration_sec << "s" << endl;
}

void showList::searchByGenre(string genre)
{
	//start clock
	clock_t start, end;
	start = clock();

	//start searching
	showNode *currNode = head;
	int total = 0;

	for (; currNode; currNode = currNode->next) {

		if (currNode->genres[0] == genre || currNode->genres[1] == genre || currNode->genres[2] == genre)
		{
			cout << " ----------------------------------------------------------------------------------------------------" << endl;
			cout << " " << currNode->tconst << "\t" << currNode->titleType << "\t" << currNode->primaryTitle << "\t" << currNode->startYear << "\t";
			if (currNode->runtimeMinutes == 9999)
				cout << "\\N" << "\t";
			else
				cout << currNode->runtimeMinutes << "\t";
			cout << currNode->genres[0] << " " << currNode->genres[1] << " " << currNode->genres[2];
			cout << endl;
			total++;
		}
			
	}

	cout << " ----------------------------------------------------------------------------------------------------" << endl;
	if (total > 0)
		cout << " There are total " << total << " record(s) found!" << endl;
	else
		cout << " No record is found!" << "\n" << endl;

	//end clock
	end = clock();
	double duration_sec = double(end - start) / CLOCKS_PER_SEC;
	cout << " ----------------------------------------------------------------------------------------------------" << endl;
	cout << " The time taken is " << duration_sec << "s" << endl;
}

//method to print desired node
void showList::searchWithMultiples(string type, string title, string year, string min, string genre)
{
	int total = 0;
	//start clock
	clock_t start, end;
	start = clock();

	int time = 0;
	//start searching
	showNode* currNode = head;
	for (; currNode; currNode = currNode->next)
	{
		//check title
		if (title != "/")
		{
			if (currNode->primaryTitle != title)
				continue;
		}

		//check year
		if (year != "/")
		{
			if (currNode->startYear != stoi(year))
				continue;
		}

		//check time
		if (min != "/")
		{
			if (min == "?")
				time = 9999;
			else
				time = stoi(min);
			if (currNode->runtimeMinutes != time)
				continue;
		}

		//check type
		if (type != "/")
		{
			if (currNode->titleType != type)
				continue;
		}

		//check genre
		bool fail = false;
		if (genre != "/") {
			int flength = 0;
			string s = "";
			for (char& c : genre)
			{
				flength++;
				if (c == ' ')
				{
					if (currNode->genres[0] != s && currNode->genres[1] != s && currNode->genres[2] != s)
					{
						fail = true;
						continue;
					}
					s = "";
				}
				else if (flength == genre.length())
				{
					s += c;
					if (currNode->genres[0] != s && currNode->genres[1] != s && currNode->genres[2] != s)
					{
						fail = true;
						continue;
					}
				}
				else
					s += c;
			}
		}

		if (fail == true)
			continue;

		cout << " ----------------------------------------------------------------------------------------------------" << endl;
		cout << " " << currNode->tconst << "\t" << currNode->titleType << "\t" << currNode->primaryTitle << "\t" << currNode->startYear << "\t";
		if (currNode->runtimeMinutes == 9999)
			cout << "\\N" << "\t";
		else
			cout << currNode->runtimeMinutes << "\t";
		cout << currNode->genres[0] << " " << currNode->genres[1] << " " << currNode->genres[2];
		cout << endl;
		total++;
	}

	//end clock
	end = clock();
	double duration_sec = double(end - start) / CLOCKS_PER_SEC;
	cout << " ----------------------------------------------------------------------------------------------------" << endl;
	cout << " There are total: " << total << " records" << endl;
	cout << " The time taken is " << duration_sec << "s" << endl;


}

void showList::deleteById(string id)
{
	//start clock
	clock_t start, end;
	start = clock();

	cout << " ----------------------------------------------------------------------------------------------------" << endl;
	if (!isEmpty()) {
		showNode *currNode = head, *prevNode = NULL;

		for (; currNode && currNode->tconst != id; currNode = currNode->next)
			prevNode = currNode;

		if (currNode) {
			if (prevNode == NULL)
				head = currNode->next;
			else
				prevNode->next = currNode->next;
			delete currNode;

			cout << " " << id << " is deleted!" << endl;
		}
		else
			cout << " Record not found!" << endl;
	}
	else
		cout << " No Records" << endl;

	//end clock
	end = clock();
	double duration_sec = double(end - start) / CLOCKS_PER_SEC;
	cout << " ----------------------------------------------------------------------------------------------------" << endl;
	cout << " The time taken is " << duration_sec << "s" << endl;
}

void showList::deleteByType(string type)
{

	cout << " ----------------------------------------------------------------------------------------------------" << endl;

	//check how many nodes have the same type
	showNode *currNode = head;
	int total = 0;

	for (; currNode; currNode = currNode->next)
	{
		if (currNode->titleType == type)
		{
			total++;
		}
	}
	if (total >= 1)
	{
		cout << " There are " << total << " record(s), do you want to delete ALL? (Y/N): ";
		char choice = ' ';
		total = 0;
		cin >> choice;
		if (choice == 'Y' || choice == 'y')
		{
			// start clock
			clock_t start, end;
			start = clock();

			//start deleting
			showNode *currNode = head, *nextNode = NULL, *prevNode = NULL;
			while (currNode)
			{
				nextNode = currNode->next;
				if (currNode->titleType == type)
				{
					if (prevNode == NULL)
					{
						head = nextNode;
					}
					else
					{
						prevNode->next = nextNode;
					}
					total++;
					delete currNode;
				}
				else
				{
					prevNode = currNode;
				}
				currNode = nextNode;
				if (currNode == head)
					prevNode = NULL;
			}

			cout << " ----------------------------------------------------------------------------------------------------" << endl;
			cout << " " << total << " records deleted!" << endl;

			//end clock
			end = clock();
			double duration_sec = double(end - start) / CLOCKS_PER_SEC;
			cout << " ----------------------------------------------------------------------------------------------------" << endl;
			cout << " The time taken is " << duration_sec << "s" << endl;
		}
		else if (choice == 'N' || choice == 'n')
		{
			string id = "";
			cout << " which data do you want to delete?" << endl;
			cout << " Please Enter its ID :";
			cin >> id;
			deleteById(id);
		}
	}
	else
	{
		cout << " No record is found!" << endl;

	}
}

void showList::deleteByTitle(string title)
{
	showNode *currNode = head;
	int total = 0;

	//check num of nodes
	for (; currNode; currNode = currNode->next)
	{
		if (currNode->primaryTitle == title)
		{
			total++;
		}
	}

	if (total >= 1)
	{
		cout << " ----------------------------------------------------------------------------------------------------" << endl;
		cout << " There are " << total << " record(s), do you want to delete ALL? (Y/N): ";
		total = 0;
		char choice = ' ';
		cin >> choice;
		if (choice == 'Y' || choice == 'y')
		{
			//start clock
			clock_t start, end;
			start = clock();

			showNode *currNode = head, *prevNode = NULL;
			while (true)
			{
				currNode = head, prevNode = NULL;

				for (; currNode && currNode->primaryTitle != title; currNode = currNode->next)
					prevNode = currNode;

				if (currNode)
				{
					if (prevNode == NULL)
						head = currNode->next;
					else
						prevNode->next = currNode->next;
					total++;
					delete currNode;
				}
				else
					break;
			}

			cout << " ----------------------------------------------------------------------------------------------------" << endl;
			cout << " " << total << " records deleted!" << endl;

			//end clock
			end = clock();
			double duration_sec = double(end - start) / CLOCKS_PER_SEC;
			cout << " ----------------------------------------------------------------------------------------------------" << endl;
			cout << " The time taken is " << duration_sec << "s" << endl;
		}
		else if (choice == 'N' || choice == 'n')
		{
			string id = "";
			cout << " which data do you want to delete?" << endl;
			cout << " Please Enter its ID :";
			cin >> id;
			deleteById(id);
		}
	}
	else {
		cout << " No record is found!" << endl;

	}
}

void showList::deleteByYear(int year)
{
	showNode *currNode = head;
	int total = 0;

	for (; currNode; currNode = currNode->next)
	{
		if (currNode->startYear == year)
		{
			total++;
		}
	}

	if (total >= 1)
	{
		cout << " ----------------------------------------------------------------------------------------------------" << endl;
		cout << " There are " << total << " record(s), do you want to delete ALL? (Y/N): ";
		total = 0;
		char choice = ' ';
		cin >> choice;
		if (choice == 'Y' || choice == 'y')
		{
			//check time
			clock_t start, end;
			start = clock();

			//actual deletion
			showNode *currNode = head, *nextNode = NULL, *prevNode = NULL;
			while (currNode)
			{
				nextNode = currNode->next;
				if (currNode->startYear == year)
				{
					if (prevNode == NULL)
					{
						head = nextNode;
					}
					else
					{
						prevNode->next = nextNode;
					}
					total++;
					delete currNode;
				}
				else
				{
					prevNode = currNode;
					//cout << "prevNOde: " << prevNode->tconst << endl;
				}

				currNode = nextNode;
				//cout << "currNode to nextNode: " << currNode->tconst << endl;
				if (currNode == head)
					prevNode = NULL;
			}

			cout << " ----------------------------------------------------------------------------------------------------" << endl;
			cout << " " << total << " records deleted!" << endl;

			//end clock
			end = clock();
			double duration_sec = double(end - start) / CLOCKS_PER_SEC;
			cout << " ----------------------------------------------------------------------------------------------------" << endl;
			cout << " The time taken is " << duration_sec << "s" << endl;
		}
		else if (choice == 'N' || choice == 'n')
		{
			string id = "";
			cout << " which data do you want to delete?" << endl;
			cout << " Please Enter its year :";
			cin >> id;
			deleteById(id);
		}
	}
	else {
		cout << " No record is found!" << endl;

	}
}

void showList::deleteByRunTimeMinutes(string min)
{
	showNode *currNode = head;
	int total = 0;
	int time = 999;

	if (min == "?")
		time = 9999;
	else
		time = stoi(min);

	//check num of nodes
	for (; currNode; currNode = currNode->next)
	{
		if (currNode->runtimeMinutes == time)
		{
			total++;
		}
	}

	if (total >= 1)
	{
		cout << " ----------------------------------------------------------------------------------------------------" << endl;
		cout << " There are " << total << " record(s), do you want to delete ALL? (Y/N): ";
		char choice = ' ';
		total = 0;
		cin >> choice;
		if (choice == 'Y' || choice == 'y')
		{
			// start clock
			clock_t start, end;
			start = clock();

			//start deleting
			showNode *currNode = head, *nextNode = NULL, *prevNode = NULL;
			while (currNode)
			{
				nextNode = currNode->next;
				if (currNode->runtimeMinutes == time)
				{
					if (prevNode == NULL)
					{
						head = nextNode;
					}
					else
					{
						prevNode->next = nextNode;
					}
					total++;
					delete currNode;
				}
				else
				{
					prevNode = currNode;
				}

				currNode = nextNode;
				if (currNode == head)
					prevNode = NULL;
			}

			cout << " ----------------------------------------------------------------------------------------------------" << endl;
			cout << " " << total << " records deleted!" << endl;

			//end clock
			end = clock();
			double duration_sec = double(end - start) / CLOCKS_PER_SEC;
			cout << " ----------------------------------------------------------------------------------------------------" << endl;
			cout << " The time taken is " << duration_sec << "s" << endl;
		}
		else if (choice == 'N' || choice == 'n')
		{
			string id = "";
			cout << " which data do you want to delete?" << endl;
			cout << " Please Enter its ID :";
			cin >> id;
			deleteById(id);
		}
	}
	else {
		cout << " No record is found!" << endl;

	}

}

void showList::deleteByGenre(string genre)
{
	showNode *currNode = head;
	int total = 0;

	//search for the number of nodes
	for (; currNode; currNode = currNode->next) {
		if (currNode && currNode->genres[0]==genre || currNode->genres[1] == genre || currNode->genres[2] == genre)
			total++;
	}

	if (total >= 1)
	{
		cout << " ----------------------------------------------------------------------------------------------------" << endl;
		cout << " There are " << total << " record(s), do you want to delete ALL? (Y/N): ";
		char choice = ' ';
		total = 0;
		cin >> choice;
		if (choice == 'Y' || choice == 'y')
		{
			//start clock
			clock_t start, end;
			start = clock();

			//start deleting
			showNode *currNode = head, *nextNode = NULL, *prevNode = NULL;
			while (currNode)
			{
				nextNode = currNode->next;
				if (currNode->genres[0] == genre || currNode->genres[1] == genre || currNode->genres[2] == genre)
				{
					if (prevNode == NULL)
					{
						head = nextNode;
					}
					else
					{
						prevNode->next = nextNode;
					}
					total++;
					delete currNode;
				}
				else
				{
					prevNode = currNode;
				}

				currNode = nextNode;
				if (currNode == head)
					prevNode = NULL;
			}

			cout << " ----------------------------------------------------------------------------------------------------" << endl;
			cout << " " << total << " records deleted!" << endl;

			//end clock
			end = clock();
			double duration_sec = double(end - start) / CLOCKS_PER_SEC;
			cout << " ----------------------------------------------------------------------------------------------------" << endl;
			cout << " The time taken is " << duration_sec << "s" << endl;
		}
		else if (choice == 'N' || choice == 'n')
		{
			string id = "";
			cout << " which data do you want to delete?" << endl;
			cout << " Please Enter its ID :";
			cin >> id;
			deleteById(id);
		}
	}
	else {
		cout << " No record is found!" << endl;

	}
}

void showList::modify()
{
	//get user input
	string id = "";
	cout << " Enter the id of the record: ";
	cin >> id;

	showNode *currNode = head;
	for (; currNode; currNode = currNode->next)
	{
		if (currNode->tconst == id)
		{
			//get user input
			string type = "", title = "", year = "", runTime = "", genre = "";
			cout << " Enter the field that you want to modify ( enter / to remain unchanged ) " << endl;
			cout << " Type: ";
			cin >> type;
			cout << " Title: ";
			cin.ignore();
			getline(cin, title);
			cout << " Year: ";
			cin >> year;
			cout << " RunTime: ";
			cin >> runTime;
			cout << " Genre(s): ";
			cin.ignore();
			getline(cin, genre);

			//start clock
			clock_t start, end;
			start = clock();

			//check data / modify
			if (type != "/")
				currNode->titleType = type;
			if (title != "/")
				currNode->primaryTitle = title;
			if (year != "/")
				currNode->startYear = stoi(year);
			if (runTime != "/")
			{
				if (runTime == "?")
					runTime = "9999";
				currNode->runtimeMinutes = stoi(runTime);
			}

			if (genre != "/")
			{
				//wipe previous data
				for (int i = 0; i < 3; i++)
					currNode->genres[i] = "";

				//insert new data
				string s = "";
				int flength = 0, i = 0;
				for (char& c : genre)
				{
					flength++;
					if (c == ' ')
					{
						currNode->genres[i] = s;
						s = "";
						i++;
					}
					else if (flength == genre.length())
					{
						s += c;
						currNode->genres[i] = s;
					}
					else
					{
						s += c;
					}

				}
			}
			// if success
			cout << " ----------------------------------------------------------------------------------------------------" << endl;
			cout << " " << currNode->tconst << " is modified!" << endl;

			end = clock();
			double duration_sec = double(end - start) / CLOCKS_PER_SEC;
			cout << " ----------------------------------------------------------------------------------------------------" << endl;
			cout << " The time taken is " << duration_sec << "s" << endl;

			return;
		}
	}
	// if failed
	cout << " ----------------------------------------------------------------------------------------------------" << endl;
	cout << " Node not found!" << endl;
}

//a function to calculate stat
void showList::stat()
{
	//start clock
	clock_t start, end;
	start = clock();

	showNode *currNode = head;

	int total = 0;

	//type
	int numOfshort = 0;
	int movie = 0;
	int tvEpisode = 0;
	int tvMovie = 0;
	int tvSeries = 0;
	int tvShort = 0;
	int tvMiniSeries = 0;

	//year
	int year1800 = 0;
	int year1900 = 0;
	
	//time
	int timeShort = 0;
	int timeMedium = 0;
	int timeLong = 0;
	int timeUnknown = 0;

	//genre
	string genre[23] =
	{
		"Documentary",
		"Short",
		"Animation",
		"Comedy",
		"Horror",
		"Biography",
		"Music",
		"News",
		"Sport",
		"Fantasy",
		"War",
		"Adventure",
		"Romance",
		"Crime",
		"History",
		"Sci - Fi",
		"Action",
		"Western",
		"\\N",
		"Thriller",
		"Film - Noir",
		"Mystery",
		"Musical"
	};

	int numOfGenre[23] = { 0 };

	for (; currNode; currNode = currNode->next)
	{

		total++;
		//type
		if (currNode->titleType == "short")
			numOfshort++;
		else if (currNode->titleType == "movie")
			movie++;
		else if (currNode->titleType == "tvEpisode")
			tvEpisode++;
		else if (currNode->titleType == "tvMovie")
			tvMovie++;
		else if (currNode->titleType == "tvSeries")
			tvSeries++;
		else if (currNode->titleType == "tvShort")
			tvShort++;
		else if (currNode->titleType == "tvMiniSeries")
			tvMiniSeries;

		//year
		if (currNode->startYear < 1900)
			year1800++;
		else if (currNode->startYear >= 1900)
			year1900++;

		//time
		if (currNode->runtimeMinutes < 10)
			timeShort++;
		else if (currNode->runtimeMinutes >= 10 && currNode->runtimeMinutes < 30)
			timeMedium++;
		else if (currNode->runtimeMinutes >= 30 && currNode->runtimeMinutes <= 9000)
			timeLong++;
		else
			timeUnknown++;

		//check genre

		for (int i = 0; i < 23; i++)
		{
			for (int j=0;j<3;j++)
			{ 
				if (currNode->genres[j] == genre[i])
				{
					numOfGenre[i]++;
				}

			}
		}
	}

	//display result
	cout << " ----------------------------------------------------------------------------------------------------" << endl;
	cout << " ---------------" << endl;
	cout << "      Type      " << endl;
	cout << " ---------------" << endl;
	if (numOfshort!=0)
		cout << " short: " << numOfshort << endl;
	if (movie != 0)
		cout << " movie: " << movie << endl;
	if (tvEpisode != 0)
		cout << " tvEpisode: " << tvEpisode << endl;
	if (tvMovie != 0)
		cout << " tvMovie: " << tvMovie << endl;
	if (tvSeries != 0)
		cout << " tvSeries: " << tvSeries << endl;
	if (tvShort != 0)
		cout << " tvShort: " << tvShort << endl;
	if (tvMiniSeries != 0)
		cout << " tvMiniSeries: " << tvMiniSeries << endl;
	cout << endl;

	cout << " ---------------" << endl;
	cout << "      Year      " << endl;
	cout << " ---------------" << endl;
	cout << " 1800s - 1900s: " << year1800 << endl;
	cout << " 1900s - 2000s: " << year1900 << endl;
	cout << endl;

	cout << " ---------------" << endl;
	cout << "     Run Time   " << endl;
	cout << " ---------------" << endl;
	cout << " short length  (<10mins:) :" << timeShort << endl;
	cout << " medium length (10-29mins): " << timeMedium << endl;
	cout << " long length   (>30mins)  :" << timeLong << endl;
	cout << " unknown length (/N): " << timeUnknown << endl;
	cout << endl;

	cout << " ---------------" << endl;
	cout << "     Genres     " << endl;
	cout << " ---------------" << endl;
	for (int i = 0; i < 23; i++)
	{
		if(numOfGenre[i] != 0)
		cout << " " << genre[i] << ": " << numOfGenre[i] << endl;
	}

	//end clock
	end = clock();
	double duration_sec = double(end - start) / CLOCKS_PER_SEC;
	cout << " ----------------------------------------------------------------------------------------------------" << endl;
	cout << " The time taken is " << duration_sec << "s" << endl;

}
