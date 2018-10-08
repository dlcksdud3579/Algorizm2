#pragma once
#include "node.h"
class Queue
{
public:
	node* front;
	node* near;

	Queue();
	~Queue();
	void enQueue(const int value);
	node deQueue();

};

