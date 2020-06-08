//#include<stdio.h>

//int check_sys()
//{
//	int a = 1;
//	return *(char *)&a;
//	//大端返回0，小端返回1
//}
//
//int main()
//{
//	int ret = check_sys();
//	if (ret == 1)
//		printf("小端\n");
//	else
//		printf("大端\n");
//	return 0;
//}

//union Un
//{
//	int i;
//	char c;
//};
//i 和 c共用了一个字节
//int main()
//{
//	printf("%d\n", sizeof(union Un));//输出4
//	union Un un;
//	printf("%p\n", &(un.c));//00BFF828
//	printf("%p\n", &(un.i));//00BFF828
//	return 0;
//}

//int check_sys()
//{
//	union Un
//	{
//		int i;
//		char c;
//	}un;
//	un.i = 1;
//	return un.c;
//}
//
//int main()
//{
//	int ret = check_sys();
//	if (ret == 1)
//		printf("小端\n");
//	else
//		printf("大端\n");
//	return 0;
//}

//#include <stdio.h> 
//int main() 
//{   
//	char a= -1;    
//	signed char b=-1;    
//	unsigned char c=-1;    
//	printf("a=%d,b=%d,c=%d",a,b,c);   //-1 -1 255 
//	return 0; 
//}


//#include <stdio.h> 
//int main() 
//{    
//	char a = -128;    
//	printf("%u\n",a);    //4294967168
//	return 0; 
//}
//10000000 00000000 00000000 10000000 char原码
//11111111 11111111 11111111 01111111 char反码
//11111111 11111111 11111111 10000000 char补码
//11111111 11111111 11111111 10000000 %u的a的补码
//11111111 11111111 11111111 10000000 %u的a的原码


#include <stdio.h> 
int main() 
{    
	int i = -20; 
	unsigned  int  j = 10; 
	printf("%d\n", i + j);//-10
	return 0;
}
//10000000 00000000 00000000 00010100  i
//11111111 11111111 11111111 11101100  i补码
//00000000 00000000 00000000 00001010  j
//11111111 11111111 11111111 11110110 i+j的补码（有符号）
//10000000 00000000 00000000 00001010 i+j的原码

