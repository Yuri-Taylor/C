#include<stdio.h>
#include<assert.h>
#include<malloc.h>

typedef int QDataType;
typedef struct QueueNode
{
	QDataType _data;
	struct QueueNode* _next;
}QueueNode;
typedef struct Queue
{
	struct QueueNode* _front;
	struct QueueNode* _back;
}Queue;
void QueueInit(Queue* q)//初始化
{
	assert(q);
	q->_back = q->_front = NULL;
}
void QueuePush(Queue* q, QDataType data)//插入
{
	assert(q);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->_data = data;
	newnode->_next = NULL;
	if (q->_back == NULL)
	{
		q->_back = q->_front = newnode;
	}
	else {
		q->_back->_next = newnode;
		q->_back = newnode;
	}
}
void QueuePop(Queue* q)//队头出队列
{
	assert(q);
	if (q->_front->_next == NULL)
	{
		free(q->_front);
		q->_back = q->_front = NULL;
	}
	else
	{
		QueueNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
	}
}
QDataType QueueFront(Queue* q)//获取队头元素
{
	assert(q);
	return q->_front->_data;
}
QDataType QueueBack(Queue* q)//获取队尾元素
{
	assert(q);
	return q->_back->_data;
}
int QueueSize(Queue* q)//获取队列元素个数
{
	int n = 0;
	QueueNode* cur = q->_front;
	while (cur)
	{
		n++;
		cur = cur->_next;
	}
	return n;
}
int QueueEmpty(Queue* q)//判断是否为空
{
	return q->_front == NULL ? 1 : 0;
}
void QueueDestory(Queue* q)//销毁
{
	QueueNode* cur = q->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_back = NULL;
}