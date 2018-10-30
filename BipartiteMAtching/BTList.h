#pragma once
#include "LlIst.h"
class BTList :
	public Llist
{
public:
	BTList();
	virtual void InsertNode(Node *inputNode);
	~BTList();
};

