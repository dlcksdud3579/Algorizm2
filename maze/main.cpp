#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#define infinity 50000000
#define nil -1;
int moveX[4] = { 0,1,0,-1 };
int moveY[4] = { -1,0,1,0 };


typedef struct pdata
{
	int y;
	int x;
	int d;
}pdata;



void inputFile(int *nodeNum);

int n = 0;
pdata* PQ;


int** flag;
int** maze;
int** d;
int** px;
int** py;

void swapData(pdata * a, pdata * b);
pdata popPQ();

void printfPQ(int nodeNum);
void insertPQ(pdata insertData);

void dijkstra(int r);
void printList(int**list, int num);

void main()
{
	
	int top = 0;
	inputFile(&n);
	
	PQ = new pdata[n*2];
	PQ[0].x = 0;
	PQ[0].y = 0;
	PQ[0].d = 0;

	dijkstra(1);
	cout << "nearest :";
	cout<< d[n][n];
}

void dijkstra(int r)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			d[i][j] = infinity;
			flag[i][j] = 0;
		}
	}
	d[r][r] = 0;
	px[r][r] = nil;
	py[r][r] = nil;

	pdata temp;
	temp.x = r;
	temp.y = r;
	temp.d = d[r][r];
	insertPQ(temp);

	while (PQ[0].d != 0)
	{
		pdata u = popPQ();
		if (flag[u.y][u.x] == 0)
		{
			for(int i=0;i<4;i++)
			{
				int vy = u.y+moveY[i];
				int vx = u.x + moveX[i];
				if (vx<1 || vy<1 || vx>n || vy>n)
					continue;

				int w =  (maze[vy][vx]? 0:1);
				
				if (flag[vy][vx] == 0 && d[u.y][u.x] + w < d[vy][vx])
				{
					py[vy][vx] = u.y;
					px[vy][vx] = u.x;
					d[vy][vx] = w + d[u.y][u.x];
					pdata temp;
					temp.y = vy;
					temp.x = vx;
					temp.d = d[vy][vx];
					insertPQ(temp);
				}
			}
		}
		flag[u.y][u.x] = 1;
		//printfPQ(n);
	}
}
void printList(int**list, int num)
{
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= num; j++)
			cout << list[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

void inputFile(int *n )
{

	string tempStr;
	char tempchar;
	int i = 1;
	ifstream inFile = ifstream("Text.txt");

	inFile >> tempStr;
	*n = stoi(tempStr);
	maze = (int**)malloc(sizeof(int*)*(*n+1));
	d = (int**)malloc(sizeof(int*)*(*n + 1));
	px = (int**)malloc(sizeof(int*)*(*n + 1));
	py = (int**)malloc(sizeof(int*)*(*n + 1));
	flag = (int**)malloc(sizeof(int*)*(*n + 1));
	for (int i = 1; i <= *n; i++)
	{
		maze[i] = (int*)malloc(sizeof(int)*(*n + 1));
		d[i] = (int*)malloc(sizeof(int)*(*n + 1));
		px[i] = (int*)malloc(sizeof(int)*(*n + 1));
		py[i] = (int*)malloc(sizeof(int)*(*n + 1));
		flag[i] = (int*)malloc(sizeof(int)*(*n + 1));
	}
	inFile.get();
	for (int i = 1; i <= *n; i++)
	{
		for (int j = 1; j <= *n; j++)
		{
			tempchar = inFile.get();
			maze[i][j] = atoi(&tempchar);
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
