#include <iostream>
#include <fstream>
#include "AdjList.h"
using namespace std;

void inputFile(int *nodeNum);
AdjList * adjList;

int main()
{
	int nodeNum = 0;
	int *d, *p;
	inputFile(&nodeNum);
	cout << adjList->toString() << endl;


	d = new int[nodeNum];
	p = new int[nodeNum];

	


	delete(adjList);
	delete[] d;
	delete[] p;
	return 0;
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