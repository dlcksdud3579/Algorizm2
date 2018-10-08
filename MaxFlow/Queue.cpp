#include "Queue.h"


Queue::Queue()
{
	this->front = NULL;
	this->near = NULL;
}


Queue::~Queue()
{
	
}

void Queue::enQueue(const int value)
{
	node *hnode;
	node *newNode = new node;
	newNode->nodeNum = value;
	newNode->capacity = 0;
	newNode->flow = 0;
	newNode->next = NULL;

	if (this->front == NULL)
	{
		this->front = newNode;
		this->near = newNode;
	}
	else
	{
		this->near->next = newNode;
		this->near = newNode;
	}
}
node Queue::deQueue()
{
	node result;
	node *tempNode;
	result.next = NULL;
	result.nodeNum = 0;
	result.capacity = 0;
	result.flow = 0;
	if (this->front != NULL)
	{
		result = *(this->front);
		tempNode = this->front;
		this->front = tempNode->next;
		free(tempNode);
	}
	return result;
}