#include<stdio.h>

//int main()
//{
//	int i = 0;
//	printf("%d \n", __STDC__);
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", i);
//	}
//
//	printf("\n file : %s  line : %d\n", __FILE__, __LINE__);
//	return 0;
//}

#define MAX(x,y) ((x)>(y)?(x):(y))

int Max(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	int a = 10;
	int b = 20;
	printf("%d\n", Max(a, b));
	printf("%d\n", MAX(a, b));
	return 0;
}