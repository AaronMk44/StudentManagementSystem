//===============================================================================|
// Name        : LinkedList.cpp												     |
// Author      : Aaron Mkandawire											     |
// Date		   : 20th December, 2020 to 8th January, 2021					     |
//===============================================================================|
// Description : Class Implementation for the LinkList Data structure modeled 	 |
//				 to the Student Management System.							     |
//===============================================================================|

#include <fstream>
#include "LinkedList.h"

namespace LL
{
	const string DB_FILE_NAME = "database/private/ZICTC_DB.db";
	const string BACKUP_DIR = "database/backups/";
}

LinkedList::LinkedList()
{
	this->headPtr = nullptr;
	this->size = 0;
	this->populate();
}

bool LinkedList::isEmpty()
{
	return (this->headPtr == nullptr) ? true: false;
}

short LinkedList::getSize()
{
	return this->size;
}

void LinkedList::populate()
{
	Student temp;
	temp.setFirstName("test");

	ifstream fileHandler(LL::DB_FILE_NAME.c_str());

	/*
	 * check if file exits
	 */
	if(fileHandler.fail())
	{
		return;
	}else
	{
		temp.deserialize(fileHandler);
		/*
		 * The case below test if the value assigned to temp by the no arg-construtor is still in temp
		 * if so it means nothing was read into the variable from the file.
		 * additionally if the eofbit is set, that means we have reached the end of file
		 * but since we had no input it means the file is blank
		 */

		if(temp.getFirstName() == "" && fileHandler.eof())
		{
			return;
		}else
		{
			this->insertInternal(temp);
			/*
			 * while the eof has not arrived read in data into the list
			 */
			while(!fileHandler.eof())
			{
				temp.deserialize(fileHandler);
				if(fileHandler.eof())
				{
					break;
				}
				this->insertInternal(temp);
			}
		}
	}
}

void LinkedList::insertInternal(const Student& obj)
{
	/*
	 * Create and initialize the new Node
	 *
	 * We use the Copy constructor on the Student because we want to create an object
	 * dynamically and initialize it to the data retrieved from the file
	 * on the fly
	 */
	Node* newNode = new Node;
	newNode->prevNodePtr = nullptr;
	newNode->data = new Student(obj);
	newNode->nextNodePtr = nullptr;

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
		while(nodePtr != nullptr && (nodePtr->data->getStudentId() < newNode->data->getStudentId()) )
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->nextNodePtr;
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
			headPtr->nextNodePtr = nodePtr;
			nodePtr->prevNodePtr = newNode;

		/*
		 * The case below will execute when the new node needs to be inserted
		 * anywhere between the first node and the last node.
		 */
		}else if(nodePtr != nullptr)
		{
			previousNode->nextNodePtr = newNode;

			newNode->prevNodePtr = previousNode;
			newNode->nextNodePtr = nodePtr;

			nodePtr->prevNodePtr = newNode;

		/*
		 * The case below will execute when the new node needs to be inserted
		 * at the end of the list
		 */
		}else
		{
			previousNode->nextNodePtr = newNode;

			newNode->prevNodePtr = previousNode;
			newNode->nextNodePtr = nullptr;
		}
	}
	this->size++;
}

void LinkedList::insert(Student* obj)
{
	/*
	 * Create and initialize the new Node
	 */

	Node* newNode = new Node;
	newNode->prevNodePtr = nullptr;
	newNode->data = obj;
	newNode->nextNodePtr = nullptr;

	/*
	 * if the headPtr is empty it means the list is empty as well.
	 */

	if(this->headPtr == nullptr)
	{
		this->headPtr = newNode;

		ofstream fileHandler(LL::DB_FILE_NAME.c_str(), ios::out);
		newNode->data->serialize(fileHandler);
		fileHandler.close();
	}else
	{

		Node* nodePtr = headPtr;
		Node* previousNode = nullptr;

		/*
		 * The loop below seeks through the list until it finds the first
		 * node whose value is greater than or equal to the new node's value.
		 */
		while(nodePtr != nullptr && (nodePtr->data->getStudentId() < newNode->data->getStudentId()) )
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->nextNodePtr;
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
			headPtr->nextNodePtr = nodePtr;

			nodePtr->prevNodePtr = newNode;

			ofstream fileHandler(LL::DB_FILE_NAME.c_str(), ios::out | ios::app);
			newNode->data->serialize(fileHandler);
			fileHandler.close();

		/*
		 * The case below will execute when the new node needs to be inserted
		 * anywhere between the first node and the last node.
		 */
		}else if(nodePtr != nullptr)
		{
			previousNode->nextNodePtr = newNode;

			newNode->prevNodePtr = previousNode;
			newNode->nextNodePtr = nodePtr;

			nodePtr->prevNodePtr = newNode;

			ofstream fileHandler(LL::DB_FILE_NAME.c_str(), ios::out | ios::app);
			newNode->data->serialize(fileHandler);
			fileHandler.close();

		/*
		 * The case below will execute when the new node needs to be inserted
		 * at the end of the list
		 */
		}else
		{
			previousNode->nextNodePtr = newNode;

			newNode->prevNodePtr = previousNode;
			newNode->nextNodePtr = nullptr;

			ofstream fileHandler(LL::DB_FILE_NAME.c_str(), ios::out | ios::app);
			newNode->data->serialize(fileHandler);
			fileHandler.close();
		}
	}
	this->size++;
}

void LinkedList::clearList()
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
			nodePtr = nodePtr->nextNodePtr;

			delete previousNode->data;			//for Student obj
			delete previousNode;				//for Node obj
		}

		/*
		 * Reset the values
		 */
		this->headPtr = nullptr;
		this->size = 0;
	}
}

Student* LinkedList::search(const string& studentID)
{
	if(this->headPtr == nullptr)
	{
		return nullptr;
	}else
	{
		Node* nodePtr = this->headPtr;

		/*
		 * While the end of the loop has not arrived and while the result has not been found
		 * 	go to the next node.
		 */

		while(nodePtr != nullptr  && (nodePtr->data->getStudentId() != studentID))
		{
			nodePtr = nodePtr->nextNodePtr;
		}

		/*
		 * The loop will only break if one or both of the conditions are false
		 * if the first condition causes the loop to break, nullptr will be returned
		 * Otherwise, if the second condition causes the loop to break then the data will be returned.
		 */
		if(nodePtr == nullptr)
		{
			return nullptr;
		}else
		{
			return nodePtr->data;
		}
	}
}

void LinkedList::updateDB()
{
	if(this->headPtr == nullptr)
	{
		ofstream fileUpdateHandler(LL::DB_FILE_NAME.c_str(), ios::out | ios::trunc);
		fileUpdateHandler.close();
	}else
	{
		Node* nodePtr = this->headPtr;
		ofstream fileUpdateHandler(LL::DB_FILE_NAME.c_str(), ios::out);

		while(nodePtr != nullptr)
		{
			nodePtr->data->serialize(fileUpdateHandler);
			nodePtr = nodePtr->nextNodePtr;
		}
		fileUpdateHandler.close();
	}
}

void LinkedList::deleteNode(const string& studentID)
{
	if(this->headPtr == nullptr)
	{
		return;
	}

	Node* nodePtr = nullptr;
	Node* previousNode = nullptr;

	if(this->headPtr->data->getStudentId() == studentID)
	{
		nodePtr = this->headPtr;
		this->headPtr = this->headPtr->nextNodePtr;

		delete nodePtr;
		this->size--;

		if(headPtr != nullptr)
		{
			this->headPtr->prevNodePtr = nullptr;
		}
		this->updateDB();
	}else
	{
		nodePtr = headPtr;

		//Skip all value which don't match the query
		while(nodePtr != nullptr && nodePtr->data->getStudentId() != studentID)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->nextNodePtr;
		}

		if(nodePtr->nextNodePtr != nullptr)
		{
			previousNode->nextNodePtr = nodePtr->nextNodePtr;
			nodePtr->nextNodePtr->prevNodePtr = previousNode;

			delete nodePtr;
			this->size--;
			this->updateDB();
		}else
		{
			delete nodePtr;
			this->size--;
			previousNode->nextNodePtr = nullptr;
			this->updateDB();
		}
	}
}

Node* LinkedList::getAllNodeData()
{
	if(this->headPtr == nullptr)
	{
		return nullptr;
	}
	return this->headPtr;

}

void LinkedList::makeBackup(string& fileName)
{
	if(this->headPtr == nullptr)
	{
		ofstream fileUpdateHandler((LL::BACKUP_DIR+fileName).c_str(), ios::out | ios::trunc);
		fileUpdateHandler.close();
	}else
	{
		Node* nodePtr = this->headPtr;
		ofstream fileUpdateHandler((LL::BACKUP_DIR+fileName).c_str(), ios::out);

		while(nodePtr != nullptr)
		{
			nodePtr->data->serialize(fileUpdateHandler);
			nodePtr = nodePtr->nextNodePtr;
		}
		fileUpdateHandler.close();
	}
}

void LinkedList::restoreBackup(string& fileName)
{
	ifstream dbRestoreHandler((LL::BACKUP_DIR+fileName).c_str(), ios::in);
	if(dbRestoreHandler.fail())
	{
		return;
	}else
	{
		ofstream fileUpdateHandler(LL::DB_FILE_NAME.c_str(), ios::out);
		Student tempStudent;

		tempStudent.deserialize(dbRestoreHandler);
		tempStudent.serialize(fileUpdateHandler);

		while(!dbRestoreHandler.eof())
		{
			tempStudent.deserialize(dbRestoreHandler);
			if(dbRestoreHandler.eof())
			{
				break;
			}
			tempStudent.serialize(fileUpdateHandler);
		}
		this->populate();
		fileUpdateHandler.close();
	}
	dbRestoreHandler.close();
}
