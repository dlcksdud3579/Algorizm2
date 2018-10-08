
#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
typedef struct node
{
	int nodeNum;
	int capacity;
	int flow;
	node* budy;
	node* next;
}node;
typedef struct hNode
{
	node* firstNode;
	node* endNode;

}hNode;


void makeNode(hNode **H, int nodeNum, int budyNum, int nodeWeight);
void printNode(hNode H);
int getEdgeWeight(hNode H, int index);



