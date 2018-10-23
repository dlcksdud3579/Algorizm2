#pragma once
#include "Llist.h"

class AdjList
{

protected:
	Llist ** rowList;
	int rowNum;

public:
	AdjList(int _rowNum);
	virtual void InsertNode(int rowNum, Node* inPutNode);
	string toString();
	Llist* getList(int _rowNum);
	
	~AdjList();
};

