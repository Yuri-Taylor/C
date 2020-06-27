/*
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 2   //����һ�¶��׾���
#include <time.h>



int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}



int main()
{

	int i, j, matrix1[M][M] = { 0 }, matrix2[M][M] = { 0 }, row1 = M, col1 = M, row2 = M, col2 = M;
	int sta = 0, len = 0, length = 0;
	int flag = 0, det, invdet;
	int matrix[2][2] = { 0 };
	int dt = 0;
	int p = 0;
	int q = 0;
	srand(time(0));
	char pla[10000] = { '\0' }; //����
	char ciph[10000] = { '\0' }; //����
	int tran1[10000] = { 0 }, T1[2] = { 0 }, T2[2] = { 0 }, cip[2] = { 0 }, s[10000] = { 0 }, msg[2] = { 0 }, mes[10000] = { 0 };
	FILE *fp;
	FILE *fp1;
	FILE *fp2;


	//����������� 
	do {
		matrix[0][0] = rand() % 26;
		matrix[0][1] = rand() % 26;
		matrix[1][0] = rand() % 26;
		matrix[1][1] = rand() % 26;
		dt = -1;
		for (p = 1; dt < 0; p++)
		{
			dt = ((matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) + 26 * p) % 26; //����ʽ��ֵ 
		}
	} while (gcd(dt, 26) != 1); //ȷ�� 
	printf("Random Encryption matrix:\n");
	for (p = 0; p < 2; p++) {
		for (q = 0; q < 2; q++) {
			printf("%d ", matrix[p][q]);
		}
		printf("\n");
	}

	//�������ļ� 
	fp = fopen("plain.txt", "r"); //  r��ֻ���ļ������ļ��������,plain�ļ��д������Ҫ����Hill���ܵ��ַ�
	while (!feof(fp))  //���ļ��е��ַ�һ��һ�����뵽char�͵�pla������
	{
		pla[sta] = fgetc(fp);
		sta++;
	}

	len = strlen(pla) - 1;
	length = len;   //ʹ��������ʽ��д�������һ������һ���ո������ڲ�������Ҫ��������ո�����strlen(pla)-1����ʵ�ʵĳ���
	// ������Ϊ����ʱ����һλ
	if (len % 2 == 1)   //Hill����ʱ����λ��λ���м��ܣ������������ʱ����Ҫ��������ĸ
	{
		pla[len] = 'a';
		len = len + 1;
		flag = 1;
	}
	// ����дת��Сд������ֵ��tran1����(��������int�͵����飬��ŵ������������ַ���Ӧ����ֵ������a��A��Ӧ����0��z��Z��Ӧ����25���Դ�����)
	for (i = 0; i < len; i++)
	{
		if (pla[i] >= 'A' && pla[i] <= 'Z')
		{
			pla[i] = pla[i] + 32;
		}
		tran1[i] = pla[i] - 'a';
	}
	for (i = 0; i < len; i = i + 2)
	{
		T1[0] = tran1[i];
		T1[1] = tran1[i + 1];
		// cip�洢����int
		//���� 
		cip[0] = (T1[0] * matrix[0][0] + T1[1] * matrix[0][1]) % 26;
		cip[1] = (T1[0] * matrix[1][0] + T1[1] * matrix[1][1]) % 26;
		s[i] = cip[0];
		s[i + 1] = cip[1];
	}
	for (i = 0; i < len; i++)
	{
		ciph[i] = s[i] + 'a';
	}

	//�����Ĵ��䵽�ļ��� (�ļ��е����ĺ��в�λ�����ں������ܣ� 
	fp1 = fopen("output.txt", "w");
	i = 0;
	while (ciph[i] != '\0')
	{
		fprintf(fp1, "%c", ciph[i]);
		i++;
	}


	if (flag == 1)
	{
		len = len - 1;
	}
	printf("The encoded ciphertext��\n");  //���������ʱ���Ĳ�λȥ�� 
	for (i = 0; i < len; i++)
	{
		printf("%c", ciph[i]);
	}
	printf("\n");


	//���ܹ��� 

	 //Ϊ��Ҫ��˵���������ֵ��// 
	printf("\n");
	printf("Enter the values of Encryption matrix��\n");
	for (i = 0; i < row1; i++)
	{
		for (j = 0; j < col1; j++)
		{
			scanf("%d", &matrix1[i][j]);
		}
	}     //matrix1�Ǽ��ܾ���

	if ((fp2 = fopen("output.txt", "r")) == NULL)
	{
		printf("Open the file failure...\n");
		exit(0);
	}
	while (!feof(fp2))
	{
		ciph[sta] = fgetc(fp2);
		sta++;
	}
	len = strlen(ciph);   //len�����ĵĳ���
   // ������Ϊ����ʱ����һλ

	if (len % 2 == 1)
	{
		ciph[len] = 'a';
		len = len + 1;
		flag = 1;
	}
	for (i = 0; i < len; i++)
	{
		if (ciph[i] >= 'A' && ciph[i] <= 'Z')
		{
			ciph[i] = ciph[i] + 32;
		}

		tran1[i] = ciph[i] - 'a';
	}

	//��������
	det = -1;
	for (i = 1; det < 0; i++)
	{
		det = ((matrix1[0][0] * matrix1[1][1] - matrix1[0][1] * matrix1[1][0]) + 26 * i) % 26;
	}
	i = 1;
	while (1)
	{
		if ((det * i) % 26 == 1)
		{
			invdet = i;
			break;
		}
		else
		{
			i++;
		}
	}

	//�����
	matrix2[0][0] = (matrix1[1][1] * invdet) % 26;
	matrix2[0][1] = (((-1 * matrix1[0][1]) + 26) * invdet) % 26;
	matrix2[1][0] = (((-1 * matrix1[1][0]) + 26) * invdet) % 26;
	matrix2[1][1] = (matrix1[0][0] * invdet) % 26;

	// �õ����ܺ���
	for (i = 0; i < len; i += 2)
	{
		T1[0] = tran1[i];
		T1[1] = tran1[i + 1];

		// msg�洢����intֵ
		msg[0] = (T1[0] * matrix2[0][0] + T1[1] * matrix2[0][1]) % 26;
		msg[1] = (T1[0] * matrix2[1][0] + T1[1] * matrix2[1][1]) % 26;

		mes[i] = msg[0];
		mes[i + 1] = msg[1];
	}


	if (length % 2 == 1)
	{
		len = length;
	}
	printf("the plain text is��\n");


	for (i = 0; i < len; i++)
	{
		pla[i] = mes[i] + 'a';
		printf("%c", pla[i]);
	}
	printf("\n");



	return 0;

}
*/