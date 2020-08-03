#include"stack.h"

typedef struct
{
	Stack pushst;
	Stack popst;
}MyQueue;
MyQueue* myQueueCreate()
{
	MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&q->popst);
	StackInit(&q->pushst);
	return q;
}
void myQueuePush(MyQueue* obj, int x)
{
	StackPush(&obj->pushst, x);
}
int myQueuePop(MyQueue* obj)
{
	if (StackEmpty(&obj->popst))
	{
		while (!StackEmpty(&obj->pushst))
		{
			StackPush(&obj->popst, StackTop(&obj->pushst));
			StackPop(&obj->pushst);
		}
	}
	int front = StackTop(&obj->popst);
	StackPop(&obj->popst);
	return front;
}
int myQueuePeek(MyQueue* obj)//取队头数据
{
	if (StackEmpty(&obj->popst))
	{
		while (!StackEmpty(&obj->pushst))
		{
			StackPush(&obj->popst, StackTop(&obj->pushst));
			StackPop(&obj->pushst);
		}
	}
	return StackTop(&obj->popst);
}
bool myQueueEmpty(MyQueue* obj)
{
	return StackEmpty(&obj->popst) && StackEmpty(&obj->pushst);
}
void myQueueFree(MyQueue* obj)
{
	StackDestory(&obj->popst);
	StackDestory(&obj->pushst);
	free(obj);
}