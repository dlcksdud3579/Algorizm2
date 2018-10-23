#include "Node.h"



Node::Node(int rowNum, int _nodeNum, int edgeNum)
{
	this->next = nullptr;
	this->rowNum = rowNum;
	this->nodeNum = _nodeNum;
	this->edgeNum = edgeNum;
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
	ostr << to_string(this->rowNum);
	ostr << " ";
	ostr << to_string(this->nodeNum);
	ostr << " ";
	ostr << to_string(this->edgeNum);
	ostr << "\n";
	return ostr.str();
}
void Node::setNextNode(Node* _next)
{
	this->next = _next;
}

Node::~Node()
{
}
