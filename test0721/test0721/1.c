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
//}p1;    //声明类型的同时定义变量p1 
//
//struct Point p2;    //定义结构体变量p2
//
////初始化：定义变量的同时赋初值。 
//struct Point p3 = {5, 1};
//
//struct Stu //类型声明 
//{    
//	char name[15];//名字    
//	int age;    //年龄 
//}; 
//struct Stu s = {"zhangsan", 20};//初始化
//
//struct Node 
//{ 
//	int data;  
//	struct Point p; 
//	struct Node* next;
//}n1 = { 10, {4,5}, NULL }; //结构体嵌套初始化 
//
//struct Node n2 = { 20, {5, 6}, NULL };//结构体嵌套初始化

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
//#pragma pack(8)//设置默认对齐数为8 
//struct S1 
//{    
//	char c1;
//	int i;
//	char c2;
//}; 
//#pragma pack()//取消设置的默认对齐数，还原为默认
//
//#pragma pack(1)//设置默认对齐数为1 
//struct S2 
//{   
//	char c1;  
//	int i;   
//	char c2;
//}; 
//#pragma pack()//取消设置的默认对齐数，还原为默认 
//int main()
//{
//	//输出的结果是什么？ ? ?
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
//}A;    //定义一个结构体
//int main()
//{
//	A p;  //定义结构体变量
//	printf("%d", offsetof(p, p.c));  //结构体起始地址相当于c变量的偏移量为8
//	return 0;
//}

//#include<stdio.h>
//struct S{
//	int data[1000];  
//	int num; 
//};
//
//struct S s = { {1,2,3,4}, 1000 }; //结构体传参 
//void print1(struct S s) 
//{   
//	printf("%d\n", s.num); 
//} 
////结构体地址传参 
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
//struct A //位段类型
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


//enum Color//颜色 
//{    
//	RED=1,
//	GREEN=2, 
//	BLUE=4 
//};
//int main()
//{
//	enum Color clr = GREEN;//只能拿枚举常量给枚举变量赋值，才不会出现类型的差异。
//	clr = 5;
//	return 0;
//}

#include<stdio.h>
//联合类型的声明 
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

