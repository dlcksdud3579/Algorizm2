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

MFAdjList* adjList;// 그래프 
Queue* Q; // 큐
BTList* bTList;
//minList;// 최소리스트;
void inputFile(int *size, int **matrix);

void bfs(const int nodeNum, int start);



int imove[4];
int rmove[4];





int main()
{
	int size;
	int * matrix = NULL;
	int Nodecnt = 1;
	int cnt = 0;;
	ofstream oF = ofstream("ouput.txt");
	int nodeNum;
	int edgeNum, maxflow = 0;

	

	
	
	inputFile(&size, &matrix);
	
	nodeNum = size*size * 2 + 1;
	color = new int[nodeNum + 1];
	p = new int[nodeNum + 1];
	d = new int[nodeNum + 1];
	Q = new Queue();
	bTList = new BTList();

	imove[0] = -1;
	imove[1] = -size;
	imove[2] = 1;
	imove[3] = size;

	rmove[0] = -3;
	rmove[1] = -size * 2 - 1;
	rmove[2] = 1;
	rmove[3] = size * 2 - 1;

	adjList = new MFAdjList(size*size *2 +2);
	for (int i= 0 ;i < size*size; i++)
	{
		// i*2 +1   ->  i*2+2
		MFNode * tempNode = new MFNode(i * 2 + 1,i * 2 + 2, 1);
		int flag = 0;
		adjList->InsertNode(i * 2 + 1,tempNode);
		cnt++;
		
		// 위 아래 좌 우 확인
		for (int j = 0; j < 4; j++)
		{
			
			if (i + imove[j] >= 0 && i + imove[j] < size*size)
			{
				if (j == 0 && i % size == 0)
				{
					if (flag != 1)
					{
						MFNode * tempNode = new MFNode(i * 2 + 2,size*size * 2 + 1, 1);
						adjList->InsertNode(i * 2 + 2,tempNode);
						cnt++;
						flag = 1;
					}
					continue;
				}
				if(j == 2 && (i + imove[j]) % size == 0)
				{
					if (flag != 1)
					{
						MFNode * tempNode = new MFNode(i * 2 + 2,size*size * 2 + 1, 1);
						adjList->InsertNode(i * 2 + 2,tempNode);
						cnt++;
						flag = 1;
					}
					continue;
				}
			
				MFNode * tempNode = new MFNode(i * 2 + 2,i*2+2  + rmove[j], 1);
				adjList->InsertNode(i * 2 + 2,tempNode);
				cnt++;
			}
			else if (flag != 1)// 모서리 인경우 
			{
				MFNode * tempNode = new MFNode(i * 2 + 2,size*size * 2 + 1, 1);
				adjList->InsertNode(i * 2 + 2,tempNode);
				cnt++;
				flag = 1;
			}
		}

		if (matrix[i] == 1) // 검은점인경우 
		{
			MFNode * tempNode = new MFNode(0,i * 2 + 1, 1);
			adjList->InsertNode(0,tempNode);
			cnt++;
		}
	}
	//cout << size*size * 2 << " " << cnt << endl;
	//cout<< adjList->toString();
	//oF <<  size*size*2<<" "<<cnt<<endl;
	//oF << adjList->toString();


	size = adjList->getList(0)->size();
	while (p[nodeNum] != -1)
	{
		bfs(nodeNum, 0);
		for (int i = 0; i <= nodeNum; i++)
		{
			cout<<p[i]<<" ";
		}
		cout<< endl;

		printTop(nodeNum);
	//	cout << adjList->toString() << endl;

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
	delete(matrix);
	return 0;
}


void inputFile(int *size, int **matrix)
{

	string tempStr;
	char* tempChar;
	int i = 1;
	int j;

	
	ifstream inFile = ifstream("text.txt");
	inFile >> tempStr;
	*size = stoi(tempStr);

	*matrix = new int[(*size)*(*size)];


	for (int i = 0; i < *size; i++)
	{
		inFile>>tempStr;
		for(j = 0; j < *size; j++)
		{
			(*matrix)[i*(*size) + j] = tempStr.at(j) - '0';
		}
	}






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
		MFNode* hnode = dynamic_cast<MFNode* >(adjList->getList(u)->getFirstNode());
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

