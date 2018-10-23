#include "LlIst.h"

Llist::Llist()
{
	this->firstNode = nullptr;
	this->endNode = nullptr;
}

void Llist::InsertNode(Node *inputNode)
{
	if (this->firstNode == nullptr)
	{
		this->firstNode = inputNode;
		this->endNode = inputNode;
	}
	else
	{
		this->endNode->connNextNode(inputNode);
		this->endNode = inputNode;
	}
}

string Llist::toString()
{
	Node *hnode = this->firstNode;
	std::ostringstream ostr;
	while (hnode != nullptr)
	{
		ostr << hnode->toString();
		ostr << "\n";
		hnode = hnode->getNextNode();
	}
	return ostr.str();
}

Node* Llist::getFirstNode()
{
	return this->firstNode;
}

Node* Llist::getEndNode()
{
	return this->endNode;
}

Llist::~Llist()
{
}
void Llist::freeList(Node *head)
{
	if (head != NULL)
	{
		freeList(head->getNextNode());
		delete(head);
	}
	return;
}
Node* Llist::getNode(int _nodeNum)
{
	Node *hnode = this->firstNode;
	while (hnode != nullptr)
	{
		if (hnode->getNodeNum() == _nodeNum)
			return hnode;
		hnode = hnode->getNextNode();
	}
	return nullptr;
}
void Llist::clearNode()
{
	freeList(this->firstNode);
	this->firstNode = nullptr;
}
int Llist::size()
{
	int size = 0;
	Node *hnode = this->firstNode;

	while (hnode != nullptr)
	{
		size++;
		hnode = hnode->getNextNode();
	}
	return size;
}