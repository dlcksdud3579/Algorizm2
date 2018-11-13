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
	string tempStr;


	ifstream inFile = ifstream("Text1.txt");
	inFile >> capacity;
	inFile >> exampleNum;
	inFile >> playerNum;
	 

	player = new int[playerNum+1];
	player[0] = playerNum;
	tree = new int[playerNum];
	tree[0] = playerNum-1;
	int F = 0;


	for (int k = 1; k <= playerNum; k = k + 2) {
		int p = (k + playerNum - 1) / 2;
		tree[p] = k;
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
					index *= 2;
				else
					index = index * 2+1;
				if (2 * index >= playerNum)
				{
					q = index * 2 - (playerNum - 1);

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
			
			

			if (player[q] < player[q + 1])
				tree[index] = q + 1;
			else
				tree[index] = q;
			while (index >1)
			{
				if (index % 2 != 0)
					index -= 1;

				if (player[tree[index]] < player[tree[index + 1]])
					tree[index / 2] = tree[index+1];
				else
					tree[index / 2] = tree[index];
				index /= 2;
			}

		}

		

	}

	printList(tree, playerNum - 1);
	printList(player, playerNum);
	
	return 0;
}



