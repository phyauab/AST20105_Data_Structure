#ifndef showList_H
#define showList_H
#include "showNode.h"

class showList {
public:
	showNode *head;
	int numOfNodes = 0;
public:
	showList();
	~showList();
	bool isEmpty();
	void printList();
	void insertRecord(); //function to insert a batch of record, not one single record
	void searchById(string id);
	void searchByType(string type);
	void searchByTitle(string title);
	void searchByYear(int year);
	void searchByRunTimeMinutes(string min);
	void searchByGenre(string genre);
	void searchWithMultiples(string type, string title, string year, string min, string genre);
	void deleteById(string id);
	void deleteByType(string type);
	void deleteByTitle(string title);
	void deleteByYear(int year);
	void deleteByRunTimeMinutes(string min);
	void deleteByGenre(string genre);
	void modify();
	void stat();
};
#endif // !showNode_H

