#include"queue.h"

typedef struct
{
	Queue _q1;
	Queue _q2;
}MyStack;

MyStack* myStackCreate()
{
	MyStack* st = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&st->_q1);
	QueueInit(&st->_q2);
	return st;
}
void myStackPush(MyStack* obj, int x)
{
	if (!QueueEmpty(&obj->_q1))
	{
		QueuePush(&obj->_q1, x);
	}
	else
	{
		QueuePush(&obj->_q2, x);
	}
}
int myStackPop(MyStack* obj)
{
	Queue* pemptyQ = &obj->_q1;
	Queue* pnoemptyQ = &obj->_q2;
	if (QueueEmpty(&obj->_q1) != NULL)
	{
		pemptyQ = &obj->_q2;
		pnoemptyQ = &obj->_q1;
	}
	while (QueueSize(pnoemptyQ) > 1)
	{
		QueuePush(pemptyQ, QueueFront(pnoemptyQ));
		QueuePop(pnoemptyQ);
	}
	int top = QueueBack(pnoemptyQ);
	QueuePop(pnoemptyQ);
	return top;
}
int myStackTop(MyStack* obj)
{
	if (QueueEmpty(&obj->_q1) != NULL)
	{
		return QueueBack(&obj->_q1);
	}
	else
	{
		return QueueBack(&obj->_q2);
	}
}
int myStackEmpty(MyStack* obj)
{
	return QueueEmpty(&obj->_q1) && QueueEmpty(&obj->_q2);
}
void myStackFree(MyStack* obj)
{
	QueueDestory(&obj->_q1);
	QueueDestory(&obj->_q2);
	free(obj);
}