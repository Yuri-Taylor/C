#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("******************************\n");
	printf("********    1.play    ********\n");
	printf("********    0.exit    ********\n");
	printf("******************************\n");
}

void game()
{
	//布置雷
	char mine[ROWS][COLS] = { 0 };//存放雷的信息
	char show[ROWS][COLS] = { 0 };//存放排出的信息
	InitBoard(mine, ROWS, COLS, '0');//初始化
	InitBoard(show, ROWS, COLS, '*');
	SetMine(mine, ROW, COL);//布置雷
	DisplayBoard(mine, ROW, COL);//打印
	DisplayBoard(show, ROW, COL);
	//扫雷
	FindMine(mine, show, ROW, COL);
}

void test()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("Please select: ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("Exit!\n");
			break;
		default:
			printf("Please re-enter!\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}