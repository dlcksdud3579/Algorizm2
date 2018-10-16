#include "MFAdjList.h"



MFAdjList::MFAdjList(int _rowNum):AdjList(_rowNum)
{
}
void MFAdjList::InsertNode(int rowNum, MFNode* inPutNode)
{
	bool isbudy = false;
	MFNode *budyNode;
	MFNode *hnode = nullptr;
	
	hnode = dynamic_cast<MFNode*>(this->getList(rowNum)->getFirstNode());
	while (hnode != nullptr && isbudy == false)
	{
		if (hnode->getNodeNum() == inPutNode->getNodeNum())
		{
			isbudy = true;
			hnode->setCapacity(inPutNode->getCapacity());
			free(inPutNode);
			break;
		}
		hnode =dynamic_cast<MFNode*>(hnode->getNextNode());
	}
	if (isbudy == false)
	{
		budyNode = new MFNode(rowNum, 0, 0);
		budyNode->setbudy(inPutNode);
		inPutNode->setbudy(budyNode);
		rowList[rowNum]->InsertNode(inPutNode);
		rowList[inPutNode->getNodeNum()]->InsertNode(budyNode);
	}
}

MFAdjList::~MFAdjList()
{
}
