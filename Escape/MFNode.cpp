#include "MFNode.h"

MFNode::MFNode(int _nodeNum, int _capacity, int _flow) :Node(_nodeNum)
{
	this->capacity = _capacity;
	this->flow = _flow;
	this->budy = nullptr;
}
MFNode::~MFNode()
{

}
string MFNode::toString()
{
	std::ostringstream ostr;
	ostr << this->nodeNum<<","<<this->capacity<<","<<this->flow;
	return ostr.str();
}