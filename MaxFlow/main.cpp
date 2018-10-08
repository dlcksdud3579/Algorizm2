#include <iostream>
#include <fstream>
#include <string>
#include "node.h";
#include "Queue.h";
#define infinity 50000000
#define NIL -1;
enum COLOR { WHITE, GRAY, BLACK };
using namespace std;

void printTop(int n);
int* color = NULL;
int* p = NULL;
int* d = NULL;

hNode *H;// 그래프 
Queue Q; // 큐
hNode minList;// 최소리스트;

void inputFile(hNode **H, int *nodeNum, int *edgeNum);

void bfs(const int nodeNum, int start);


int main()
{
	
	int nodeNum;
	int edgeNum;
	minList;
	inputFile(&H,&nodeNum,&edgeNum);
	color = new int[nodeNum + 1];
	p = new int[nodeNum + 1];
	d = new int[nodeNum + 1];
	bfs(nodeNum, 0);
	for (int i = 0; i<= nodeNum; i++)
	{
	cout<<p[i]<<" ";
	}
	cout<< endl;
	printTop(nodeNum);
	system("pause");


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
	Q.enQueue(start);
	while (Q.front != NULL)
	{
		int u = Q.front->nodeNum;
		node *hnode = H[u].firstNode;
		while (hnode != NULL)
		{
			int v = hnode->nodeNum;
			if (hnode->capacity > hnode->flow &&color[v] == WHITE)
			{
				color[v] = GRAY;
				d[v] = d[u] + 1;
				p[v] = u;
				if (v >= nodeNum)
				{
					return;
				}
				Q.enQueue(v);
			}
			hnode = hnode->next;
		}
		Q.deQueue();
		color[u] = BLACK;
	}


}
void inputFile(hNode **H, int *nodeNum, int *edgeNum)
{

	string tempStr;
	int *tmpInput  = new int[3];
	int i = 1;
	ifstream inFile = ifstream("Text.txt");
	int hNum, edgeL, nodeN, nodeW;
	inFile >> tempStr;
	*nodeNum = stoi(tempStr) + 1;
	inFile >> tempStr;
	*edgeNum = stoi(tempStr);
	*H = new hNode[*nodeNum + 1];
	for (int i = 0; i <= *nodeNum; i++)
	{
		(*H)[i].firstNode = NULL;
		(*H)[i].endNode = NULL;
	}

	i = 1;
	
	while (!inFile.eof())
	{
		inFile >> tempStr;
		tmpInput[0] = stoi(tempStr);
		inFile >> tempStr;
		tmpInput[1] = stoi(tempStr);
		inFile >> tempStr;
		tmpInput[2] = stoi(tempStr);

		makeNode(H, tmpInput[0], tmpInput[1], tmpInput[2]);
	}
	
	for (int i = 0; i <= *nodeNum; i++)
	{
	cout << i<<": ";
	printNode((*H)[i]);
	}
}
void printTop(int n)
{
	int blockNum = 0;
	int *blockOrder = new int[n];
	int index = p[n];
	blockOrder[blockNum] = p[n];
	blockNum++;

	while (p[index] != -1)
	{
		blockOrder[blockNum] = p[index];
		blockNum++;
		index = p[index];
	}
	cout << blockNum<<endl;

	for (int i = 0; i < blockNum; i++)
	{
		cout << blockOrder[i] << endl;
	}

}

