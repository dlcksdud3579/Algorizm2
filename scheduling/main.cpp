#include <iostream>
#include <fstream>
#include <string>
#include "Sets.h"


using namespace std;
#define infinity 50000000
#define nil -1;
Sets  *disjointSet;
int *shedule;

void printList(int*list, int num)
{
	for (int i = 1; i <= num; i++)
		cout << list[i] << " ";
	cout << endl;
}

void sheduling()
{
	int edgeNum;
	string tempStr;
	int nextEdge[3];

	ifstream inFile = ifstream("Text1.txt");
	inFile >> tempStr;
	edgeNum = stoi(tempStr);
	disjointSet = new Sets(edgeNum+1);   // inital n disjointSet
	shedule = new int[edgeNum+1];
	int F = 0;


	for (int i = 0; i < edgeNum; i++)
	{
		inFile >> tempStr;
		nextEdge[0] = stoi(tempStr); // source
		inFile >> tempStr;
		nextEdge[1] = stoi(tempStr);  // dst
		inFile >> tempStr;
		nextEdge[2] = stoi(tempStr);  // edge
		int p, q;
		q = disjointSet->CollapsingFind(nextEdge[1]);
		shedule[q] = nextEdge[0];
		disjointSet->SimpleUnion(q, disjointSet->CollapsingFind(q-1));
		cout << nextEdge[0] << " " << nextEdge[1] << " " << nextEdge[2] << endl;
		F++;
	}
	printList(shedule, edgeNum);
}



int main()
{

	sheduling();
	


	
	delete(disjointSet);
	delete shedule;
	return 0;
}



