#define _crt_secure_no_warnings
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#define infinity 50000000
#define nil -1;
enum COLOR
{
	WHITE,GRAY,BLACK
};

int moveX[4] = { 0,1,0,-1 };
int moveY[4] = { -1,0,1,0 };

typedef struct pdata
{
	int y;
	int x;
	int d;
}pdata;

void inputFile();

int n = 0;
pdata* PQ;

int** map;
int**d;
int**p;
int** color;


int Bsize = 2;
int x;
int y;

int exe = 0;


void swapData(pdata * a, pdata * b);
pdata popPQ();
bool BFS();
void printfPQ(int nodeNum);
void insertPQ(pdata insertData);

void printList(int**list, int num);

void main()
{

	int top = 0;
	inputFile();

	PQ = new pdata[n*n];
	PQ[0].x = 0;
	PQ[0].y = 0;
	PQ[0].d = 0;

	while (BFS()){}




	for (int i = 0; i <= n; i++)
	{
		free(map[i]);
		free(d[i]);
		free(p[i]);
		free(color[i]);


	}
	free(map);
	free(d);
	free(p);
	free(color);

}
bool BFS()
{
	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < n;j++)
		{
			color[i][j] = WHITE;
			d[i][j] = infinity;
			p[i][j] = nil;
		}
	}
	color[y][x] = GRAY;
	d[y][x] = 0;
	p[y][x] = nil;
	pdata temp;

	temp.x = x;
	temp.y = y;
	temp.d = d[y][x];
	insertPQ(temp);

	while (PQ[0].d != 0)
	{
		pdata u = PQ[PQ[0].d];
		for (int i = 0; i <4; i++)
		{
			
			int vx = u.x + moveX[i];
			int vy = u.y + moveY[i];
			if (vx < 1 || vy < 1 || vx > n || vy > n)
				continue;

			if (map[vy][vx] > 0 && map[vy][vx] < Bsize)
			{
				map[vy][vx] = 0;
				printf("<%d %d> <%d,%d> %d\n", x-1, y-1, vy-1, vx-1,d[y][x]+1);
				x = vx;
				y = vy;
				exe++;
				if (Bsize == exe)
				{
					Bsize++;
					exe = 0;
				}
				PQ[0].d = 0;

				return true;
			}
			if (color[vy][vx] == WHITE && map[vy][vx] <= Bsize) {
				color[vy][vx] = GRAY;
				d[vy][vx] = d[u.y][u.x] + 1;
				temp.x = vx;
				temp.y = vy;
				temp.d = d[vy][vx];
				insertPQ(temp);
			}
			popPQ();
			color[u.y][u.x] = BLACK;

		}
	}
	return false;
}


void inputFile()
{

	string tempStr;
	char tempchar;
	int i = 1;
	ifstream inFile = ifstream("Text1.txt");

	inFile >> tempStr;
	n = stoi(tempStr);

	inFile >> tempStr;
	x = stoi(tempStr) +1;

	inFile >> tempStr;
	y = stoi(tempStr) +1;

	map = (int**)malloc(sizeof(int*)*(n + 1));
	d = (int**)malloc(sizeof(int*)*(n + 1));
	p = (int**)malloc(sizeof(int*)*(n + 1));
	color = (int**)malloc(sizeof(int*)*(n + 1));




	for (int i = 0; i <= n; i++)
	{
		map[i] = (int*)malloc(sizeof(int)*(n + 1));
		d[i] = (int*)malloc(sizeof(int)*(n + 1));
		p[i] = (int*)malloc(sizeof(int)*(n + 1));
		color[i] = (int*)malloc(sizeof(int)*(n + 1));

	}
	inFile.get();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			tempchar = inFile.get();
			map[i][j] = atoi(&tempchar);
		}
		inFile.get();
	}
}





void swapData(pdata * a, pdata * b)  // �������� ��ȯ�ϴ� �Լ� 
{
	pdata tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}


pdata popPQ()  // min Heap �� ���� ���� �����͸� �����ϴ� �Լ�
{
	pdata returnValue = PQ[1];
	int index = 1;
	int child = 1 * 2;
	pdata temp;
	temp = PQ[PQ[0].d];  // �ǵ��� Ű�� ����
	PQ[0].d -= 1;
	PQ[1] = temp;


	while (child <= PQ[0].d)
	{
		if (child < PQ[0].d && PQ[child].d > PQ[child + 1].d)  // ���� �Ƶ��� ����
		{
			child++;

		}

		if (temp.d <= PQ[child].d)  // �Ƶ��� Ŀ����� ���� 
			break;

		swapData(&PQ[index], &PQ[child]); // �Ƶ��� ������ġ�� �̵�
		index = child;

		child *= 2; //�����Ƶ��� ã�´�  
	}
	return returnValue;
}



void printfPQ(int nodeNum)  // min heao �� ����ϴ� �Լ� 
{
	int cnt = 1;
	int cnt2 = 1;

	for (int i = 1; i <= PQ[0].d; i++)
	{

		printf_s("(<%d,%d>,%d)", PQ[i].y, PQ[i].x, PQ[i].d);
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



void insertPQ(pdata insertData) // min Heap �� �����͸�  �߰� �ϴ��Լ� 
{
	int index;
	int parent;


	PQ[0].d += 1;
	PQ[PQ[0].d] = insertData;  // �ǵڿ� �Է°��� �־��ݴϴ�.

	index = PQ[0].d;  //�Է°��� ��ġ
	parent = index / 2;  // �Է°��� �θ� ��ġ

	while (parent != 0 && PQ[parent].d > PQ[index].d) // �θ𺸴� ������� �ٲ۴�
	{
		swapData(&PQ[parent], &PQ[index]);
		index /= 2;
		parent = index / 2;

	}
}
