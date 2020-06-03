//实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定
//输入9，输出9*9口诀表，输出12，输出12*12的乘法口诀表
#include<stdio.h>
void Multiplication(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d * %d = %d\t", j, i, i*j);
		}
		printf("\n");
	}
}
int main()
{
	int line;
	line = 12;
	Multiplication(line);
	return 0;
}