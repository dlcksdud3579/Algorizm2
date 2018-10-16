#include "BTList.h"



BTList::BTList()
{
}

void BTList::InsertNode(Node *inputNode)
{

	Node *hnode = this->firstNode;
	inputNode->setNodeNum(1);
	while (hnode != nullptr)
	{
		hnode->setNodeNum(hnode->getNodeNum() + 1);
		hnode = hnode->getNextNode();
	}

	if (this->firstNode == nullptr)
	{
		this->firstNode = inputNode;
		this->endNode = inputNode;
	}
	else
	{
		inputNode->setNextNode(this->firstNode);
		this->firstNode = inputNode;
	}
}

BTList::~BTList()
{
}
