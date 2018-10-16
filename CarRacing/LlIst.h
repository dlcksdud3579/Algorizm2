#pragma once

#include "Node.h"


class Llist
{

protected:
	Node* firstNode;
	Node* endNode;

public:
	void freeList(Node *head);
	Node* getFirstNode();
	Node* getEndNode();
	virtual void InsertNode(Node *inputNode);
	string toString();
	Node* getNode(int _nodeNum);
	void clearNode();
	Llist();
	~Llist();
};

