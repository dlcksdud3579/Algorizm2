#pragma once
#include "Node.h"
class MRNode :public Node
{
private:
	Node *valNode;  // ���� ���� �� ��带 ����Ű�� ������
public:
	MRNode(int _nodeNum, Node* _valNode);
	virtual string toString();
	Node * getValNode() { return this->valNode; }
	~MRNode();
};

