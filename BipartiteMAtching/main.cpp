#include <iostream>
#include <fstream>
#include <string>
#include "AdjList.h"
#include "stdlib.h"

#include <iostream>
#include <fstream>
#include <string>
#include "MFAdjList.h";
#include "Queue.h";
#include "MFNode.h";
#include "MRNode.h";
#include "BTList.h" 

#define infinity 50000000
#define NIL -1;

enum COLOR { WHITE, GRAY, BLACK };
using namespace std;

void printTop(int n);
int* color = NULL;
int* p = NULL;
int* d = NULL;

MFAdjList* mfadjList;
Queue* Q; // ť
BTList* bTList;

void inputFile2(int *nodeNum, int *edgeNum);

void bfs(const int nodeNum, int start);


int main()
{
	int size;
	int * matrix = NULL;
	int Nodecnt = 1;
	int cnt = 0;;
	ofstream oF = ofstream("output.txt");
	int nodeNum;
	int edgeNum, maxflow = 0;


	inputFile2(&nodeNum, &edgeNum);
	color = new int[nodeNum + 1];
	p = new int[nodeNum + 1];
	d = new int[nodeNum + 1];
	Q = new Queue();
	bTList = new BTList();

	while (p[nodeNum] != -1)
	{
		bfs(nodeNum, 0);
		for (int i = 0; i <= nodeNum; i++)
		{
			//cout<<p[i]<<" ";
		}
		//cout<< endl;

		printTop(nodeNum);
		//cout << adjList->toString() << endl;

	}
	MFNode* hNode = dynamic_cast<MFNode*>(mfadjList->getList(0)->getFirstNode());
	while (hNode != nullptr)
	{
		maxflow += hNode->getFlow();
		hNode = dynamic_cast<MFNode*>(hNode->getNextNode());
	}

	size = mfadjList->getList(0)->size();


	cout << "MAX Flow is  " << maxflow << endl;
	//if (size <= maxflow)
	//{
	//	cout << "START:" << size << " = MAX:" << maxflow << endl;
	//	cout << "escape success!!";
	//}
	//else
	//{
	//	cout << "START:" << size << "\t!=\tMAX:" << maxflow << endl;
	//	cout << "escape fail!!";
	//}


	delete(p);
	delete(d);
	delete(Q);
	delete(bTList);
	delete(mfadjList);
	delete(matrix);
	return 0;
}


void inputFile2(int *nodeNum , int *edgeNum)
{

	string tempStr;
	int *tmpInput = new int[3];
	int i = 1;
	ifstream inFile = ifstream("test.txt");
	inFile >> tempStr;
	int nodeNum1 = stoi(tempStr);
	inFile >> tempStr;
	int nodeNum2 = stoi(tempStr);

	*nodeNum = nodeNum1 + nodeNum2 + 1;

	inFile >> tempStr;
	*edgeNum = stoi(tempStr);

	mfadjList = new MFAdjList(*nodeNum + 1);


	i = 1;
	while (!inFile.eof())
	{
		inFile >> tempStr;
		tmpInput[0] = stoi(tempStr);
		inFile >> tempStr;
		tmpInput[1] = stoi(tempStr) +nodeNum1;

		MFNode *node = new MFNode(tmpInput[1], 1, 0);
		mfadjList->InsertNode(tmpInput[0], node);
	}
	for (int i = 1; i <= nodeNum1; i++)
	{
		MFNode *node = new MFNode(i, 1, 0);
		mfadjList->InsertNode(0, node);
	}
	for (int i = nodeNum1+1 ; i <= nodeNum2 + nodeNum1; i++)
	{
		MFNode *node = new MFNode(*nodeNum, 1, 0);
		mfadjList->InsertNode(i, node);
	}

	//cout<< mfadjList->toString()<<endl;
}




void bfs(const int nodeNum, int start)
{
	for (int u = 0; u <= nodeNum; u++)
	{
		color[u] = WHITE;
		d[u] = infinity;
		p[u] = NIL;
	}
	color[start] = GRAY;
	d[start] = 0;
	p[start] = NIL;
	Q->enQueue(new Node(0,start,0));
	while (Q->getFirstNode() != NULL)
	{
		int u = Q->getFirstNode()->getNodeNum();
		MFNode* hnode = dynamic_cast<MFNode* >(mfadjList->getList(u)->getFirstNode());
		while (hnode != NULL)
		{
			int v = hnode->getNodeNum();

			if (hnode->getCapacity() > hnode->getFlow() && color[v] == WHITE)
			{
				color[v] = GRAY;
				d[v] = d[u] + 1;
				p[v] = u;
				if (v >= nodeNum)
				{
					Q->clearNode();
					return;
				}
				Q->enQueue(new Node(0,v,0));
			}
			hnode = dynamic_cast<MFNode*>(hnode->getNextNode());
		}
		Q->deQueue();
		color[u] = BLACK;
	}

	Q->clearNode();
}


void printTop(int n)
{
	int blockNum = 0;
	int index = n;
	blockNum++;

	while (p[index] != -1)
	{
		p[index];
		MRNode *mRNode = new MRNode(0, dynamic_cast<MFNode*>(mfadjList->getList(index)->getNode(p[index]))->getbudy());
		bTList->InsertNode(mRNode);
		index = p[index];
	}

	MRNode* hnode = dynamic_cast<MRNode*>(bTList->getFirstNode());
	MFNode* tempNode;
	int min = infinity;
	while (hnode != nullptr)
	{
		tempNode = dynamic_cast<MFNode*>(hnode->getValNode());
		if (min > (tempNode->getCapacity() - tempNode->getFlow()))
			min = tempNode->getCapacity() - tempNode->getFlow();
		hnode = dynamic_cast<MRNode*>(hnode->getNextNode());
	}

	hnode = dynamic_cast<MRNode*>(bTList->getFirstNode());
	while (hnode != nullptr)
	{
		tempNode = dynamic_cast<MFNode*>(hnode->getValNode());
		tempNode->setFlow(tempNode->getFlow() + min);
		tempNode->getbudy()->setFlow(tempNode->getbudy()->getFlow() - min);
		hnode = dynamic_cast<MRNode*>(hnode->getNextNode());
	}
	//cout << bTList->toString()<<endl;
	bTList->clearNode();
}

