//#include<stdio.h>

//int check_sys()
//{
//	int a = 1;
//	return *(char *)&a;
//	//��˷���0��С�˷���1
//}
//
//int main()
//{
//	int ret = check_sys();
//	if (ret == 1)
//		printf("С��\n");
//	else
//		printf("���\n");
//	return 0;
//}

//union Un
//{
//	int i;
//	char c;
//};
//i �� c������һ���ֽ�
//int main()
//{
//	printf("%d\n", sizeof(union Un));//���4
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
//		printf("С��\n");
//	else
//		printf("���\n");
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
//10000000 00000000 00000000 10000000 charԭ��
//11111111 11111111 11111111 01111111 char����
//11111111 11111111 11111111 10000000 char����
//11111111 11111111 11111111 10000000 %u��a�Ĳ���
//11111111 11111111 11111111 10000000 %u��a��ԭ��


#include <stdio.h> 
int main() 
{    
	int i = -20; 
	unsigned  int  j = 10; 
	printf("%d\n", i + j);//-10
	return 0;
}
//10000000 00000000 00000000 00010100  i
//11111111 11111111 11111111 11101100  i����
//00000000 00000000 00000000 00001010  j
//11111111 11111111 11111111 11110110 i+j�Ĳ��루�з��ţ�
//10000000 00000000 00000000 00001010 i+j��ԭ��

