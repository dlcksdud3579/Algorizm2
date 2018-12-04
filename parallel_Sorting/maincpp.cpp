#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>

#define SWAP(a,b) {a^=b^=a^=b;};

int *matrix;
int main()
{
	int size = 0;
	freopen("Text.txt", "r", stdin);
	freopen("Text1.txt", "w", stdout);
	scanf("%d",&size);

	matrix = (int *)malloc(sizeof(int)*size*size);
	for (int i = 0; i < size*size; i++)
		scanf("%d", &(matrix[i]));



	for (int m = 0; m < size*log2(size); m++)
	{
		for (int i = 0; i < size; i++)
		{

			if (i % 2 == 0)  // È¦¼ö row
			{
				for (int n = 0; n < size; n++)  // n¹ø ¹Ýº¹
				{
					if (n % 2 == 0)  //È¦¼ö¹ø
					{
						for (int j = 0; j < size; j += 2)
						{
							if (matrix[i*(size)+j] > matrix[i*(size)+j + 1])
								SWAP(matrix[i*(size)+j], matrix[i*(size)+j + 1])
						}
					}
					else  //Â¦¼ö¹ø
					{
						for (int j = 1; j < size - 1; j += 2)
						{
							if (matrix[i*(size)+j] > matrix[i*(size)+j + 1])
								SWAP(matrix[i*(size)+j], matrix[i*(size)+j + 1])
						}
					}
				}

			}
			else  //Â¦¼ö ROW
			{
				for (int n = 0; n < size; n++)  // N¹ø ¹Ý“ý
				{
					if (n % 2 == 0)  //È¦¼ö¹ø
					{
						for (int j = 0; j < size; j += 2)
						{
							if (matrix[i*(size)+j] < matrix[i*(size)+j + 1])
								SWAP(matrix[i*(size)+j], matrix[i*(size)+j + 1])
						}
					}
					else   // Â¦¼ö¹ø
					{
						for (int j = 1; j < size - 1; j += 2)
						{
							if (matrix[i*(size)+j] < matrix[i*(size)+j + 1])
								SWAP(matrix[i*(size)+j], matrix[i*(size)+j + 1])
						}
					}
				}
			}
			for (int c = 0; c < size; c++)
			{
				for (int n = 0; n < size; n++)  // N¹ø ¹Ý“ý
				{
					if (n % 2 == 0)  //È¦¼ö¹ø
					{
						for (int j = 0; j < size; j += 2)
						{
							if (matrix[j*(size)+c] > matrix[(j + 1)*(size)+c])
								SWAP(matrix[j*(size)+c], matrix[(j + 1)*(size)+c])
						}
					}
					else
					{
						for (int j = 1; j < size - 1; j += 2)
						{
							if (matrix[j*(size)+c] > matrix[(j + 1)*(size)+c])
								SWAP(matrix[j*(size)+c], matrix[(j + 1)*(size)+c])
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < size; i++) // 0~n row
	{
		for (int n = 0; n < size; n++)  // n¹ø ¹Ýº¹
		{
			if (n % 2 == 0)  //È¦¼ö¹ø
			{
				for (int j = 0; j < size; j += 2)
				{
					if (matrix[i*(size)+j] > matrix[i*(size)+j + 1])
						SWAP(matrix[i*(size)+j], matrix[i*(size)+j + 1])
				}
			}
			else  //Â¦¼ö¹ø
			{
				for (int j = 1; j < size - 1; j += 2)
				{
					if (matrix[i*(size)+j] > matrix[i*(size)+j + 1])
						SWAP(matrix[i*(size)+j], matrix[i*(size)+j + 1])
				}
			}
		}
	}


	for (int i = 0; i < size*size; i++)
	{
		if (i%size == 0)
			printf("\n");
		printf("%d ", matrix[i]);
	}

}

