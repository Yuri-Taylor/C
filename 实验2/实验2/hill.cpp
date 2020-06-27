/*
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 2   //定义一下二阶矩阵
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
	char pla[10000] = { '\0' }; //明文
	char ciph[10000] = { '\0' }; //密文
	int tran1[10000] = { 0 }, T1[2] = { 0 }, T2[2] = { 0 }, cip[2] = { 0 }, s[10000] = { 0 }, msg[2] = { 0 }, mes[10000] = { 0 };
	FILE *fp;
	FILE *fp1;
	FILE *fp2;


	//生成随机矩阵 
	do {
		matrix[0][0] = rand() % 26;
		matrix[0][1] = rand() % 26;
		matrix[1][0] = rand() % 26;
		matrix[1][1] = rand() % 26;
		dt = -1;
		for (p = 1; dt < 0; p++)
		{
			dt = ((matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) + 26 * p) % 26; //行列式的值 
		}
	} while (gcd(dt, 26) != 1); //确定 
	printf("Random Encryption matrix:\n");
	for (p = 0; p < 2; p++) {
		for (q = 0; q < 2; q++) {
			printf("%d ", matrix[p][q]);
		}
		printf("\n");
	}

	//打开明文文件 
	fp = fopen("plain.txt", "r"); //  r打开只读文件，该文件必须存在,plain文件中存放着需要进行Hill加密的字符
	while (!feof(fp))  //将文件中的字符一个一个读入到char型的pla数组中
	{
		pla[sta] = fgetc(fp);
		sta++;
	}

	len = strlen(pla) - 1;
	length = len;   //使用这样方式读写数组最后一个会多出一个空格，我们在操作中需要丢弃这个空格，所以strlen(pla)-1才是实际的长度
	// 当长度为奇数时补齐一位
	if (len % 2 == 1)   //Hill加密时是两位两位进行加密，如果遇到奇数时必须要补充哑字母
	{
		pla[len] = 'a';
		len = len + 1;
		flag = 1;
	}
	// 将大写转成小写，并赋值给tran1数组(次数组是int型的数组，存放的是输入明文字符对应的数值，例如a和A对应的是0，z和Z对应的是25，以此类推)
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
		// cip存储密文int
		//加密 
		cip[0] = (T1[0] * matrix[0][0] + T1[1] * matrix[0][1]) % 26;
		cip[1] = (T1[0] * matrix[1][0] + T1[1] * matrix[1][1]) % 26;
		s[i] = cip[0];
		s[i + 1] = cip[1];
	}
	for (i = 0; i < len; i++)
	{
		ciph[i] = s[i] + 'a';
	}

	//将密文传输到文件中 (文件中的密文含有补位，便于后续解密） 
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
	printf("The encoded ciphertext：\n");  //命令行输出时最后的补位去掉 
	for (i = 0; i < len; i++)
	{
		printf("%c", ciph[i]);
	}
	printf("\n");


	//解密过程 

	 //为需要相乘的两个矩阵赋值：// 
	printf("\n");
	printf("Enter the values of Encryption matrix：\n");
	for (i = 0; i < row1; i++)
	{
		for (j = 0; j < col1; j++)
		{
			scanf("%d", &matrix1[i][j]);
		}
	}     //matrix1是加密矩阵

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
	len = strlen(ciph);   //len是密文的长度
   // 当长度为奇数时补齐一位

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

	//求矩阵的逆
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

	//逆矩阵
	matrix2[0][0] = (matrix1[1][1] * invdet) % 26;
	matrix2[0][1] = (((-1 * matrix1[0][1]) + 26) * invdet) % 26;
	matrix2[1][0] = (((-1 * matrix1[1][0]) + 26) * invdet) % 26;
	matrix2[1][1] = (matrix1[0][0] * invdet) % 26;

	// 得到解密后结果
	for (i = 0; i < len; i += 2)
	{
		T1[0] = tran1[i];
		T1[1] = tran1[i + 1];

		// msg存储明文int值
		msg[0] = (T1[0] * matrix2[0][0] + T1[1] * matrix2[0][1]) % 26;
		msg[1] = (T1[0] * matrix2[1][0] + T1[1] * matrix2[1][1]) % 26;

		mes[i] = msg[0];
		mes[i + 1] = msg[1];
	}


	if (length % 2 == 1)
	{
		len = length;
	}
	printf("the plain text is：\n");


	for (i = 0; i < len; i++)
	{
		pla[i] = mes[i] + 'a';
		printf("%c", pla[i]);
	}
	printf("\n");



	return 0;

}
*/