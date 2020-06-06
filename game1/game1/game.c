#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void InitBoard(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			arr[i][j] = ' ';
		}
	}
}

void DisplayBoard(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ",arr[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}


void PlayerMove(char arr[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("Player step:\n");
	while (1)
	{
		printf("Please enter coordinates: ");
		scanf("%d %d", &x, &y);
		if ((x >= 1 && x <= row) && (y >= 1 && y <= col))
		{
			if (arr[x - 1][y - 1] == ' ')
			{
				arr[x - 1][y - 1] = 'X';
				break;
			}
			else
			{
				printf("Coordinates occupied!\n");
			}
		}
		else
		{
			printf("Invalid coordinates!\n");
		}
	}
}


void ComputerMove(char arr[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("Computer step:\n");
	while (1)
	{
		x = rand() % 3;
		y = rand() % 3;
		if (arr[x][y] == ' ')
		{
			arr[x][y] = 'O';
			break;
		}
	}
}

static int IsFull(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (arr[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char IsWin(char arr[ROW][COL], int row, int col)
{
	//横
	int i = 0;
	int j = 0;
	int flag = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col - 1; j++)
		{
			if (arr[i][j] == arr[i][j + 1] && (arr[i][0] != ' '))
				flag = 1;
			else {
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			return arr[i][0];
	}
	//竖
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < row - 1; j++)
		{
			if (arr[j][i] == arr[j+1][i] && (arr[0][j] != ' '))
				flag = 1;
			else {
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			return arr[0][i];
	}
	//斜
	for (j = 0; j < row - 1; j++)
	{
		if (arr[j][j] == arr[j+1][j + 1] && (arr[0][0] != ' '))
			flag = 1;
		else {
			flag = 0;
			break;
		}
	}
	if (flag == 1)
		return arr[0][0];

	for (j = 0; j < row - 1; j++)
	{
		if (arr[j][row-j-1] == arr[j + 1][row-j-2] && (arr[0][row-1] != ' '))
			flag = 1;
		else {
			flag = 0;
			break;
		}
	}
	if (flag == 1)
		return arr[0][row-1];
	//平局
	if (IsFull(arr, row, col))
	{
		return 'Q';
	}
	return ' ';//游戏继续
}