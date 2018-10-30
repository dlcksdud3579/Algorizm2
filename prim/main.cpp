#include <iostream>
#include <fstream>
#include "AdjList.h"
using namespace std;
#define infinity 50000000
#define nil -1;

typedef struct pdata
{
	int p;
	int d;
}pdata;

void inputFile(int *nodeNum);
AdjList * adjList;
int nodeNum = 0;
pdata* PQ;
int* d;
int* p;
int *flag;


void swapData(pdata * a, pdata * b);
pdata popPQ();

void printfPQ(int nodeNum);
void insertPQ(pdata insertData);

void mstPrim(int r);
void printList(int*list, int num);




int main()
{
	
	int *root;
	int top = 0;
	inputFile(&nodeNum);
	
	PQ = new pdata[nodeNum*2];
	PQ[0].p = 0;
	PQ[0].d = 0;
	d = new int[nodeNum + 1];
	p = new int[nodeNum + 1];
	flag = new int[nodeNum + 1];
	mstPrim(1);


	cout << "nearest :";
	printList(p, nodeNum);
	int sum=0;
	printList(d, nodeNum);

	cout << "weight 합 ::";
	for (int i = 1; i <= nodeNum; i++)
	{
		
		sum += d[i];
	}
	cout << sum << endl;;



	delete(adjList);
	return 0;
}

void mstPrim(int r)
{
	for (int i = 1; i <= nodeNum; i++)
	{
		d[i] = infinity;
		flag[i] = 0;
	}
	d[r] = 0;
	p[r] = nil;
	
	pdata temp;
	temp.p = r;
	temp.d = d[r];
	insertPQ(temp);
	while (PQ[0].d != 0)
	{
		int u = popPQ().p;
		if (flag[u] == 0)
		{
			Node* hnode = adjList->getList(u)->getFirstNode();
			while (hnode != NULL)
			{
				int v = hnode->getNodeNum();
				int w = adjList->getList(u)->getNode(v)->getEdgeNum();
				if (flag[v] == 0 && w < d[v])
				{
					p[v] = u;
					d[v] = w;
					pdata temp;
					temp.p = v;
					temp.d = d[v];
					insertPQ(temp);
				}
				hnode = hnode->getNextNode();
			}
		}
		flag[u] = 1;
		printfPQ(nodeNum);
	}
}
void printList(int*list, int num)
{
	for (int i = 1; i <= num; i++)
		cout << list[i] << " ";
	cout << endl;
}

void inputFile(int *nodeNum )
{

	string tempStr;
	int tmpInput[3];
	int edegeNum;
	int i = 1;
	ifstream inFile = ifstream("Text1.txt");

	inFile >> tempStr;
	*nodeNum = stoi(tempStr);
	
	inFile >> tempStr;
	edegeNum = stoi(tempStr);
	
	
	adjList = new AdjList(*nodeNum+1);

	i = 1;
	for (int i = 0; i < edegeNum; i++)
	{
		inFile >> tempStr;
		tmpInput[0] = stoi(tempStr);
		inFile >> tempStr;
		tmpInput[1] = stoi(tempStr);
		inFile >> tempStr;
		tmpInput[2] = stoi(tempStr);

		Node *node1 = new Node(tmpInput[1], tmpInput[2]);
		adjList->InsertNode(tmpInput[0], node1);
		Node *node2 = new Node(tmpInput[0], tmpInput[2]);
		adjList->InsertNode(tmpInput[1], node2);

	}
	cout << adjList->toString() << endl;
}


void swapData(pdata * a, pdata * b)  // 두정수를 교환하는 함수 
{
	pdata tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}


pdata popPQ()  // min Heap 에 가장 작은 데이터를 제거하는 함수
{
	pdata returnValue = PQ[1];
	int index = 1;
	int child = 1 * 2;
	pdata temp;
	temp = PQ[PQ[0].d];  // 맨뒤의 키를 저장
	PQ[0].d -= 1;
	PQ[1] = temp;


	while (child <= PQ[0].d)
	{
		if (child < PQ[0].d && PQ[child].d > PQ[child + 1].d)  // 작은 아들을 선택
		{
			child++;

		}

		if (temp.d <= PQ[child].d)  // 아들이 커질경우 정지 
			break;

		swapData(&PQ[index],&PQ[child]); // 아들을 현재위치로 이동
		index = child;

		child *= 2; //다음아들을 찾는다  
	}
	return returnValue;
}



void printfPQ(int nodeNum)  // min heao 을 출력하는 함수 
{
	int cnt = 1;
	int cnt2 = 1;

	for (int i = 1; i <= PQ[0].d; i++)
	{

		printf_s("(%d,%d)", PQ[i].p, PQ[i].d);
		if (cnt2 == cnt)
		{
			printf_s("\n");
			cnt *= 2;
			cnt2 = 0;
		}
		cnt2++;

	}
	printf_s("\n");
	printf_s("\n");

}



void insertPQ(pdata insertData) // min Heap 에 데이터를  추가 하는함수 
{
	int index;
	int parent;


	PQ[0].d+=1;
	PQ[PQ[0].d] = insertData;  // 맨뒤에 입력값을 넣어줍니다.

	index = PQ[0].d;  //입력값의 위치
	parent = index / 2;  // 입력값의 부모 위치

	while (parent !=0 && PQ[parent].d > PQ[index].d) // 부모보다 작을경우 바꾼다
	{
		swapData(&PQ[parent], &PQ[index]);
		index /= 2;
		parent = index / 2;

	}
}
