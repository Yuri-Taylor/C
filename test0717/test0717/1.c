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
//	int (*p)[10] = &arr;//������arr�ĵ�ַ��ֵ������ָ�����p     
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
//	//������arr����ʾ��Ԫ�صĵ�ַ     
//	//���Ƕ�ά�������Ԫ���Ƕ�ά����ĵ�һ��  
//	//�������ﴫ�ݵ�arr����ʵ�൱�ڵ�һ�еĵ�ַ����һά����ĵ�ַ   
//	//��������ָ��������   
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
//void test(int arr[3][5])//ok�� 
//{} 
////void test(int arr[][])//ok��
////{} 
////void test(int arr[][5])//ok�� 
////{}
////��ά���鴫�Σ������βε����ֻ��ʡ�Ե�һ��[]�����֡���Ϊ��һ����ά���飬���Բ�֪���ж����У����Ǳ���֪��һ�ж���Ԫ�ء� 
//
////void test(int *arr)//ok��
////{}
////void test(int* arr[5])//ok��
////{}
////void test(int (*arr)[5])//ok��
////{}
////void test(int **arr)//ok��
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
//	//һ��ָ��p����������  
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
		printf("��ѡ��");         
		scanf("%d", &input);         
		switch (input) 
		{ 
		case 1:               
			printf("�����������");               
			scanf("%d %d", &x, &y);               
			ret = add(x, y);              
			break;         
		case 2:               
			printf("�����������");               
			scanf("%d %d", &x, &y);               
			ret = sub(x, y);               
			break;         
		case 3:               
			printf("�����������");              
			scanf("%d %d", &x, &y);               
			ret = mul(x, y);               
			break;         
		case 4:               
			printf("�����������");               
			scanf("%d %d", &x, &y);               
			ret = div(x, y);               
			break;         
		default:               
			printf("ѡ�����\n");               
			break;
		}         
		printf("ret = %d\n", ret);
	}     
	return 0;
}