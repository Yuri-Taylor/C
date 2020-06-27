#include"Hill.h"

void menu()
{
	float keys[ROW][COV] = { 8,6,9,5, };// ���ܾ���Ĭ����Կ��
	float obkeys[ROW][COV] = { 0 }; //���ܾ���?����Կ�����
	char words[100] = { 0 };
	char crypto[100] = { 0 };
	char obwords[100] = { 0 };
	bool flag = true; //�˵�ѡ��
	bool chose = false; //��Կѡ��
	char cn = 0;
	while (flag)
	{
		int n = 0;
		cout << endl;
		cout << "****************************************************************" << endl;
		cout << "********************* 1.������Կ *******************************" << endl;
		cout << "********************* 2.����     *******************************" << endl;
		cout << "********************* 3.����     *******************************" << endl;
		cout << "********************* 4.�˳�     *******************************" << endl;
		cout << "****************************************************************" << endl;
		cout << "��ѡ��->��";
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "Ĭ����ԿΪ��";
			PopKeys(keys);
			cout << "������Ҫ����������Կ��?y/n" << endl << "��ѡ��->:";
			cin >> cn;
			if ((cn == 'y') || (cn == 'Y'))
			{
				InputKeys(keys); //������Կ
			}
			else if ((cn == 'n') || (cn == 'N'))
			{
				cout << "ʹ��Ĭ����Կ��" << endl;
			}
			else
				cout << "��������������ѡ��" << endl;
			break;
		case 2:
			InputWords(words);
			Encryption(keys, words, crypto);
			cout << "������->��" << crypto << endl;
			break;
		case 3:
			InputObwords(crypto);
			ObMatrix(keys, obkeys, COV);
			Decode(obkeys, obwords, crypto);
			cout << "������->��" << obwords << endl;
			break;
		case 4:
			cout << endl << endl << endl;
			cout << setw(15) << "ллʹ�ã�" << endl;
			flag = false;
			break;
		default:
			cout << "ѡ�����󣬳����˳���" << endl;
			break;
		}
	}
}

//�������ĺ���
void InputWords(char *words)
{
	assert(words);
	cout << "���������ģ�";
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
	cout << "����ɹ���" << endl;
}

//�������ĺ���
void InputObwords(char *words)
{
	assert(words);
	cout << "���������ģ�";
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
	cout << "����ɹ���" << endl;
}

//������Կ����
void InputKeys(float keys[ROW][COV])
{
	cout << "��������Կ��" << endl;
	for (size_t i = 0; i < ROW; i++)
	{
		cout << "�������" << i << "����Կ(" << ROW << "����):";
		for (size_t j = 0; j < COV; j++)
		{
			cin >> keys[i][j];
		}
	}
	cout << "����ɹ�!" << endl;
}

//�����Կ����
void PopKeys(float keys[ROW][COV])
{
	cout << "��ԿΪ��" << endl;
	for (size_t i = 0; i < ROW; i++)
	{
		for (size_t j = 0; j < COV; j++)
		{
			cout << keys[i][j] << "???";
		}
		cout << endl;
	}
}

//���ܺ���
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

//���ܺ���
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
			*words = 'A' + cry[i];//��������
			words++;
		}
	}
}

//���������
void ObMatrix(float a[ROW][COV], float b[ROW][COV], int n)
{
	int i, j;//������������ʽ
	if (Gauss(a, b, n))
	{
		cout << "�÷���������Ϊ:\n";
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
	cout << "�����mod26��:" << endl;
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

//��˹��ȥ������
bool Gauss(float A[ROW][COV], float B[ROW][COV], int n)
{
	int i, j, k;
	float max, temp;
	float t[ROW][COV];//��ʱ����
	//��A����������ʱ����t[n][n]��
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			t[i][j] = A[i][j];
		}
	}
	//��ʼ��B����Ϊ��λ��
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			B[i][j] = (i == j) ? (int)1 : 0;
		}
	}
	for (i = 0; i < n; i++)
	{
		//Ѱ����Ԫ
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
		//�����Ԫ�����в��ǵ�i�У������н���
		if (k != i)
		{
			for (j = 0; j < n; j++)
			{
				temp = t[i][j];
				t[i][j] = t[k][j];
				t[k][j] = temp;
				//B���潻��
				temp = B[i][j];
				B[i][j] = B[k][j];
				B[k][j] = temp;
			}
		}
		//�ж���Ԫ�Ƿ�Ϊ0,?����,?�����A�������Ⱦ���,�����������
		if (t[i][i] == 0)
		{
			cout << "There is no inverse matrix!";
			return false;
		}
		//��ȥA�ĵ�i�г�ȥi������ĸ���Ԫ��
		temp = t[i][i];
		for (j = 0; j < n; j++)
		{
			t[i][j] = t[i][j] / temp;//���Խ����ϵ�Ԫ�ر�Ϊ1
			B[i][j] = B[i][j] / temp;//�������
		}
		for (j = 0; j < n; j++)//��0��->��n��
		{
			if (j != i)//���ǵ�i��
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
