//ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ��
//����9�����9*9�ھ������12�����12*12�ĳ˷��ھ���
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