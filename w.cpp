//============================================================================
// Name        : testingForSMS.cpp
// Author      : Aaron Mkandawire
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*
 * Class definition
 */
class LinkedList
{
public:
	LinkedList();
	void populate();
	void makeBackUp();
	void append(int value);
	void insert(int value);
	int search(int query);
	void displayNodes();
	short getSize();
	void clear();

private:
	struct Node
	{
		int data;
		Node* next;
	};

	Node* headPtr;
	short size;
	void insertInternal(int value);
};

/*
 * Class implementation
 */
LinkedList::LinkedList()
{
	this->headPtr = nullptr;
	this->size = 0;
	this->populate();

}

void LinkedList::populate()
{
	int temp = -1; //-1 is the test bit

	fstream fileHandler("file.bin", ios::binary | ios::in);

	/*
	 * check if file exits
	 */
	if(fileHandler.fail())
	{
		return;
	}else
	{
		fileHandler.read(reinterpret_cast<char*>(&temp), sizeof(int));
		cout << temp << endl;
		/*
		 * The case below test if the value assigned to temp is still in temp
		 * if so it means nothing was read into the variable from the file.
		 * additionally if the eofbit is set, that means we have reached the end of file
		 * but since we had no input it means the file is blank
		 */
		if(temp == -1 && fileHandler.eof())
		{
			cout << "File is blank" << endl;
			return;
		}else
		{
			this->insertInternal(temp);
			/*
			 * while the eof has not arrived read in data into the list
			 */
			while(!fileHandler.eof())
			{
				fileHandler.read(reinterpret_cast<char*>(&temp), sizeof(int));
				if(fileHandler.eof())
				{
					break;
				}
				this->insertInternal(temp);
				cout << "In populate right after the insert() call." << endl;
				/*
				 * if the iof has arrived break
				 */

				cout << temp << endl;
			}
		}
	}
}

void LinkedList::makeBackUp()
{
	if(this->headPtr == nullptr)
	{
		return;
	}else
	{
		Node* nodePtr = headPtr;
		fstream fileHandler("backup/backup.bin", ios::binary | ios::out);

		while(nodePtr != nullptr)
		{
			fileHandler.write(reinterpret_cast<char*>(&nodePtr->data), sizeof(int));
			nodePtr = nodePtr->next;
		}

		fileHandler.close();
	}
}
void LinkedList::insertInternal(int value)
{
	/*
	 * Create and initialize the new Node
	 */

	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;

	/*
	 * if the headPtr is empty it means the list is empty as well.
	 */

	if(this->headPtr == nullptr)
	{
		this->headPtr = newNode;
	}else
	{

		Node* nodePtr = headPtr;
		Node* previousNode = nullptr;

		/*
		 * The loop below seeks through the list until it finds the first
		 * node whose value is greater than or equal to the new node's value.
		 */
		while(nodePtr != nullptr && (nodePtr->data < value) )
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		/*
		 * The case below executes when the new node will be first
		 * ==============================================================
		 * BEG					ANYWHERE BETWEEN 					END
		 * ==============================================================
		 */

		if(previousNode == nullptr)
		{
			headPtr = newNode;
			headPtr->next = nodePtr;

		/*
		 * The case below will execute when the new node needs to be inserted
		 * anywhere between the first node and the last node.
		 */
		}else if(nodePtr != nullptr)
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;

		/*
		 * The case below will execute when the new node needs to be inserted
		 * at the end of the list
		 */
		}else
		{
			previousNode->next = newNode;
			newNode->next = nullptr;
		}
	}
	this->size++;
}

void LinkedList::insert(int value)
{
	/*
	 * Create and initialize the new Node
	 */

	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;

	/*
	 * if the headPtr is empty it means the list is empty as well.
	 */

	if(this->headPtr == nullptr)
	{
		this->headPtr = newNode;

		/*
		 * write data to file
		 */
		fstream fileHandler("file.bin", ios::binary | ios::out | ios::app);
		fileHandler.write(reinterpret_cast<char*>(&newNode->data), sizeof(int));
		fileHandler.close();
	}else
	{

		Node* nodePtr = headPtr;
		Node* previousNode = nullptr;

		/*
		 * The loop below seeks through the list until it finds the first
		 * node whose value is greater than or equal to the new node's value.
		 */
		while(nodePtr != nullptr && (nodePtr->data < value) )
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		/*
		 * The case below executes when the new node will be first
		 * ==============================================================
		 * BEG					ANYWHERE BETWEEN 					END
		 * ==============================================================
		 */

		if(previousNode == nullptr)
		{
			headPtr = newNode;
			headPtr->next = nodePtr;
			/*
			 * write data to file
			 */
			fstream fileHandler("file.bin", ios::binary | ios::out | ios::app);
			fileHandler.write(reinterpret_cast<char*>(&newNode->data), sizeof(int));
			fileHandler.close();

		/*
		 * The case below will execute when the new node needs to be inserted
		 * anywhere between the first node and the last node.
		 */
		}else if(nodePtr != nullptr)
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
			/*
			 * write data to file
			 */
			fstream fileHandler("file.bin", ios::binary | ios::out | ios::app);
			fileHandler.write(reinterpret_cast<char*>(&newNode->data), sizeof(int));
			fileHandler.close();

		/*
		 * The case below will execute when the new node needs to be inserted
		 * at the end of the list
		 */
		}else
		{
			previousNode->next = newNode;
			newNode->next = nullptr;
			/*
			 * write data to file
			 */
			fstream fileHandler("file.bin", ios::binary | ios::out | ios::app);
			fileHandler.write(reinterpret_cast<char*>(&newNode->data), sizeof(int));
			fileHandler.close();
		}
	}
	this->size++;
}

void LinkedList::displayNodes()
{
	Node* nodePtr = nullptr;

	if(this->headPtr == nullptr)
	{
		cout << "No elements available." << endl;
	}else
	{
		nodePtr = this->headPtr;

		while(nodePtr != nullptr)
		{
			cout << "In display nodes." << endl;
			cout << nodePtr->data << endl;
			nodePtr = nodePtr->next;
		}
	}
}

short LinkedList::getSize()
{
	return this->size;
}

void LinkedList::clear()
{
	Node* nodePtr = nullptr;

	if(this->headPtr == nullptr)
	{
		return;
	}else
	{
		Node* previousNode = nullptr;
		nodePtr = this->headPtr;

		while(nodePtr != nullptr)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;

			delete previousNode;
		}

		/*
		 * Reset the values
		 */
		this->headPtr = nullptr;
		this->size = 0;
	}
}
int LinkedList::search(int query)
{
	if(this->headPtr == nullptr)
	{
		return -1;
	}else
	{
		Node* nodePtr = this->headPtr;

		/*
		 * While the end of the loop has not arrived and while the result has not been found
		 * 	go to the next node.
		 */

		while(nodePtr != nullptr  && (nodePtr->data != query))
		{
			nodePtr = nodePtr->next;
		}

		/*
		 * The loop will only break if one or both of the conditions are false
		 * if the first condition causes the loop to break, nullptr will be returned
		 * Otherwise, if the second condition causes the loop to break then the data will be returned.
		 */

		if(nodePtr == nullptr)
		{
			return -1;
		}else
		{
			return nodePtr->data;
		}
	}
}
/*
 * Main Application
 */

int main() {


	LinkedList* list = new LinkedList();

	list->displayNodes();

	list->insert(45);
	list->insert(4);
	list->insert(56);

	list->displayNodes();



	list->clear();
	delete list;

	return 0;
}




