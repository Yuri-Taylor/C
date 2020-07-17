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

#include <stdio.h> 
int add(int a, int b) 
{  
	return a + b;
} 
int sub(int a, int b) 
{ 
	return a - b; 
} 
int mul(int a, int b)
{  
	return a*b;
} 
int div(int a, int b) 
{ 
	return a / b;
} 
int main() 
{
	int x, y;
	int input = 1;    
	int ret = 0;    
	while (input)
	{ 
		printf("*************************\n");
		printf("  1:add           2:sub  \n");
		printf("  3:mul           4:div  \n");
		printf("*************************\n");         
		printf("请选择：");         
		scanf("%d", &input);         
		switch (input) 
		{ 
		case 1:               
			printf("输入操作数：");               
			scanf("%d %d", &x, &y);               
			ret = add(x, y);              
			break;         
		case 2:               
			printf("输入操作数：");               
			scanf("%d %d", &x, &y);               
			ret = sub(x, y);               
			break;         
		case 3:               
			printf("输入操作数：");              
			scanf("%d %d", &x, &y);               
			ret = mul(x, y);               
			break;         
		case 4:               
			printf("输入操作数：");               
			scanf("%d %d", &x, &y);               
			ret = div(x, y);               
			break;         
		default:               
			printf("选择错误\n");               
			break;
		}         
		printf("ret = %d\n", ret);
	}     
	return 0;
}