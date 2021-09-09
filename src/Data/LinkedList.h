//===============================================================================|
// Name        : LinkedList.h												     |
// Author      : Aaron Mkandawire											     |
// Date		   : 20th December, 2020 to 8th January, 2021					     |
//===============================================================================|
// Description : Class definition for the LinkList Data structure modeled to the |
//				 Student Management System.									     |
//===============================================================================|

#include <iostream>
#include "Student.h"
#include "Node.h"

#ifndef STUDENTLIST_H
#define STUDENTLIST_H

/*
 * Class Definition
 */
class LinkedList
{
public:
	LinkedList();

	bool isEmpty();
	short getSize();
	void populate();
	void insert(Student* obj);
	void updateDB();
	void clearList();
	void deleteNode(const string& studentID);
	Student* search(const string& studentID);
	Node* getAllNodeData();
	void makeBackup(string& fileName);
	void restoreBackup(string& fileName);
private:
	Node* headPtr;
	short size;

	void insertInternal(const Student& obj);
};

#endif
