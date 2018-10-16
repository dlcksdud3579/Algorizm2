#include "MRNode.h"



MRNode::MRNode(int _nodeNum, Node* _valNode):Node(_nodeNum)
{
	this->valNode = _valNode;
}
string MRNode::toString()
{
	std::ostringstream ostr;
	ostr << this->nodeNum<<","<<this->valNode->toString();
	return ostr.str();
}

MRNode::~MRNode()
{
}
