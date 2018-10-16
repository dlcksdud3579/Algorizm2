#pragma once
#include "Node.h"
class MRNode :public Node
{
private:
	Node *valNode;  // 실제 값이 들어갈 노드를 가르키는 포인터
public:
	MRNode(int _nodeNum, Node* _valNode);
	virtual string toString();
	Node * getValNode() { return this->valNode; }
	~MRNode();
};

