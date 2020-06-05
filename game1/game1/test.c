#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void game()
{
	char board[ROW][COL] = { 0 };
	char ret = 0;
	InitBoard(board, ROW, COL);  //���ӳ�ʼ��
	DisplayBoard(board, ROW, COL); //��ӡ����
	while (1)
	{
		PlayerMove(board, ROW, COL);
		ret = IsWin(board, ROW, COL);//�ж���Ϸ�Ƿ��������X�����Ӯ����O������Ӯ����Q��ƽ�֣����� ������Ϸ������
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