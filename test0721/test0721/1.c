#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>

//struct Stu
//{
//	char name[20];
//	int age;
//	char sex[5];
//	char id[20];
//};
//
//int main()
//{
//	sizeof(struct Stu);
//	return 0;
//}


//typedef struct
//{
//	int data;
//	struct Node* next;
//}Node;
//
//int main()
//{
//	return 0;
//}

//struct Point 
//{ 
//	int x;   
//	int y; 
//}p1;    //�������͵�ͬʱ�������p1 
//
//struct Point p2;    //����ṹ�����p2
//
////��ʼ�������������ͬʱ����ֵ�� 
//struct Point p3 = {5, 1};
//
//struct Stu //�������� 
//{    
//	char name[15];//����    
//	int age;    //���� 
//}; 
//struct Stu s = {"zhangsan", 20};//��ʼ��
//
//struct Node 
//{ 
//	int data;  
//	struct Point p; 
//	struct Node* next;
//}n1 = { 10, {4,5}, NULL }; //�ṹ��Ƕ�׳�ʼ�� 
//
//struct Node n2 = { 20, {5, 6}, NULL };//�ṹ��Ƕ�׳�ʼ��

//#include<stdio.h>
//#include<string.h>
//
//struct Stu
//{
//	char name[20];
//	int age;
//	char sex[5];
//	char id[20];
//};
//
//int main()
//{
//	struct Stu s;
//	struct Stu *ps = &s;
//	strcpy(s.name,"Yuri");
//	s.age = 20;
//	printf("name is %s   age = %d\n", ps->name, ps->age);
//	return 0;
//}

//#include<stdio.h>
//struct S1 
//{ 
//	char c1;  
//	int i;  
//	char c2; };
//struct S2 
//{   
//	char c1;    
//	char c2;    
//	int i;
//}; 
//struct S3 
//{    
//	double d;  
//	char c;    
//	int i; 
//};
//struct S4 
//{   
//	char c1;  
//	struct S3 s3;  
//	double d; 
//}; 
//int main()
//{
//	printf("%d\n", sizeof(struct S1));//12
//	printf("%d\n", sizeof(struct S2));//8
//	printf("%d\n", sizeof(struct S3));//16
//	printf("%d\n", sizeof(struct S4));//32
//	return 0;
//}


//#include <stdio.h>
//#pragma pack(8)//����Ĭ�϶�����Ϊ8 
//struct S1 
//{    
//	char c1;
//	int i;
//	char c2;
//}; 
//#pragma pack()//ȡ�����õ�Ĭ�϶���������ԭΪĬ��
//
//#pragma pack(1)//����Ĭ�϶�����Ϊ1 
//struct S2 
//{   
//	char c1;  
//	int i;   
//	char c2;
//}; 
//#pragma pack()//ȡ�����õ�Ĭ�϶���������ԭΪĬ�� 
//int main()
//{
//	//����Ľ����ʲô�� ? ?
//	printf("%d\n", sizeof(struct S1));//12
//	printf("%d\n", sizeof(struct S2));//6
//	return 0; 
//}

//#include<stdio.h>
//#define offsetof(a,b) ((char*)(&b)-(char*)(&a))
//typedef struct A {
//	char a;
//	int b;
//	double c;
//}A;    //����һ���ṹ��
//int main()
//{
//	A p;  //����ṹ�����
//	printf("%d", offsetof(p, p.c));  //�ṹ����ʼ��ַ�൱��c������ƫ����Ϊ8
//	return 0;
//}

//#include<stdio.h>
//struct S{
//	int data[1000];  
//	int num; 
//};
//
//struct S s = { {1,2,3,4}, 1000 }; //�ṹ�崫�� 
//void print1(struct S s) 
//{   
//	printf("%d\n", s.num); 
//} 
////�ṹ���ַ���� 
//void print2(struct S* ps)
//{   
//	printf("%d\n", ps->num); 
//}
//int main()
//{
//	print1(s);
//	print2(&s);
//	return 0;
//}

//#include<stdio.h>
//
//struct A //λ������
//{
//	int _a : 2;
//	int _b : 5;
//	int _c : 10;
//	int _d : 30;
//};
//int main()
//{
//	printf("%d\n", sizeof(struct A));//8
//}


//struct S 
//{
//	char a : 3; 
//	char b : 4;  
//	char c : 5;   
//	char d : 4; 
//};
//int main()
//{
//	struct S s = { 0 };
//	s.a = 10;
//	s.b = 12;
//	s.c = 3;
//	s.d = 4;
//	return 0;
//}


//enum Color//��ɫ 
//{    
//	RED=1,
//	GREEN=2, 
//	BLUE=4 
//};
//int main()
//{
//	enum Color clr = GREEN;//ֻ����ö�ٳ�����ö�ٱ�����ֵ���Ų���������͵Ĳ��졣
//	clr = 5;
//	return 0;
//}

#include<stdio.h>
//�������͵����� 
//union Un
//{  
//	char c;  
//	int i;
//};
//int main()
//{
//	union Un un;
//	printf("%d\n", &(un.i));
//	printf("%d\n", &(un.c));
//	un.i = 0x11223344;
//	un.c = 0x55;
//	printf("%x\n", un.i);
//	return 0;
//}
//union Un1 
//{ 
//	char c[5]; 
//	int i;
//}; 
//union Un2
//{
//	short c[7]; 
//	int i; 
//};
//int main()
//{
//	union Un1 un1;
//	union Un2 un2;
//	printf("%d\n", sizeof(un1)); //8
//	printf("%d\n", sizeof(un2)); //16
//	return 0;
//}

