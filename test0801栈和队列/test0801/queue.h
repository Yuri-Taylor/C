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
void QueueInit(Queue* q)//��ʼ��
{
	assert(q);
	q->_back = q->_front = NULL;
}
void QueuePush(Queue* q, QDataType data)//����
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
void QueuePop(Queue* q)//��ͷ������
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
QDataType QueueFront(Queue* q)//��ȡ��ͷԪ��
{
	assert(q);
	return q->_front->_data;
}
QDataType QueueBack(Queue* q)//��ȡ��βԪ��
{
	assert(q);
	return q->_back->_data;
}
int QueueSize(Queue* q)//��ȡ����Ԫ�ظ���
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
int QueueEmpty(Queue* q)//�ж��Ƿ�Ϊ��
{
	return q->_front == NULL ? 1 : 0;
}
void QueueDestory(Queue* q)//����
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