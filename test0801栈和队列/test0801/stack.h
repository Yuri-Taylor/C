#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
//��̬ջ
//typedef int STDataType; 
//#define N 10 
//typedef struct Stack 
//{
//	STDataType _a[N];  
//	int _top; // ջ��
//}Stack;

// ֧�ֶ�̬������ջ
typedef char STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;       // ջ��  
	int _capacity;  // ���� 
}Stack;

void StackInit(Stack* ps)//��ʼ��
{
	ps->_a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}

void StackDestory(Stack* ps)//����
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}

void StackPush(Stack* ps, STDataType data)//��ջ
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

void StackPop(Stack* ps)//��ջ
{
	assert(ps && ps->_top > 0);
	--ps->_top;
}

STDataType StackTop(Stack* ps)//��ջ��
{
	assert(ps);
	return ps->_a[ps->_top - 1];
}

int StackEmpty(Stack* ps)//�ж�ջ�Ƿ�Ϊ�գ����Ϊ�շ���1�������Ϊ�շ���0
{
	assert(ps);
	return ps->_top == 0 ? 1 : 0;
}

int StackSize(Stack* ps)//��ȡջ����ЧԪ�صĸ���
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


//����ƥ��
////����һ��������
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
//////������
//bool isValid(char* s)
//{
//	Stack st;
//	StackInit(&st);
//	char* symbols[3] = { "[]","{}","()" };//ָ������
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



