//#include<stdio.h>
//int main()
//{
//	unsigned int i;
//	for (i = 9; i >= 0; i--)
//	{
//		printf("%u\n", i);
//	}
//	return 0;
//}


//int main() 
//{ 
//	char a[1000];     
//	int i;     
//	for (i = 0; i < 1000; i++) 
//	{ 
//		a[i] = -1 - i; 
//	}     
//	printf("%d", strlen(a));     
//	return 0; 
//}

//#include <stdio.h> 
//
//unsigned char i = 0; 
//int main() 
//{ 
//	for (i = 0; i <= 255; i++) 
//	{ 
//		printf("hello world\n"); 
//	}     
//	return 0;
//}

//#include<stdio.h>
//int main() 
//{
//	int n = 9;  
//	float *pFloat = (float *)&n;  
//	printf("n的值为：%d\n", n);  
//	printf("*pFloat的值为：%f\n", *pFloat);
//
//	*pFloat = 9.0;
//	printf("num的值为：%d\n", n); 
//	printf("*pFloat的值为：%f\n", *pFloat);
//	return 0;
//}


//#include <stdio.h> 
//int main() 
//{  
//	int arr[10] = {1,2,3,4,5,6,7,8,9,0};  
//	printf("%p\n", arr);  
//	printf("%p\n", &arr[0]); 
//	return 0; 
//} 


//#include <stdio.h> 

//int main() 
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };     
//	int *p = arr; //指针存放数组首元素的地址    
//	int sz = sizeof(arr)/sizeof(arr[0]); 
//	for(int i=0; i<sz; i++)     
//	{       
//		printf("&arr[%d] = %p   <====> p+%d = %p\n", i, &arr[i], i, p+i);   
//	}   
//	return 0;
//}


//int main() 
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 }; 
//	int *p = arr; //指针存放数组首元素的地址  
//	int sz = sizeof(arr) / sizeof(arr[0]); 
//	int i = 0;  
//	for (i = 0; i<sz; i++)  
//	{  
//		printf("%d ", *(p + i)); 
//	} 
//	return 0; 
//}

//int main()
//{
	////一维数组
	//int a[] = { 1,2,3,4 };
	//printf("%d\n", sizeof(a)); 
	//printf("%d\n", sizeof(a + 0)); 
	//printf("%d\n", sizeof(*a)); 
	//printf("%d\n", sizeof(a + 1));
	//printf("%d\n", sizeof(a[1])); 
	//printf("%d\n", sizeof(&a));
	//printf("%d\n", sizeof(&a + 1)); 
	//printf("%d\n", sizeof(&a[0])); 
	//printf("%d\n", sizeof(&a[0] + 1));

	//// 字符数组 
	//char arr[] = {'a','b','c','d','e','f'}; 
	//printf("%d\n", sizeof(arr)); 
	//printf("%d\n", sizeof(arr+0)); 
	//printf("%d\n", sizeof(*arr)); 
	//printf("%d\n", sizeof(arr[1]));
	//printf("%d\n", sizeof(&arr)); 
	//printf("%d\n", sizeof(&arr+1));
	//printf("%d\n", sizeof(&arr[0]+1));
	//printf("%d\n", strlen(arr));
	//printf("%d\n", strlen(arr + 0));
	////printf("%d\n", strlen(*arr));
	////printf("%d\n", strlen(arr[1]));
	//printf("%d\n", strlen(&arr));
	//printf("%d\n", strlen(&arr + 1)); 
	//printf("%d\n", strlen(&arr[0] + 1));

	//char *p = "abcdef";
	//printf("%d\n", sizeof(p));
	//printf("%d\n", sizeof(p + 1));
	//printf("%d\n", sizeof(*p));
	//printf("%d\n", sizeof(p[0]));
	//printf("%d\n", sizeof(&p));
	//printf("%d\n", sizeof(&p + 1));
	//printf("%d\n", sizeof(&p[0] + 1));
	//printf("%d\n", strlen(p));
	//printf("%d\n", strlen(p + 1));
	////printf("%d\n", strlen(*p)); 
	////printf("%d\n", strlen(p[0]));
	//printf("%d\n", strlen(&p));
	//printf("%d\n", strlen(&p + 1)); 
	//printf("%d\n", strlen(&p[0] + 1));

	// ⼆维数组 
//	int a[3][4] = {0};
//	printf("%d\n", sizeof(a));
//	printf("%d\n", sizeof(a[0][0]));
//	printf("%d\n", sizeof(a[0]));
//	printf("%d\n", sizeof(a[0] + 1)); 
//	printf("%d\n", sizeof(a + 1)); 
//	printf("%d\n", sizeof(&a[0] + 1));
//	printf("%d\n", sizeof(*a)); 
//	printf("%d\n", sizeof(a[3]));
//
//	return 0;
//}












