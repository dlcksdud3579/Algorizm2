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

int moveX[4] = { -1,1,0,0 };
int moveY[4] = { 0,0,-1,1 };

typedef struct pdata
{
	int y;
	int x;
	int d;
}pdata;

void inputFile();

int n = 0;
pdata* Q;

int rear=0;
int front=0;

int** map;
int**d;
int**p;
int** color;


int Bsize = 2;
int x;
int y;
int time = 0;

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

	Q = new pdata[n*n];
	Q[0].x = 0;
	Q[0].y = 0;
	Q[0].d = 0;

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
	for (int i = 1; i <= n;i++)
	{
		for (int j = 1; j <= n;j++)
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

	while (front!= rear)
	{
		pdata u = Q[front];
		for (int i = 0; i <4; i++)
		{
			
			int vx = u.x + moveX[i];
			int vy = u.y + moveY[i];

			if (vx < 1 || vy < 1 || vx > n || vy > n)
				continue;

			if (map[vy][vx] > 0 && map[vy][vx] < Bsize)
			{
				map[vy][vx] = 0;
				time += d[u.y][u.x] + 1;
				printf("<%d %d> <%d,%d> %d\n", y-1, x-1, vy-1, vx-1, time);
				x = vx;
				y = vy;
				exe++;
				if (Bsize == exe)
				{
					Bsize++;
					exe = 0;
				}
				front = 0;
				rear = 0;
				return true;
			}
			if (color[vy][vx] == WHITE && map[vy][vx] <= Bsize){
				color[vy][vx] = GRAY;
				d[vy][vx] = d[u.y][u.x] + 1;
				temp.x = vx;
				temp.y = vy;
				temp.d = d[vy][vx];
				insertPQ(temp);
			}
		}
		popPQ();
		color[u.y][u.x] = BLACK;
	}
	return false;
}


void inputFile()
{

	string tempStr;
	char tempchar;
	int i = 1;
	ifstream inFile = ifstream("Text.txt");

	inFile >> tempStr;
	n = stoi(tempStr);

	inFile >> tempStr;
	y = stoi(tempStr) +1;

	inFile >> tempStr;
	x = stoi(tempStr) +1;

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





void swapData(pdata * a, pdata * b)  // 두정수를 교환하는 함수 
{
	pdata tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}


pdata popPQ()  // min Heap 에 가장 작은 데이터를 제거하는 함수
{
	return Q[front++];
}



void printfPQ(int nodeNum)  // min heao 을 출력하는 함수 
{
	int cnt = 1;
	int cnt2 = 1;

	for (int i = 1; i <= Q[0].d; i++)
	{

		printf_s("(<%d,%d>,%d)", Q[i].y, Q[i].x, Q[i].d);
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
	Q[rear++] = insertData;  // 맨뒤에 입력값을 넣어줍니다.
}
