#pragma once
#include "AdjList.h"
#include "MfNode.h"

class MFAdjList :public AdjList
{
public:
	MFAdjList(int _rowNum);
	virtual void InsertNode(int rowNum, MFNode* inPutNode);
	~MFAdjList();
};

