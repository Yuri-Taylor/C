#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void game()
{
	char board[ROW][COL] = { 0 };
	char ret = 0;
	InitBoard(board, ROW, COL);  //棋子初始化
	DisplayBoard(board, ROW, COL); //打印棋盘
	while (1)
	{
		PlayerMove(board, ROW, COL);
		ret = IsWin(board, ROW, COL);//判断游戏是否结束返回X（玩家赢），O（电脑赢），Q（平局），‘ ’（游戏继续）
		if (ret != ' ')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
		ComputerMove(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != ' ')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);

	}
	DisplayBoard(board, ROW, COL);
	if (ret == 'X')
	{
		printf("Player wins!\n");
	}
	else if (ret == 'O')
	{
		printf("Computer wins!\n");
	}
	else if (ret == 'Q')
	{
		printf("Dogfall!\n");
	}
	
}

void menu()
{
	printf("***************************\n");
	printf("********  1. play  ********\n");
	printf("********  0. exit  ********\n");
	printf("***************************\n");
}

void test()
{
	int choose = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("Please select: ");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("Input error.Please re-enter!\n");
			break;
		}
	} while (choose);
}

int main()
{
	test();
	return 0;
}