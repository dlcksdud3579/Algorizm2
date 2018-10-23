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

MFAdjList* adjList;// 그래프 
Queue* Q; // 큐
BTList* bTList;
 //minList;// 최소리스트;

void inputFile(int *nodeNum, int *edgeNum);

void bfs(const int nodeNum, int start);


int main()
{
	
	int nodeNum;
	int edgeNum,maxflow = 0;
	inputFile(&nodeNum,&edgeNum);
	int size = adjList->getList(0)->size();
	color = new int[nodeNum + 1];
	p = new int[nodeNum + 1];
	d = new int[nodeNum + 1];
	Q = new Queue();
	bTList = new BTList();

	while (p[nodeNum] != -1)
	{
		bfs(nodeNum, 0);
		for (int i = 0; i<= nodeNum; i++)
		{
		//cout<<p[i]<<" ";
		}
		//cout<< endl;
	
		printTop(nodeNum);
		//cout << adjList->toString() << endl;
		
	}
	MFNode* hNode = dynamic_cast<MFNode*>(adjList->getList(0)->getFirstNode());
	while (hNode != nullptr)
	{
		maxflow += hNode->getFlow();
		hNode = dynamic_cast<MFNode*>(hNode->getNextNode());
	}

	
	
	if (size <= maxflow)
	{
		cout << "START:" << size << " = MAX:" << maxflow << endl;
		cout << "escape success!!";
	}
	else
	{
		cout << "START:" << size << "\t!=\tMAX:" << maxflow << endl;
		cout << "escape fail!!";
	}
	

	
	delete(p);
	delete(d);
	delete(Q);
	delete(bTList);
	delete(adjList);
	return 0;
}

void bfs(const int nodeNum,int start)
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
	Q->enQueue(new Node(start));
	while (Q->getFirstNode() != NULL)
	{
		int u = Q->getFirstNode()->getNodeNum();
		MFNode* hnode = dynamic_cast<MFNode* >(adjList->getList(u)->getFirstNode()) ;
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
				Q->enQueue(new Node(v));
			}
			hnode = dynamic_cast<MFNode*>( hnode->getNextNode());
		}
		Q->deQueue();
		color[u] = BLACK;
	}

	Q->clearNode();
}

void inputFile(int *nodeNum, int *edgeNum)
{

	string tempStr;
	int *tmpInput  = new int[3];
	int i = 1;
	ifstream inFile = ifstream("Text.txt");
	inFile >> tempStr;
	*nodeNum = stoi(tempStr) + 1;
	inFile >> tempStr;
	*edgeNum = stoi(tempStr);

	adjList = new MFAdjList(*nodeNum +1);


	i = 1;
	while (!inFile.eof())
	{
		inFile >> tempStr;
		tmpInput[0] = stoi(tempStr);
		inFile >> tempStr;
		tmpInput[1] = stoi(tempStr);
		inFile >> tempStr;
		tmpInput[2] = stoi(tempStr);


		MFNode *node = new MFNode(tmpInput[1], tmpInput[2], 0);
		adjList->InsertNode(tmpInput[0], node);
	}
	
	 //cout<< adjList->toString()<<endl;
}

void printTop(int n)
{
	int blockNum = 0;
	int index = n;
	blockNum++;

	while (p[index] != -1)
	{
		p[index];
		MRNode *mRNode = new MRNode(0, dynamic_cast<MFNode*>(adjList->getList(index)->getNode(p[index]))->getbudy());
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

