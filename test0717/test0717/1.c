#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	char str1[] = "hello bit.";
//	char str2[] = "hello bit.";
//	char *str3 = "hello bit."; 
//	char *str4 = "hello bit.";
//	if (str1 == str2)       
//		printf("str1 and str2 are same\n");
//	else
//		printf("str1 and str2 are not same\n");
//	if (str3 == str4)
//		printf("str3 and str4 are same\n");
//	else
//		printf("str3 and str4 are not same\n");
//	return 0;
//}

//
//#include <stdio.h> 
//int main()
//{
//	int arr[10] = { 0 };
//	printf("%p\n", arr);
//	printf("%p\n", &arr);
//	printf("arr+1 = %p\n", arr + 1);
//	printf("&arr+1= %p\n", &arr + 1);
//	return 0;
//}

//#include <stdio.h> 
//int main() 
//{     
//	int arr[10] = {1,2,3,4,5,6,7,8,9,0};     
//	int (*p)[10] = &arr;//把数组arr的地址赋值给数组指针变量p     
//	return 0; 
//}


//#include <stdio.h> 
//void print_arr1(int arr[3][5], int row, int col) 
//{    
//	int i = 0;   
//	int j = 0;
//	for(i=0; i<row; i++)   
//	{       
//		for(j=0; j<col; j++) 
//		{         
//			printf("%d ", arr[i][j]);  
//		}       
//		printf("\n");    
//	} 
//} 
//
//void print_arr2(int(*arr)[5], int row, int col)
//{ 
//	int i = 0;   
//	int j = 0;
//	for (i = 0; i < row; i++) 
//	{
//		for (j = 0; j < col; j++)
//		{ 
//			printf("%d ", arr[i][j]);
//		}  
//		printf("\n");
//	}
//}
//
//int main() 
//{
//	int arr[3][5] = { 1,2,3,4,5,6,7,8,9,10 };     
//	print_arr1(arr, 3, 5);   
//	printf("\n\n");
//	//数组名arr，表示首元素的地址     
//	//但是二维数组的首元素是二维数组的第一行  
//	//所以这里传递的arr，其实相当于第一行的地址，是一维数组的地址   
//	//可以数组指针来接收   
//	print_arr2(arr, 3, 5);   
//	return 0;
//}



//#include <stdio.h> 
//void test(int arr[])//ok? 
//{} 
////void test(int arr[10])//ok?
////{}
////void test(int *arr)//ok? 
////{}
//void test2(int *arr[20])//ok?
//{}
////void test2(int **arr)//ok? 
////{}
//int main() 
//{ 
//	int arr[10] = {0}; 
//	int *arr2[20] = {0}; 
//	test(arr);
//	test2(arr2); 
//} 

//#include<stdio.h>
//void test(int arr[3][5])//ok？ 
//{} 
////void test(int arr[][])//ok？
////{} 
////void test(int arr[][5])//ok？ 
////{}
////二维数组传参，函数形参的设计只能省略第一个[]的数字。因为对一个二维数组，可以不知道有多少行，但是必须知道一行多少元素。 
//
////void test(int *arr)//ok？
////{}
////void test(int* arr[5])//ok？
////{}
////void test(int (*arr)[5])//ok？
////{}
////void test(int **arr)//ok？
////{} 
//int main() 
//{
//	int arr[3][5] = {0}; 
//	test(arr);
//} 





//#include <stdio.h> 
//void print(int *p, int sz) 
//{ 
//	int i = 0;  
//	for(i=0; i<sz; i++)
//	{  
//		printf("%d\n", *(p+i));
//	} 
//} 
//int main() 
//{  
//	int arr[10] = {1,2,3,4,5,6,7,8,9};  
//	int *p = arr; 
//	int sz = sizeof(arr)/sizeof(arr[0]); 
//	//一级指针p，传给函数  
//	print(p, sz); 
//	return 0;
//}



//#include <stdio.h>
//void test(int** ptr)
//{ 
//	printf("num = %d\n", **ptr);
//} 
//int main() 
//{ 
//	int n = 10;
//	int*p = &n;
//	int **pp = &p;
//	test(pp); 
//	test(&p); 
//	return 0;
//}

//
//#include <stdio.h> 
//void test()
//{
//	printf("hehe\n");
//}
//int main()
//{
//	printf("%p\n", test); 
//	printf("%p\n", &test);  
//	return 0;
//}

//#include <stdio.h> 
//int add(int a, int b) 
//{  
//	return a + b;
//} 
//int sub(int a, int b) 
//{ 
//	return a - b; 
//} 
//int mul(int a, int b)
//{  
//	return a*b;
//} 
//int div(int a, int b) 
//{ 
//	return a / b;
//} 
//int main() 
//{
//	int x, y;
//	int input = 1;    
//	int ret = 0;    
//	while (input)
//	{ 
//		printf("*************************\n");
//		printf("  1:add           2:sub  \n");
//		printf("  3:mul           4:div  \n");
//		printf("*************************\n");         
//		printf("请选择：");         
//		scanf("%d", &input);         
//		switch (input) 
//		{ 
//		case 1:               
//			printf("输入操作数：");               
//			scanf("%d %d", &x, &y);               
//			ret = add(x, y);              
//			break;         
//		case 2:               
//			printf("输入操作数：");               
//			scanf("%d %d", &x, &y);               
//			ret = sub(x, y);               
//			break;         
//		case 3:               
//			printf("输入操作数：");              
//			scanf("%d %d", &x, &y);               
//			ret = mul(x, y);               
//			break;         
//		case 4:               
//			printf("输入操作数：");               
//			scanf("%d %d", &x, &y);               
//			ret = div(x, y);               
//			break;         
//		default:               
//			printf("选择错误\n");               
//			break;
//		}         
//		printf("ret = %d\n", ret);
//	}     
//	return 0;
//}



//#include <stdio.h> 
//int add(int a, int b) 
//{  
//	return a + b;
//} 
//int sub(int a, int b) 
//{ 
//	return a - b; 
//} 
//int mul(int a, int b)
//{  
//	return a*b;
//} 
//int div(int a, int b) 
//{ 
//	return a / b;
//} 
//int main() 
//{
//	int x, y;   
//	int input = 1;   
//	int ret = 0;   
//	int(*p[5])(int x, int y) = { 0, add, sub, mul, div }; //转移表   
//	while (input)  
//	{     
//		printf( "*************************\n" );  
//		printf( "  1:add           2:sub  \n" );    
//		printf( "  3:mul           4:div  \n" );    
//		printf( "*************************\n" );     
//		printf( "请选择：" );     
//		scanf( "%d", &input);     
//		if ((input <= 4 && input >= 1))  
//		{        
//			printf( "输入操作数：" );      
//			scanf( "%d %d", &x, &y);          
//			ret = (*p[input])(x, y);        
//		}       
//		else       
//			printf( "输入有误\n" );   
//		printf( "ret = %d\n", ret);  
//	}   
//	return 0;
//}


//void test(const char* str) 
//{
//	printf("%s\n", str); 
//}
//int main() 
//{  
//	//函数指针pfun  
//	void (*pfun)(const char*) = test; 
//	//函数指针的数组pfunArr
//	void(*pfunArr[5])(const char* str);  
//	pfunArr[0] = test;  
//	//指向函数指针数组pfunArr的指针ppfunArr  
//	void (*(*ppfunArr)[10])(const char*) = &pfunArr; 
//	return 0; 
//}


//#include <stdio.h> 
//int int_cmp(const void * p1, const void * p2) 
//{   
//	return (*( int *)p1 > *(int *) p2); 
//} 
//
//int main() 
//{
//	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };  
//	int i = 0;       
//	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);   
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) 
//	{ 
//		printf("%d ", arr[i]);
//	}  
//	printf("\n");  
//	return 0;
//}


//#include <stdio.h> 
//int int_cmp(const void * p1, const void * p2) 
//{   
//	return (*( int *)p1 > *(int *) p2); 
//} 
//
//void _swap(void *p1, void * p2, int size) 
//{
//	int i = 0;  
//	for (i = 0; i < size; i++)
//	{
//		char tmp = *((char *)p1 + i);     
//		*((char *)p1 + i) = *((char *)p2 + i);  
//		*((char *)p2 + i) = tmp;
//	}
//}
//
//void bubble(void *base, int count, int size, int(*cmp)(void *, void *)) 
//{ 
//	int i = 0;   
//	int j = 0;   
//	for (i = 0; i < count - 1; i++)
//	{ 
//		for (j = 0; j < count - i - 1; j++) 
//		{ 
//			if (cmp((char *)base + j * size, (char *)base + (j + 1)*size) > 0)
//			{
//				_swap((char *)base + j * size, (char *)base + (j + 1)*size, size);
//			}
//		}
//	} 
//} 
//int main()
//{
//	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };     
//	int i = 0; 
//	bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof (int), int_cmp);  
//	for (i = 0; i< sizeof(arr) / sizeof(arr[0]); i++)  
//	{     
//		printf( "%d ", arr[i]);    
//	}    
//	printf("\n");  
//	return 0;
//} 



//#include<stdio.h>
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,0};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	int tmp = 0;
//	for (i = 0; i < sz/2; i++)
//	{
//		tmp = arr[i];
//		arr[i] = arr[sz - i - 1];
//		arr[sz - i - 1] = tmp;
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d  ", arr[i]);
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int *p = arr;
//	int *q = arr + sz - 1;
//	int tmp = 0;
//	while (p < q)
//	{
//		tmp = *p;
//		*p = *q;
//		*q = tmp;
//		p++;
//		q--;
//	}
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d  ", arr[i]);
//	}
//	return 0;
//}


int bubble(int arr[], int num)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < num; i++)
	{
		for (j = num - 1; j >= 0; j--)
		{
			if (arr[i] < arr[j])
			{
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

#include<stdio.h>
int main()
{
	int arr[] = { 3,1,6,4,8,9,2,7,0,5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d  ",arr[i]);
	}
	return 0;
}