#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int *player;
int *tree;

void printList(int*list, int num)
{
	for (int i = 1; i <= num; i++)
		cout << list[i] << " ";
	cout << endl;
}

int main()
{

	int capacity,exampleNum,playerNum;
	int example;
	int offset = 0;
	int LowExt = 0;
	int s;
	string tempStr;


	ifstream inFile = ifstream("Text.txt");
	inFile >> capacity;
	inFile >> exampleNum;
	inFile >> playerNum;
	 

	player = new int[playerNum+1];
	player[0] = playerNum;
	tree = new int[playerNum];
	tree[0] = playerNum-1;
	int F = 0;


	s = (int)pow(ceil(log2(playerNum)) -1,2);
	LowExt =  2*((playerNum-1) - (s-1));
	offset = 2*s-1;

	if (playerNum % 2 == 0)
	{
		for (int k = 1; k <= playerNum; k = k + 2) {
			int p = 0;
			if (k <= LowExt)
				p = (k + offset) / 2;
			else
				p = (k - LowExt +playerNum - 1) / 2;
			tree[p] = k;
		}
	}
	else
	{
		for (int k = 1; k <= LowExt; k = k + 2)
		{
			int p = (k + offset) / 2;;
			tree[p] = k;
		}
		for (int k = LowExt + 2; k <= playerNum; k = k + 2)
		{
			int p = (k - LowExt + playerNum - 1) / 2;
			tree[p] = k;
		}
	}

	for (int k = (playerNum - 1) / 2; k > 0; k--)
		tree[k] = tree[k * 2];

	for (int k = 1; k <= playerNum; k++)
	{
		player[k] = capacity;
	}

	for (int i = 0; i < exampleNum; i++)
	{
		inFile >> tempStr;
		example = stoi(tempStr);
		int index = 1;
		int q = 0;
		if (player[tree[index]] >= example)
		{
			while (1)
			{

				if (player[tree[2 * index]] >= example)
					index *= 2;  // 외쪽 자식으로 
				else if (2*index + 1 >= playerNum)
				{
					if (player[(index) * 2 + LowExt - playerNum + 1 + 1] >= example)
					{
						q = (index) * 2 + LowExt - playerNum + 1 + 1;
						player[q] -= example;
						break;

					}
					else
					{
						index = index/2 + 1;
						continue;
					}

				}
				else if(player[tree[2 * index + 1]] >= example)
				{
					index = index * 2 + 1;  // 오른쪽 자식

				}


				if (2 * index >= playerNum)   // 여기 걸리면 리프 노드 인듯?
				{
					
					if (s<=index)
					{
						q = index * 2 - offset;
					}
					else
					{
						q = index * 2 + LowExt - playerNum + 1;
					}
					if (player[q] >= example)
						player[q] -= example;
					else if (player[q + 1] >= example)
						player[q + 1] -= example;
					else
					{
						index = index / 2 + 1;
						continue;
					}
					break;
				}
			}
			
			
			if (playerNum%2 !=0 && q == LowExt + 1)
			{
				if (player[tree[index * 2]] <player[q])
					tree[index] = q;
				else
					tree[index] = tree[index * 2];
			}
			else
			{
				if (player[q] < player[q + 1])
					tree[index] = q + 1;
				else
				{
					tree[index] = q;
				}
			}

			while (index > 1)
			{
				if (index % 2 != 0)
					index -= 1;
				if (index + 1 >= playerNum)
				{
					if (player[tree[index]] < player[(index/2) * 2 + LowExt - playerNum + 1+1])
						tree[index / 2] = (index / 2) * 2 + LowExt - playerNum + 1 + 1;
					else
						tree[index / 2] = tree[index];
				}
				else
				{
					if (player[tree[index]] < player[tree[index + 1]])
						tree[index / 2] = tree[index + 1];
					else
						tree[index / 2] = tree[index];
				}
				index /= 2;
			}

		}

		

	}

	printList(tree, playerNum - 1);
	printList(player, playerNum);
	
	return 0;
}



