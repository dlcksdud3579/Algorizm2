#include "Node.h"



Node::Node(int _nodeNum)
{
	this->next = nullptr;
	this->nodeNum = _nodeNum;
}

Node::Node()
{
	this->next = nullptr;
	this->nodeNum = 0;
}

void Node::connNextNode(Node *nextNodePtr)
{
	this->next = nextNodePtr;
}
Node* Node::getNextNode()
{
	return next;
}

string Node::toString()
{
	std::ostringstream ostr;
	ostr << this->nodeNum;
	return ostr.str();
}
void Node::setNextNode(Node* _next)
{
	this->next = _next;
}

Node::~Node()
{
}
