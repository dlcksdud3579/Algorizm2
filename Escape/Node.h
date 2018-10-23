#pragma once
#include <string>
#include <sstream>
using namespace std;

class Node
{
public:
	
	void connNextNode(Node *nextNodePtr);
	Node *getNextNode();
	void setNextNode(Node* _next);
	int getNodeNum() { return this->nodeNum; }
	void setNodeNum(int _nodeNum) {this->nodeNum = _nodeNum;}
	int getEdgeNum() { return this->edgeNum; }
	void getEdgeNum(int _edgeNum) { this->edgeNum = _edgeNum; }
	virtual string toString();
	Node(int rowNum ,int _nodeNum , int edgeNum);
	Node();
	~Node();

protected:
	Node* next;
	int rowNum;
	int nodeNum;
	int edgeNum;
	
};

