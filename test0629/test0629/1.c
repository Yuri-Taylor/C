#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *fp;
	int matcip[2][2] = { 9,3,19,22 }, matpla[2][2] = { 14,0,3,24 }, invcip[2][2] = { 0 }, invA[2][2] = { 0 };
	int tran1[10000] = { 0 }, T1[2] = { 0 }, msg[2] = { 0 }, mes[10000] = { 0 };
	int i, j, detcip, invdetcip, len;
	int flag = 0;
	char ciph[10000] = { '\0' }; //密文
	char pla[10000] = { '\0' }; //明文
	detcip = -1;
	for (i = 1; detcip < 0; i++)
	{
		detcip = ((matcip[0][0] * matcip[1][1] - matcip[0][1] * matcip[1][0]) + 26 * i) % 26; //求部分密文的行列式的值 
	}
	i = 1;

	//判断 是否可逆 
	while (1)
	{
		if ((detcip * i) % 26 == 1)
		{
			invdetcip = i;
			break;
		}
		else
		{
			i++;
		}
	}

	// 求部分密文的逆矩阵 
	invcip[0][0] = (matcip[1][1] * invdetcip) % 26;
	invcip[0][1] = (((-1 * matcip[0][1]) + 26) * invdetcip) % 26;
	invcip[1][0] = (((-1 * matcip[1][0]) + 26) * invdetcip) % 26;
	invcip[1][1] = (matcip[0][0] * invdetcip) % 26;

	//加密矩阵A在模26下的逆矩阵
	invA[0][0] = (matpla[0][0] * invcip[0][0] + matpla[0][1] * invcip[1][0]) % 26;
	invA[0][1] = (matpla[0][0] * invcip[0][1] + matpla[0][1] * invcip[1][1]) % 26;
	invA[1][0] = (matpla[1][0] * invcip[0][0] + matpla[1][1] * invcip[1][0]) % 26;
	invA[1][1] = (matpla[1][0] * invcip[0][1] + matpla[1][1] * invcip[1][1]) % 26;
	printf("The Inverse of the encryption matrix：\n");
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			printf("%d ", invA[i][j]);
		}
		printf("\n");
	}
	strcpy(ciph, "zvpzcuaswvcdpzmnqvkgcemuvdfukgzvpzcuaswvcdpzq");

	len = strlen(ciph) - 1;   //len是密文的长度
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
	// 得到解密后结果
	for (i = 0; i < len; i += 2)
	{
		T1[0] = tran1[i];
		T1[1] = tran1[i + 1];

		// msg存储明文int值
		msg[0] = (T1[0] * invA[0][0] + T1[1] * invA[0][1]) % 26;
		msg[1] = (T1[0] * invA[1][0] + T1[1] * invA[1][1]) % 26;

		mes[i] = msg[0];
		mes[i + 1] = msg[1];
	}
	if (flag == 1)
	{
		len = len - 1;
	}
	printf("the cracked plain text：\n");
	for (i = 0; i < len; i++)
	{
		pla[i] = mes[i] + 'a';
		printf("%c", pla[i]);
	}
	printf("\n");
	return 0;
}