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
	//������
	char mine[ROWS][COLS] = { 0 };//����׵���Ϣ
	char show[ROWS][COLS] = { 0 };//����ų�����Ϣ
	InitBoard(mine, ROWS, COLS, '0');//��ʼ��
	InitBoard(show, ROWS, COLS, '*');
	SetMine(mine, ROW, COL);//������
	DisplayBoard(mine, ROW, COL);//��ӡ
	DisplayBoard(show, ROW, COL);
	//ɨ��
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