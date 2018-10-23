#pragma once
#include "Node.h"
class MFNode : public Node
{
private:
	int capacity;
	int flow;
	MFNode* budy;
public:
	MFNode(int _nodeNum, int _capacity, int _flow);
	virtual string toString();
	int getCapacity() { return this->capacity; }
	void setCapacity(int _capacity) {  this->capacity = _capacity; }
	int getFlow() { return this->flow;}
	void setFlow(int _flow) { this->flow = _flow; }

	void setbudy(MFNode* _budy) { this->budy = _budy; }
	MFNode* getbudy() { return  this->budy; }
	~MFNode();
};

