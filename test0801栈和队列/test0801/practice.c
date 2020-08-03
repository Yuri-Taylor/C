//设计循环队列
#include"queue.h"
typedef struct
{
	int* _array;
	int _size;//大小
	int front;//队头
	int back;//队尾
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
//插入
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
int myCircularQueueFront(MyCircularQueue* obj)//找队头
{
	if(myCircularQueueIsEmpty(obj))
		return -1;
	return obj->_array[obj->front];
}
int myCircularQueueRear(MyCircularQueue* obj)//找队尾
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