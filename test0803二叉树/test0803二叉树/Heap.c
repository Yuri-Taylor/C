#include"Heap.h"

//typedef int HpDataType;
//
//typedef struct Heap
//{
//	HpDataType* _a;
//	size_t _size;
//	size_t _capapcity;
//}Heap;
//小堆向下调整
void AdjustDown(HpDataType* a, size_t n, int root)
{
	size_t parent = root;
	size_t child = parent * 2 + 1;
	while ( child < n)
	{
		//找出小的孩子
		if (a[child + 1] < a[child])
		{
			++child;
		}
		//如果孩子比父亲小
		if (a[parent] > a[child])
		{		 
			HpDataType tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;

			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}

	}
}
void AdjustUp(HpDataType* a, size_t child)//小堆向上调整
{
	size_t parent = (child - 1) / 2;
	while (child>0)//parent不会小于0，所以用child判断
	{
		if (a[child] < a[parent])
		{
			HpDataType tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapCreate(Heap* hp, HpDataType* a, size_t n)//创建堆
{
	hp->_a = (HpDataType*)malloc(sizeof(HpDataType)*n);
	memcpy(hp->_a, a, sizeof(HpDataType)*n);
	hp->_size = n;
	hp->_capapcity = n;
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
}
//Heap* HeapCreate(HpDataType* a, size_t n)//创建堆
//{
//	Heap* hp = (Heap*)malloc(sizeof(Heap));
//	hp->_a = (HpDataType)malloc(sizeof(HpDataType)*n);
//	memcpy(hp->_a, a, sizeof(HpDataType)*n);
//	hp->_capapcity = n;
//	hp->_size = n;
//	//建堆
//	for (int i = (n - 2) / 2; i >= 0; --i)
//	{
//		AdjustDown(hp->_a, hp->_size, i);
//	}
//	return hp;
//}
void HeapPrint(Heap* hp)
{
	for (size_t i = 0; i < hp->_size; ++i)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}
void HeapDestory(Heap* hp)//销毁
{
	hp->_capapcity = 0;
	hp->_size = 0;
	free(hp->_a);
	hp->_a = NULL;
}
void HeapPush(Heap* hp, HpDataType x)//插入
{
	if (hp->_size == hp->_capapcity)
	{
		size_t newcapacity = hp->_capapcity * 2;
		hp->_a = (HpDataType*)malloc(sizeof(HpDataType)*newcapacity);
		hp->_capapcity = newcapacity;
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	//向上调整，调成堆
	AdjustUp(hp->_a, hp->_size - 1);
}
void HeapPop(Heap* hp)//删除  第一个和最后一个交换，删除后向下调整
{
	HpDataType tmp = hp->_a[0];
	hp->_a[0] = hp->_a[hp->_size - 1];
	hp->_a[hp->_size - 1] = tmp;
	hp->_size--;
	AdjustDown(hp->_a, hp->_size, 0);
}
HpDataType HeapTop(Heap* hp)//取堆顶的数据
{
	return hp->_a[0];
}
int HeapSize(Heap* hp)//堆的数据个数
{
	return hp->_size;
}
int HeapEmpty(Heap* hp)//判空
{
	return hp->_size == 0 ? 1 : 0;
}

void HeapSort(int* a, int n)//对堆排序（升序）
{
	//建小堆
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end>0)
	{
		int tmp = a[end];
		a[end] = a[0];
		a[0] = tmp;
		AdjustDown(a, end, 0);
		--end;
	}
}







void printTopK(int* a, int n, int k)
{
	//建k个数的小堆
	Heap hp;
	HeapCreate(&hp, a, k);
	for (int i = k; i < n; i++)
	{
		//如果数据大于堆顶的数据，替换
		if (HeapTop(&hp) < a[i])
		{
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
	}
	HeapPrint(&hp);
}
void TestTopK()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int)*n);
	srand(time(0));
	for (size_t i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[115] = 1000000 + 5;
	a[2335] = 1000000 + 6;
	a[9999] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;
	printTopK(a, n, 10);
}