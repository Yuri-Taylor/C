
#include<iostream>
using namespace std;
#include<assert.h>
#include<iomanip>

#define ROW 2//��Կ����
#define COV 2//��Կ����

void InputKeys(float keys[ROW][COV]);//������Կ
void InputWords(char *words);//��������
void InputObwords(char *words);//��������
void PopKeys(float keys[ROW][COV]);//�����Կ
void Encryption(float keys[ROW][COV], char *words, char *crypto);//���ļ���
void Decode(float keys[ROW][COV], char *words, char *crypto);//���Ľ���
bool Gauss(float A[ROW][COV], float B[ROW][COV], int n);//��˹��ȥ���������
void ObMatrix(float a[ROW][COV], float b[ROW][COV], int n);//����Կ�����
void menu();//�˵�

