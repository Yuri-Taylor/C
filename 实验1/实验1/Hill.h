
#include<iostream>
using namespace std;
#include<assert.h>
#include<iomanip>

#define ROW 2//密钥行数
#define COV 2//密钥列数

void InputKeys(float keys[ROW][COV]);//输入密钥
void InputWords(char *words);//输入明文
void InputObwords(char *words);//输入密文
void PopKeys(float keys[ROW][COV]);//输出密钥
void Encryption(float keys[ROW][COV], char *words, char *crypto);//明文加密
void Decode(float keys[ROW][COV], char *words, char *crypto);//密文解密
bool Gauss(float A[ROW][COV], float B[ROW][COV], int n);//高斯消去法求逆矩阵
void ObMatrix(float a[ROW][COV], float b[ROW][COV], int n);//求密钥逆矩阵
void menu();//菜单

