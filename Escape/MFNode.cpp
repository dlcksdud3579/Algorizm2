#include "MFNode.h"

MFNode::MFNode(int rowNum,int _nodeNum,int _capacity):Node(rowNum,_nodeNum, _capacity)
{
	this->capacity = _capacity;
	this->flow = 0;
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