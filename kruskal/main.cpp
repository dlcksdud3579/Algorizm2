#include <iostream>
#include <fstream>
#include <string>
#include "Sets.h"


using namespace std;
#define infinity 50000000
#define nil -1;
Sets  *disjointSet;


void kruskal()
{
	int nodeNum,edgeNum;
	string tempStr;
	int nextEdge[3];

	ifstream inFile = ifstream("Text1.txt");
	inFile >> tempStr;
	nodeNum = stoi(tempStr);

	inFile >> tempStr;
	edgeNum = stoi(tempStr);

	disjointSet = new Sets(nodeNum+1);   // inital n disjointSet
	int F = 0;


	for (int i = 0; i < edgeNum && F<= edgeNum-1; i++)
	{
		inFile >> tempStr;
		nextEdge[0] = stoi(tempStr); // source
		inFile >> tempStr;
		nextEdge[1] = stoi(tempStr);  // dst
		inFile >> tempStr;
		nextEdge[2] = stoi(tempStr);  // edge

		int p, q;
		p = disjointSet->CollapsingFind(nextEdge[0]);
		q = disjointSet->CollapsingFind(nextEdge[1]);
		if (p != q)
		{
			disjointSet->weightedUnion(p, q);
			cout << nextEdge[0]<<" "<< nextEdge[1] <<" "<<nextEdge[2] << endl;
			F++;
		}

	}



}
int main()
{

	kruskal();

	return 0;
}



