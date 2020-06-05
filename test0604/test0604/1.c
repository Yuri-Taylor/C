#include<stdio.h>
/*int main()
{
	int arr[10] = { 0 };
	int i = 0;
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("&arr[%d] = %p\n", i, &arr[i]);
	}
	return 0;
}*/

/*int main()
{
	int arr[10] = { 0 };
	int i = 0;
	int *p = arr;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; i++)
	{
		*(arr + i) = i;
		arr[i] = i;
		*(p + i) = i;
		p[i] = i;
	}
	for (i = 0; i < sz; i++)
		printf("%d  ", arr[i]);
	printf("\n");
	return 0;
}*/

/*int main()
{
	int arr[3][5] = { 0 };
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("$arr[%d][%d] = %p\n", i, j, &arr[i][j]);
		}
	}
	return 0;
}*/

//int main()
//{
//	int arr[3][5] = { 0 };
//	int *p = &arr[0][0];
//	int i = 0;
//	for (i = 0; i < 15; i++)
//	{
//		*(p + i) = i + 1;
//	}
//	for (i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			printf("%d  ", arr[i][j]);
//		}
//	}
//	return 0;
//}


//int main()
//{
//	int num = 10;
//	int *p = &num;
//	char *pc = &num;
//	printf("%p\n", p);
//	printf("%p\n", p + 1);
//
//	printf("%p\n", pc);
//	printf("%p\n", pc + 1);
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//	printf("&arr[0] = %p\n", &arr[0]);
//	printf("&arr[0] + 1 = %p\n", &arr[0]+1);
//	printf("arr = %p\n", arr);
//	printf("arr + 1 = %p\n", arr+1);
//	printf("&arr = %p\n", &arr);
//	printf("&arr + 1 = %p\n", &arr+1);
//	return 0;
//}

int main()
{
	int a[] = { 1,2,3,4 }; 
	printf("%d\n", sizeof(a)); 
	printf("%d\n", sizeof(a + 0)); 
	printf("%d\n", sizeof(*a)); 
	printf("%d\n", sizeof(a + 1)); 
	printf("%d\n", sizeof(a[1])); 
	printf("%d\n", sizeof(&a)); 
	printf("%d\n", sizeof(*&a)); 
	printf("%d\n", sizeof(&a + 1)); 
	printf("%d\n", sizeof(&a[0])); 
	printf("%d\n", sizeof(&a[0] + 1));


	char arr[] = {'a','b','c','d','e','f'}; 
	printf("%d\n", sizeof(arr)); 
	printf("%d\n", sizeof(arr+0)); 
	printf("%d\n", sizeof(*arr)); 
	printf("%d\n", sizeof(arr[1])); 
	printf("%d\n", sizeof(&arr)); 
	printf("%d\n", sizeof(&arr+1)); 
	printf("%d\n", sizeof(&arr[0]+1));
	printf("%d\n", strlen(arr)); 
	printf("%d\n", strlen(arr + 0)); 
	printf("%d\n", strlen(*arr)); 
	printf("%d\n", strlen(arr[1])); 
	printf("%d\n", strlen(&arr)); 
	printf("%d\n", strlen(&arr + 1)); 
	printf("%d\n", strlen(&arr[0] + 1));


	char arr[] = "abcdef"; 
	printf("%d\n", sizeof(arr)); 
	printf("%d\n", sizeof(arr + 0)); 
	printf("%d\n", sizeof(*arr)); 
	printf("%d\n", sizeof(arr[1])); 
	printf("%d\n", sizeof(&arr)); 
	printf("%d\n", sizeof(&arr + 1));
	printf("%d\n", sizeof(&arr[0] + 1));
	printf("%d\n", strlen(arr)); 
	printf("%d\n", strlen(arr + 0)); 
	printf("%d\n", strlen(*arr)); 
	printf("%d\n", strlen(arr[1])); 
	printf("%d\n", strlen(&arr)); 
	printf("%d\n", strlen(&arr + 1)); 
	printf("%d\n", strlen(&arr[0] + 1));


	char *p = "abcdef"; 
	printf("%d\n", sizeof(p)); 
	printf("%d\n", sizeof(p + 1)); 
	printf("%d\n", sizeof(*p)); 
	printf("%d\n", sizeof(p[0])); 
	printf("%d\n", sizeof(&p)); 
	printf("%d\n", sizeof(&p + 1)); 
	printf("%d\n", sizeof(&p[0] + 1));
	printf("%d\n", strlen(p)); 
	printf("%d\n", strlen(p + 1)); 
	printf("%d\n", strlen(*p)); 
	printf("%d\n", strlen(p[0])); 
	printf("%d\n", strlen(&p)); 
	printf("%d\n", strlen(&p + 1)); 
	printf("%d\n", strlen(&p[0] + 1));


	int a[3][4] = {0};
	printf("%d\n", sizeof(a)); 
	printf("%d\n", sizeof(a[0][0])); 
	printf("%d\n", sizeof(a[0])); 
	printf("%d\n", sizeof(a[0] + 1)); 
	printf("%d\n", sizeof(a + 1)); 
	printf("%d\n", sizeof(&a[0] + 1)); 
	printf("%d\n", sizeof(*a)); 
	printf("%d\n", sizeof(a[3]));
	return 0;
}