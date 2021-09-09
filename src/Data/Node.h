#include "Student.h"

#ifndef DATA_NODE_H_
#define DATA_NODE_H_


struct Node
{
	Node* prevNodePtr;
	Student* data;
	Node* nextNodePtr;
};

#endif /* DATA_NODE_H_ */
