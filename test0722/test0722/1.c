#define _CRT_SECURE_NO_WARNINGS 1
//

//#include <stdio.h>
//int main() 
//{
//	int *ptr = malloc(100); 
//	if (ptr != NULL)
//	{     
//		//业务处理
//	}    
//	else    
//	{ 
//		exit(EXIT_FAILURE);
//	}    
//	//扩展容量   
//	int*p = NULL; 
//	p = realloc(ptr, 1000); 
//	if(p != NULL)   
//	{    
//		ptr = p;  
//	}   
//	//业务处理    
//	free(ptr);   
//	return 0;
//} 


//void test() 
//{
//	int *p = (int *)malloc(INT_MAX / 4);  
//	*p = 20;//如果p的值是NULL，就会有问题  
//	free(p);
//}
//
//
//void test() 
//{
//	int i = 0;  
//	int *p = (int *)malloc(10 * sizeof(int)); 
//	if (NULL == p) 
//	{ 
//		exit(EXIT_FAILURE);
//	}   
//	for (i = 0; i <= 10; i++) 
//	{
//		*(p + i) = i;//当i是10的时候越界访问  
//	}  
//	free(p); 
//}
//
//
//void test()
//{
//	int a = 10;
//	int *p = &a;
//	free(p);//不可以
//}
//
//
//
//void test()
//{
//	int *p = (int *)malloc(100);
//	p++;
//	free(p);//p不再指向动态内存的起始位置 
//}
//
//
//void test()
//{
//	int *p = (int *)malloc(100); 
//	free(p);  
//	free(p);//重复释放
//}
//
//
//void test() 
//{ 
//	int *p = (int *)malloc(100); 
//	if (NULL != p) 
//	{ *p = 20; } 
//}
//
//int main() 
//{ 
//	test();  
//	while (1);
//}

#include<stdio.h>
//void GetMemory(char *p) 
//{
//	p = (char *)malloc(100); 
//} 
//void Test(void)
//{
//	char *str = NULL;  
//	GetMemory(str); 
//	strcpy(str, "hello world"); 
//	printf(str);
//}

//char *GetMemory(void) 
//{ 
//	char p[] = "hello world";   
//	return p;
//}
//void Test(void)
//{ 
//	char *str = NULL;    
//	str = GetMemory();   
//	printf(str); 
//}
//
//
//void GetMemory(char **p, int num) 
//{
//	*p = (char *)malloc(num);
//} 
//void Test(void) 
//{
//	char *str = NULL;
//	GetMemory(&str, 100); 
//	strcpy(str, "hello");   
//	printf(str);
//}
//
//
//
//
//
//void Test(void)
//{
//	char *str = (char *)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
////}
//
//int main()
//{
//	Test();
//	return 0;
//}



int OutNum = 1;
static int taticOutNum = 1;
void Test()
{
	static int staticNum = 1;
	int num = 1;
	int arr1[20] = { 1,2,3,4 };
	char arr2[] = "abcd";
	char *pArr3 = "abcd";
	int *p1 = (int*)malloc(sizeof(int) * 4);
	int *p2 = (int*)calloc(4, sizeof(int));
	int *p3 = (int*)realloc(p2, sizeof(int) * 4);
	free(p1);
	free(p2);
}












