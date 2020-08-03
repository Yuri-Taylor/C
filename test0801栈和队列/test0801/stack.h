#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
//静态栈
//typedef int STDataType; 
//#define N 10 
//typedef struct Stack 
//{
//	STDataType _a[N];  
//	int _top; // 栈顶
//}Stack;

// 支持动态增长的栈
typedef char STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;       // 栈顶  
	int _capacity;  // 容量 
}Stack;

void StackInit(Stack* ps)//初始化
{
	ps->_a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}

void StackDestory(Stack* ps)//销毁
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}

void StackPush(Stack* ps, STDataType data)//入栈
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		size_t newcapicity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_a = (STDataType*)realloc(ps->_a, newcapicity * sizeof(STDataType));
		ps->_capacity = newcapicity;
	}

	ps->_a[ps->_top] = data;
	ps->_top++;
}

void StackPop(Stack* ps)//出栈
{
	assert(ps && ps->_top > 0);
	--ps->_top;
}

STDataType StackTop(Stack* ps)//找栈顶
{
	assert(ps);
	return ps->_a[ps->_top - 1];
}

int StackEmpty(Stack* ps)//判断栈是否为空，如果为空返回1，如果不为空返回0
{
	assert(ps);
	return ps->_top == 0 ? 1 : 0;
}

int StackSize(Stack* ps)//获取栈中有效元素的个数
{
	assert(ps);
	return ps->_top;
}

void TestStack()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	StackPush(&st, 6);
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
		printf("%d ", StackTop(&st));

	}
	StackDestory(&st);
}


//括号匹配
////方法一，局限性
//bool isValid(char* s)
//{
//	Stack st;
//	StackInit(&st);
//	while (*s)
//	{
//		if (*s == '{' || *s == '(' || *s == '[')
//		{
//			StackPush(&st, *s);
//		}
//		else if(*s == '}')
//		{
//			if (StackEmpty(&st))
//			{
//				return false;
//			}
//			char top = StackTop(&st);
//			StackPop(&st);
//			if (top != '}')
//			{
//				return false;
//			}
//		}
//		else if (*s == ')')
//		{
//			if (StackEmpty(&st))
//			{
//				return false;
//			}
//			char top = StackTop(&st);
//			StackPop(&st);
//			if (top != ')')
//			{
//				return false;
//			}
//		}
//		else if (*s == ']')
//		{
//			if (StackEmpty(&st))
//			{
//				return false;
//			}
//			char top = StackTop(&st);
//			StackPop(&st);
//			if (top != ']')
//			{
//				return false;
//			}
//		}
//		++s;
//	}
//	bool ret = StackEmpty(&st);
//	StackEmpty(&st);
//	return ret;
//}
//////方法二
//bool isValid(char* s)
//{
//	Stack st;
//	StackInit(&st);
//	char* symbols[3] = { "[]","{}","()" };//指针数组
//	while (*s)
//	{
//		if (*s == '{' || *s == '(' || *s == '[')
//		{
//			StackPush(&st, *s);
//		}
//		else
//		{
//			if (StackEmpty(&st))
//				return false;
//			char top = StackTop(&st);
//			for (int i = 0; i < 3; i++)
//			{
//				if (*s == symbols[i][1] && top != symbols[i][0])
//				{
//					return false;
//				}
//			}
//		}
//		++s;
//	}
//	bool ret = StackEmpty(&st);
//	StackEmpty(&st);
//	return ret;
//}



