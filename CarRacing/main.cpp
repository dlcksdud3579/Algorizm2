#include <iostream>
#include <fstream>
#include "AdjList.h"
using namespace std;

void inputFile(int *nodeNum);
AdjList * adjList;
int nodeNum = 0;
int *d, *p;

void intializeSingleSource(int start);

void relax(int u, int v);

bool bellmanFord(int start);

int* path(int end,int *top);

int main()
{
	
	int *root;
	int top = 0;
	inputFile(&nodeNum);
	cout << adjList->toString() << endl;


	d = new int[nodeNum];
	p = new int[nodeNum];

	bellmanFord(0);
	for (int i = 0 ;i< nodeNum; i++)
	{
		cout<< p[i];
	}
	cout << endl;
	for (int i = 0; i< nodeNum; i++)
	{
		cout << d[i]<<" ";
	}
	cout << endl;

	
	cout << "--------------°á°ú-----------------" << endl;
	root = path(6,&top);
	cout << d[6] << endl;
	cout << top << endl;
	for (int i = top-1; i >= 0; i--)
	{
		cout<<root[i]<<" ";
	}

	cout << endl;

	delete(adjList);
	delete[] d;
	delete[] p;
	return 0;
}
int* path(int end,int *top)
{
	int *result;
	result = new int[nodeNum];
	int index = p[end];
	while (index != 0)
	{
		
		result[(*top)++] = index;
		index = p[index];
	}

	return  result;
}


void inputFile(int *nodeNum )
{

	string tempStr;
	int tmpInput;
	int i = 1;
	int *distance;
	int *maintenance;
	ifstream inFile = ifstream("Text.txt");
	
	inFile >> tempStr;
	int maxDistance = stoi(tempStr);
	
	inFile >> tempStr;
	*nodeNum = stoi(tempStr) + 2;
	distance = new int[*nodeNum];
	maintenance = new int[*nodeNum - 1];
	adjList = new AdjList(*nodeNum);

	i = 1;
	for (int i = 1; i < *nodeNum; i++)
	{
		inFile >> tempStr;
		distance[i] = stoi(tempStr);

	}
	for (int i = 1; i < *nodeNum-1; i++)
	{
		inFile >> tempStr;
		maintenance[i] = stoi(tempStr);

	}
	for (int i = 0; i < *nodeNum; i++)
	{
		int sum = 0;
		for (int j = i+1; j < *nodeNum; j++)
		{
			
			sum += distance[j];
			if (sum <= maxDistance)
			{
				Node *node;
				if (j == *nodeNum - 1)
				{
					node = new Node(j,0);
				}
				else
				{
					node = new Node(j,maintenance[j]);
				}
				adjList->InsertNode(i, node);
				
			}
			else
			{
				break;
			}
		}
	}

	delete[] distance;
	delete[] maintenance;
	
}

void intializeSingleSource(int start)
{
	for (int i = 0; i< nodeNum; i++)
	{
		d[i] = 50000000;
		p[i] = NULL;
	}
	d[start] = 0;
}

void relax(int u, int v)
{
	if (d[v] > d[u] + adjList->getList(u)->getNode(v)->getEdgeNum())
	{
		d[v] = d[u] + adjList->getList(u)->getNode(v)->getEdgeNum();
		p[v] = u;
	}
}

bool bellmanFord(int start)
{
	intializeSingleSource(start);
	for (int i = 1; i<nodeNum - 1; i++)
	{
		for (int u = 0; u<nodeNum; u++)
		{
			int v;
			Node* hnode = adjList->getList(u)->getFirstNode();
			while (hnode != NULL)
			{
				v = hnode->getNodeNum();
				relax(u, v);
				hnode = hnode->getNextNode();
			}
		}
	}
	for (int u = 0; u<nodeNum; u++)
	{
		int v;
		Node* hnode = adjList->getList(u)->getFirstNode();
		while (hnode != NULL)
		{
			v = hnode->getNodeNum();
			if (d[v] > d[u] + adjList->getList(u)->getNode(v)->getEdgeNum())
				return false;
			hnode = hnode->getNextNode();
		}
	}

	return true;
}