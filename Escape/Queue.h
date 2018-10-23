#pragma once
#include "LlIst.h"
class Queue:public Llist
{
public:
	Queue();
	~Queue();
	void enQueue( Node* newNode);
	Node deQueue();
	void clearQueue();

};

