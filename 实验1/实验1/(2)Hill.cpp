#include"Hill.h"

void menu()
{
	float keys[ROW][COV] = { 8,6,9,5, };// 加密矩阵（默认密钥）
	float obkeys[ROW][COV] = { 0 }; //解密矩阵?（密钥逆矩阵）
	char words[100] = { 0 };
	char crypto[100] = { 0 };
	char obwords[100] = { 0 };
	bool flag = true; //菜单选择
	bool chose = false; //密钥选择
	char cn = 0;
	while (flag)
	{
		int n = 0;
		cout << endl;
		cout << "****************************************************************" << endl;
		cout << "********************* 1.输入密钥 *******************************" << endl;
		cout << "********************* 2.加密     *******************************" << endl;
		cout << "********************* 3.解密     *******************************" << endl;
		cout << "********************* 4.退出     *******************************" << endl;
		cout << "****************************************************************" << endl;
		cout << "请选择->：";
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "默认密钥为：";
			PopKeys(keys);
			cout << "请问您要重新输入密钥？?y/n" << endl << "请选择->:";
			cin >> cn;
			if ((cn == 'y') || (cn == 'Y'))
			{
				InputKeys(keys); //输入密钥
			}
			else if ((cn == 'n') || (cn == 'N'))
			{
				cout << "使用默认密钥！" << endl;
			}
			else
				cout << "输入有误，请重新选择！" << endl;
			break;
		case 2:
			InputWords(words);
			Encryption(keys, words, crypto);
			cout << "密文是->：" << crypto << endl;
			break;
		case 3:
			InputObwords(crypto);
			ObMatrix(keys, obkeys, COV);
			Decode(obkeys, obwords, crypto);
			cout << "明文是->：" << obwords << endl;
			break;
		case 4:
			cout << endl << endl << endl;
			cout << setw(15) << "谢谢使用！" << endl;
			flag = false;
			break;
		default:
			cout << "选择有误，程序退出！" << endl;
			break;
		}
	}
}

//输入明文函数
void InputWords(char *words)
{
	assert(words);
	cout << "请输入明文：";
	char *start = words;
	int flag = 1;
	getchar();
	while (flag)
	{
		*words = getchar();
		words++;
		if (*(words - 1) == '\n')
		{
			*words = '\0';
			flag = 0;
		}
	}
	words = start;
	while (*start)
	{
		if (('A' <= *start) && (*start <= 'Z'))
		{
			*words = *start;
			words++;
		}
		else if (('a' <= *start) && (*start <= 'z'))
		{
			*words = *start - 32;
			words++;
		}
		start++;
	}
	*words = '\0';
	cout << "输入成功！" << endl;
}

//输入密文函数
void InputObwords(char *words)
{
	assert(words);
	cout << "请输入密文：";
	char *start = words;
	int flag = 1;
	getchar();
	while (flag)
	{
		*words = getchar();
		words++;
		if (*(words - 1) == '\n')
		{
			*words = '\0';
			flag = 0;
		}
	}
	words = start;
	while (*start)
	{
		if (('A' <= *start) && (*start <= 'Z'))
		{
			*words = *start;
			words++;
		}
		else if (('a' <= *start) && (*start <= 'z'))
		{
			*words = *start - 32;
			words++;
		}
		start++;
	}
	*words = '\0';
	cout << "输入成功！" << endl;
}

//输入密钥函数
void InputKeys(float keys[ROW][COV])
{
	cout << "请输入密钥：" << endl;
	for (size_t i = 0; i < ROW; i++)
	{
		cout << "请输入第" << i << "行密钥(" << ROW << "个数):";
		for (size_t j = 0; j < COV; j++)
		{
			cin >> keys[i][j];
		}
	}
	cout << "输入成功!" << endl;
}

//输出密钥函数
void PopKeys(float keys[ROW][COV])
{
	cout << "密钥为：" << endl;
	for (size_t i = 0; i < ROW; i++)
	{
		for (size_t j = 0; j < COV; j++)
		{
			cout << keys[i][j] << "???";
		}
		cout << endl;
	}
}

//加密函数
void Encryption(float keys[ROW][COV], char *words, char *crypto)
{
	assert(words);
	int len = strlen(words);
	char *start = words;

	while (len > 0)
	{
		int matrix[ROW] = { 0 };
		for (int i = 0; i < ROW; i++)
		{
			if (*start)
				matrix[i] = *start - 'A';
			else
				matrix[i] = 0;
			start++;
		}
		len -= ROW;
		int cry[ROW] = { 0 };
		for (int i = 0; i < ROW; i++)
		{
			int temp = 0;
			for (int j = 0; j < COV; j++)
			{
				temp = matrix[j] * keys[j][i] + temp;
			}
			cry[i] = temp % 26;
			*crypto = 'A' + cry[i];
			crypto++;
		}
	}
}

//解密函数
void Decode(float obkeys[ROW][COV], char *words, char *crypto)
{
	assert(crypto);
	int len = strlen(crypto);
	char *start = crypto;
	while (len > 0)
	{
		int matrix[ROW] = { 0 };
		for (int i = 0; i < ROW; i++)
		{
			if (*start)
				matrix[i] = *start - 'A';
			else
				matrix[i] = 0;
			start++;
		}
		len -= ROW;
		int cry[ROW] = { 0 };
		for (int i = 0; i < ROW; i++)
		{
			int temp = 0;
			for (int j = 0; j < COV; j++)
			{
				temp = matrix[j] * obkeys[j][i] + temp;
			}
			cry[i] = temp % 26;
			*words = 'A' + cry[i];//计算明文
			words++;
		}
	}
}

//求逆矩阵函数
void ObMatrix(float a[ROW][COV], float b[ROW][COV], int n)
{
	int i, j;//定义矩阵的行列式
	if (Gauss(a, b, n))
	{
		cout << "该方阵的逆矩阵为:\n";
		for (i = 0; i < n; i++)
		{
			cout << setw(4);
			for (j = 0; j < n; j++)
			{
				int temp = b[i][j] / 1;
				float num = b[i][j] - temp;
				if (fabs(num) < 0.50)
					b[i][j] = (int)temp;
				else
					b[i][j] = temp + (int)(num * 2);
				cout << b[i][j] << setw(10);
			}
			cout << endl;
		}
	}
	cout << "逆矩阵（mod26）:" << endl;
	for (int i = 0; i < ROW; i++)
	{
		cout << setw(4);
		for (int j = 0; j < COV; j++)
		{
			if (b[i][j] >= 0)
			{
				b[i][j] = (int)b[i][j] % 26;
			}
			else
			{
				b[i][j] = 26 + (int)b[i][j] % 26;
			}
			cout << b[i][j] << setw(6);
		}
		cout << endl;
	}

}

//高斯消去法函数
bool Gauss(float A[ROW][COV], float B[ROW][COV], int n)
{
	int i, j, k;
	float max, temp;
	float t[ROW][COV];//临时矩阵
	//将A矩阵存放在临时矩阵t[n][n]中
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			t[i][j] = A[i][j];
		}
	}
	//初始化B矩阵为单位阵
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			B[i][j] = (i == j) ? (int)1 : 0;
		}
	}
	for (i = 0; i < n; i++)
	{
		//寻找主元
		max = t[i][i];
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (fabs(t[j][i]) > fabs(max))
			{
				max = t[j][i];
				k = j;
			}
		}
		//如果主元所在行不是第i行，进行行交换
		if (k != i)
		{
			for (j = 0; j < n; j++)
			{
				temp = t[i][j];
				t[i][j] = t[k][j];
				t[k][j] = temp;
				//B伴随交换
				temp = B[i][j];
				B[i][j] = B[k][j];
				B[k][j] = temp;
			}
		}
		//判断主元是否为0,?若是,?则矩阵A不是满秩矩阵,不存在逆矩阵
		if (t[i][i] == 0)
		{
			cout << "There is no inverse matrix!";
			return false;
		}
		//消去A的第i列除去i行以外的各行元素
		temp = t[i][i];
		for (j = 0; j < n; j++)
		{
			t[i][j] = t[i][j] / temp;//主对角线上的元素变为1
			B[i][j] = B[i][j] / temp;//伴随计算
		}
		for (j = 0; j < n; j++)//第0行->第n行
		{
			if (j != i)//不是第i行
			{
				temp = t[j][i];
				for (k = 0; k < n; k++)
				{
					t[j][k] = t[j][k] - t[i][k] * temp;
					B[j][k] = B[j][k] - B[i][k] * temp;
				}
			}
		}
	}
	return true;
}


int main()
{
	menu();
	return 0;
}
