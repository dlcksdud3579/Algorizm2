#include "node.h"



void makeNode(hNode **H, int nodeNum,int budyNum, int nodeWeight)
{
	node *newNode = new node;
	node *newNodeBudy = new node;
	bool isbudy = false;
	bool isnode = false;
	
	node *hnode = (*H)[nodeNum].firstNode;
	while (hnode != NULL && isbudy == false)
	{
		if (hnode->nodeNum == budyNum)
		{
			isbudy = true;
			hnode->capacity = nodeWeight;
			break;
		}
		hnode = hnode->next;
	}

	/*
	hnode = (*H)[budyNum].firstNode;
	while (hnode != NULL && isnode == false)
	{
		if (hnode->nodeNum == nodeNum)
		{
			isnode == true;
			break;
		}
		hnode = hnode->next;
	}
	*/

	if (isbudy == false)
	{
		newNode->nodeNum = budyNum;
		newNode->capacity = nodeWeight;
		newNode->flow = 0;
		newNode->budy = newNodeBudy;
		newNode->next = NULL;


		newNodeBudy->nodeNum = nodeNum;
		newNodeBudy->capacity = 0;
		newNodeBudy->flow = 0;
		newNodeBudy->budy = newNode;
		newNodeBudy->next = NULL;

		if ((*H)[nodeNum].firstNode == NULL)
		{
			(*H)[nodeNum].firstNode = newNode;
			(*H)[nodeNum].endNode = newNode;
		}
		else
		{
			(*H)[nodeNum].endNode->next = newNode;
			(*H)[nodeNum].endNode = newNode;
		}
		if (isnode == false)
		{
			if ((*H)[budyNum].firstNode == NULL)
			{
				(*H)[budyNum].firstNode = newNodeBudy;
				(*H)[budyNum].endNode = newNodeBudy;
			}
			else
			{
				(*H)[budyNum].endNode->next = newNodeBudy;
				(*H)[budyNum].endNode = newNodeBudy;
			}
		}
	}
}


void printNode(hNode H)
{
	node *hnode = H.firstNode;
	while (hnode != NULL)
	{
		cout << "(";
		cout << hnode->nodeNum << ", ";
		cout << hnode->capacity << ", ";
		cout << hnode->flow;
		cout << ")";
		hnode = hnode->next;
	}
	cout << endl;
}

int getEdgeWeight(hNode H, int index)
{
	node *hnode = H.firstNode;
	while (hnode != NULL)
	{
		if (hnode->nodeNum == index)
		{
			return hnode->capacity;
		}
		hnode = hnode->next;
	}
	return 0;
}