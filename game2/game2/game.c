#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			arr[i][j] = set;
		}
	}
}

void DisplayBoard(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("\n");
	printf("  ");
	for (i = 1; i <= col; i++)
	{
		printf("%d  ",i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ",i);
		for (j = 1; j <= col; j++)
		{
			printf("%c  ", arr[i][j]);
		}
		printf("\n\n");
	}
	printf("---------------------------\n");
}


void SetMine(char arr[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % 9 + 1;
		int y = rand() % 9 + 1;
		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			count--;
		}
	}
}

int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] + 
		mine[x + 1][y] + mine[x + 1][y + 1] + mine[x][y + 1] + mine[x - 1][y + 1] - 8 * '0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col-EASY_COUNT)
	{
		printf("Please enter coordinates: ");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("The bomb exploded!!!\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				int count = GetMineCount(mine, x,y);
				win++;
				show[x][y] = count+'0';
				DisplayBoard(show, ROW, COL);
			}
		}
		else {
			printf("Illegal coordinates!\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("Success\n");
		DisplayBoard(mine, ROW, COL);
	}
}