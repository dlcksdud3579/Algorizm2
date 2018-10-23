#include "Queue.h"


Queue::Queue()
{
	this->firstNode = NULL;
	this->endNode = NULL;
}


Queue::~Queue()
{
	
}

void Queue::enQueue(Node* newNode)
{

	if (this->firstNode == NULL)
	{
		this->firstNode = newNode;
		this->endNode = newNode;
	}
	else
	{
		this->endNode->setNextNode(newNode);
		this->endNode = newNode;
	}
}
Node Queue::deQueue()
{
	Node result;
	Node *tempNode;
	if (this->firstNode != NULL)
	{
		result = *(this->firstNode);
		tempNode = this->firstNode;
		this->firstNode = tempNode->getNextNode();
		free(tempNode);
	}
	return result;
}
void Queue::clearQueue()
{

}