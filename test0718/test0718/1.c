//#include <stdio.h>
//int Add(int x, int y)
//{   
//	int z = 0;  
//	z = x + y;  
//	return z; 
//} 
//int main() 
//{  
//	int a = 10;  
//	int b = 20;   
//	int ret = Add(a, b);  
//	printf("ret = %d\n", ret); 
//	return 0;
//}

//void fun()
//{ 
//	int tmp = 10;
//	//printf("%p\n",&tmp);
//	//printf("%p\n", &tmp+1);
//	//printf("%d\n",*(&tmp+1));
//	//printf("%p\n", (int*)(*(&tmp + 1)));
//	//printf("%p\n", ((int*)(*(&tmp + 1)))-1);
//	//printf("%d\n", *(((int*)(*(&tmp + 1))) - 1));//出错
//	int *p = (int *)(*(&tmp + 1)); //使用了未初始化的tmp  
//	*(p - 1) = 20;
//}
//int main() 
//{ 
//	int a = 0; 
//	fun(); 
//	printf("a = %d\n", a); 
//	return 0; 
//}

//#include<stdio.h>
//void Print(int n)
//{
//	if (n > 9)
//	{
//		Print(n/10);
//	}
//	printf("%d ",n%10);
//}
//int main()
//{
//	int num = 1234;
//	Print(num);
//	return 0;
//}


//#include <stdio.h>
//int Strlen(const char*str)
//{ 
//	if (*str == '\0')   
//		return 0;
//	else return 1 + Strlen(str + 1);
//} 
//int main() 
//{ 
//	char *p = "abcdef"; 
//	int len = Strlen(p); 
//	printf("%d\n", len);   
//	return 0; 
//}
//#include <stdio.h>
//int factorial(int n) 
//{ 
//	if (n <= 1)    
//		return 1;  
//	else      
//		return n * factorial(n - 1);
//}
//int main()
//{
//	int n = 10;
//	printf("%d\n",factorial(n));
//}

//#include <stdio.h>
//int fib(int n) 
//{ 
//	if (n <= 2)      
//		return 1; 
//	else     
//		return fib(n - 1) + fib(n - 2);
//}
//
//int main()
//{
//	int n = 20;
//	printf("%d\n", fib(20));
//	return 0;
//}

//#include <stdio.h>
//int fib(int n)
//{ 
//	int result;  
//	int pre_result;  
//	int next_older_result;   
//	result = pre_result = 1;    
//	while (n > 2) 
//	{ 
//		n -= 1;     
//		next_older_result = pre_result;   
//		pre_result = result;    
//		result = pre_result + next_older_result;
//	}    
//	return result;
//}
//int main()
//{
//	int n = 500;
//	printf("%d\n", fib(n));//315178285
//	return 0;
//}


//#include <stdio.h>
//int main(int argc, char* argv[], char* envp[]) 
//{    
//	int i = 0;  
//	for(i=0; i<argc; i++)  
//	{     
//		printf("%s\n", argv[i]);  
//	}    
//	return 0; 
//}


//#include <stdio.h>
//int main(int argc, char* argv[], char* envp[])
//{
//	int i = 0;
//	while (envp[i] != NULL)
//	{
//		printf("%s\n", envp[i]);
//		i++;
//	}
//	return 0;
//}


#include <stdio.h> 
#include <stdarg.h>
int average(int n, ...) 
{   
	va_list arg;   
	int i = 0;    
	int sum = 0;   
	va_start(arg, n); 
	for(i=0; i<n; i++)   
	{
		sum += va_arg(arg, int); 
	}    
	return sum / n;  
	va_end(arg);
} 
int main() 
{ 
	int a = 1;   
	int b = 2; 
	int c = 3;  
	int avg1 = average(2, a, c);  
	int avg2 = average(3, a, b, c);
	printf("avg1 = %d\n", avg1);   
	printf("avg2 = %d\n", avg2);   
	return 0;
}









