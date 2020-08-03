//���ѭ������
#include"queue.h"
typedef struct
{
	int* _array;
	int _size;//��С
	int front;//��ͷ
	int back;//��β
}MyCircularQueue;

MyCircularQueue* muyCircularQueueCreate(int k)
{
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->_array = (int*)malloc(sizeof(int)*(k+1));
	cq->_size = k+1;
	cq->front = cq->back = 0;
	cq->back = 0;
	cq->front = 0;
	return cq;
}
//����
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	if (myCircularQueueIsFull(obj))
	{
		return false;
	}
	obj->_array[obj->back] = value;
	obj->back++;
	if (obj->back == obj->_size)
	{
		obj->back = 0;
	}
	return true;
}
bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return false;
	obj->front++;
	if (obj->front == obj->_size)
		obj->front = 0;
	return true;
}
int myCircularQueueFront(MyCircularQueue* obj)//�Ҷ�ͷ
{
	if(myCircularQueueIsEmpty(obj))
		return -1;
	return obj->_array[obj->front];
}
int myCircularQueueRear(MyCircularQueue* obj)//�Ҷ�β
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	int prevBack = obj->back - 1;
	if (obj->back == 0)
		prevBack = obj->_size - 1;
	return obj->_array[prevBack];
}
bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	return obj->front == obj->back;
}
bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	if (obj->back + 1 == obj->front)
		return true;
	if ((obj->back + 1) % (obj->_size) == obj->front)
		return true;
	return false;
}
void myCircularQueueFree(MyCircularQueue* obj)
{
	free(obj->_array);
	free(obj);
}